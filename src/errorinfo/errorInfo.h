/*----------------------------------------------------------------------
 *    
 *                         ALCATEL SPACE INSDUSTRIES
 *
 *                     Service bancs de Tests TOULOUSE
 *
 *  Nom du fichier   : errorInfo.h
 *  Date de creation : 18/02/03
 *  DESCRIPTION :
 *
 *
 *--- CVS ----
 * 
 *   Revision CVS courante  	: $Revision: 1.7 $
 *   Date de la revision   	: $Date: 2013/05/24 08:56:08 $
 *   Auteur de la revision 	: $Author: THALES ALENIA SPACE $
 *   Nom de la revision    	: $Name:  $
 *   Fichier source CVS    	: $Source: N:/CVSREF/drivers_cpp/src/errorinfo/errorInfo.h,v $
 *
 *  Copyright (C) ALCATEL SPACE INDUSTRIES
 *-----------------------------------------------------------------------*/
#ifndef errorInfoH
#define errorInfoH

#include <string>
#include <stdio.h>

using namespace std;

#ifndef __FUNCTION__
#define __FUNCTION__ __FUNC__
#endif

#define ERRORINFO_TRY_M \
    try {

#define ERRORINFO_CATCH_PRINT_M \
    } catch (errorInfo_C & err_l) { \
	err_l.print(); \
    }

#define ERRORINFO_CATCH_RETHROW_M \
    } catch (errorInfo_C & err_l) { \
	err_l.errStack_m += "\n'"; \
	err_l.errStack_m += __FUNCTION__; \
	err_l.errStack_m += "'"; \
	throw err_l; \
    }

#ifdef linux
#define throwError(errClass_i, errCode_i, fct_i, format_i, ...) \
                        throwErrorParam(errClass_i, errCode_i, \
					fct_i, \
					__FILE__, __LINE__, \
                                       format_i, ##__VA_ARGS__)
#else
#define throwError(errClass_i, errCode_i, fct_i, format_i) \
                        throwErrorParam(errClass_i, errCode_i, \
					fct_i, \
					__FILE__, __LINE__, \
                                       format_i)
#endif

#define ERRORINFO_CLASS_SYS "SYS"

// Function pointer to convert error code to error message
// long errorCode_i char * str_o, int maxSizeStr_i
typedef void (* errorInfoCodeToMsgFct_T)(long, char *, int);

// Add new class
extern "C" void errorInfoAddClass(string className_i,
		       errorInfoCodeToMsgFct_T codeToMsgFct_i);

// Init
void errorInfoInit(char * argv0_i);

extern "C" void throwErrorParam(const char * errClass_i,
		long errCode_i,
		const char * fct_i,
		const char * file_i,
		long lineNb_i,
		const char * errMsgFormat_i,
		...);

class errorInfo_C {
    public:
	void print() {
	    printf("%s> %s Error %ld : %s : %s\n%s\n",
	       processName_m.c_str(),
	       errClass_m.c_str(),
	       errCode_m,
	       errMsg_m.c_str(),
	       errCodeMsg_m.c_str(),
	       errStack_m.c_str());
	}
    void getStrMsg(string * strMsg_o) {
        char errorCodeStr_l[10];

        sprintf(errorCodeStr_l, "%ld",  errCode_m);
        *strMsg_o = processName_m + "> " +
                    errClass_m + " Error " +
                    errorCodeStr_l + " : " +
                    errMsg_m + " : " +
                    errCodeMsg_m + "\n" +
                    errStack_m + "\n";
    }
	// Error Class
	string errClass_m;
	// Error Stack
	string errStack_m;
	// Error message
	string errMsg_m;
	// Error message linked to error code
	string errCodeMsg_m;
	// Process name
	string processName_m;
	// Error code
	long errCode_m;
};
#endif
