/* ----------------------------------------------------------------------
 *
 *                         ALCATEL SPACE INSDUSTRIES
 *
 *                     Service bancs de Tests TOULOUSE
 *
 *  Nom du fichier   : errorInfo.cpp
 *  Date de creation : 18/02/03
 *  DESCRIPTION :
 *
 *
 *--- CVS ----
 *
 *   Revision CVS courante  	: $Revision: 1.5 $
 *   Date de la revision   	: $Date: 2013/05/24 08:56:07 $
 *   Auteur de la revision 	: $Author: THALES ALENIA SPACE $
 *   Nom de la revision    	: $Name:  $
 *   Fichier source CVS    	: $Source: N:/CVSREF/drivers_cpp/src/errorinfo/errorInfo.cpp,v $
 *
 *  Copyright (C) ALCATEL SPACE INDUSTRIES
 *----------------------------------------------------------------------- */
#include <stdarg.h>
#include <stdio.h>
#include <map>

#pragma hdrstop

#include "errorInfo.h"

#pragma package(smart_init)

#define STRING_SIZE 256

static map<string, errorInfoCodeToMsgFct_T>classNameCodeToMsgFct_s;
static string processName_s;
static int initDone_s = 0;

// Convert Errno to string
static void errnoToStr(long errno_i, char *msg_o, int maxMsg_i) {
  strncpy(msg_o, strerror(errno_i), maxMsg_i);
  msg_o[maxMsg_i - 1] = '\0';
}

void errorInfoInit(char * argv0_i) {
  char * slash_l;
  if (argv0_i != NULL) {
    slash_l = strrchr(argv0_i, '/');
    if (slash_l == NULL) {
      processName_s = argv0_i;
    }
    else {
      processName_s = slash_l + 1;
    }
  }
  errorInfoAddClass(ERRORINFO_CLASS_SYS, errnoToStr);
  initDone_s = 1;
}

void throwErrorParam(const char * errClass_i, long errCode_i, const char * fct_i, const char * file_i, long lineNb_i,
const char * errMsgFormat_i, ...) {
  errorInfo_C err_l;
  va_list vaList_l;
  char str_l[STRING_SIZE];
  errorInfoCodeToMsgFct_T codeToMsgFct_l = NULL;

  if (!initDone_s) {
    errorInfoInit(NULL);
  }
  // Error code
  err_l.errCode_m = errCode_i;
  // Error Class
  err_l.errClass_m = errClass_i;
  // Error Stack
  snprintf(str_l, sizeof(str_l), "While executing\n'%s' file '%s' line %ld", fct_i, file_i, lineNb_i);
  err_l.errStack_m += str_l;

  // Error code message
  codeToMsgFct_l = classNameCodeToMsgFct_s[err_l.errClass_m];
  if (codeToMsgFct_l != NULL) {
    codeToMsgFct_l(errCode_i, str_l, sizeof(str_l));
    err_l.errCodeMsg_m = str_l;
  }
  else {
    fprintf(stderr, "Undefined error class '%s' (file %s line %d)\n", err_l.errClass_m.c_str(), file_i, lineNb_i);
  }

  // Error message
  va_start(vaList_l, errMsgFormat_i);
  vsnprintf(str_l, sizeof(str_l), errMsgFormat_i, vaList_l);
  va_end(vaList_l);
  err_l.errMsg_m = str_l;

  // Process name
  err_l.processName_m = processName_s;

  throw err_l;
}

void errorInfoAddClass(string className_i, errorInfoCodeToMsgFct_T codeToMsgFct_i) {
  classNameCodeToMsgFct_s[className_i] = codeToMsgFct_i;
}
