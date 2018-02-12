// ---------------------------------------------------------------------------
#include <iostream>
#include "visa_C.h"
#include "errorInfo.h"
#ifndef linux
#pragma package(smart_init)
#endif

// ---------------------------------------------------------------------------

/* Conversion error number en chaine de caracteres */
static void errVisaToStr(long errVisa_i, char *msg_o, int maxMsg_i) {
  ERRORINFO_TRY_M

  char desc_l[BUFFER_LENGTH];

  if (viStatusDesc_s != NULL) {
    viStatusDesc_s(0, errVisa_i, desc_l);
    strncpy(msg_o, desc_l, maxMsg_i);
    msg_o[maxMsg_i - 1] = '\0';
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* --------------------Fonctions publiques----------------------- */

/* Ouverture de session visa niveau carte */
void visaDefaultRM_C::OpenDefaultRm(void) {
  ERRORINFO_TRY_M

  LibId = LoadLibrary("visa32.dll");
  if (LibId <= 0)
    throw Exception("La librairie visa32.dll est introuvable !");
  viOpenDefaultRM_s = (PTR_FUNCTION_viOpenDefaultRM)GetProcAddress(LibId, "viOpenDefaultRM");
  viOpen_s = (PTR_FUNCTION_viOpen)GetProcAddress(LibId, "viOpen");
  viClose_s = (PTR_FUNCTION_viClose)GetProcAddress(LibId, "viClose");
  viSetAttribute_s = (PTR_FUNCTION_viSetAttribute)GetProcAddress(LibId, "viSetAttribute");
  viGetAttribute_s = (PTR_FUNCTION_viGetAttribute)GetProcAddress(LibId, "viGetAttribute");
  viFlush_s = (PTR_FUNCTION_viFlush)GetProcAddress(LibId, "viFlush");
  viStatusDesc_s = (PTR_FUNCTION_viStatusDesc)GetProcAddress(LibId, "viStatusDesc");
  viRead_s = (PTR_FUNCTION_viRead)GetProcAddress(LibId, "viRead");
  viWrite_s = (PTR_FUNCTION_viWrite)GetProcAddress(LibId, "viWrite");
  viPrintf_s = (PTR_FUNCTION_viPrintf)GetProcAddress(LibId, "viPrintf");
  viQueryf_s = (PTR_FUNCTION_viQueryf)GetProcAddress(LibId, "viQueryf");
  viScanf_s = (PTR_FUNCTION_viScanf)GetProcAddress(LibId, "viScanf");
  viReadSTB_s = (PTR_FUNCTION_viReadSTB)GetProcAddress(LibId, "viReadSTB");
  viClear_s = (PTR_FUNCTION_viClear)GetProcAddress(LibId, "viClear");
  viEnableEvent_s = (PTR_FUNCTION_viEnableEvent)GetProcAddress(LibId, "viEnableEvent");
  viDisableEvent_s = (PTR_FUNCTION_viDisableEvent)GetProcAddress(LibId, "viDisableEvent");
  viDiscardEvents_s = (PTR_FUNCTION_viDiscardEvents)GetProcAddress(LibId, "viDiscardEvents");
  viWaitOnEvent_s = (PTR_FUNCTION_viWaitOnEvent)GetProcAddress(LibId, "viWaitOnEvent");
  viSetBuf_s = (PTR_FUNCTION_viSetBuf)GetProcAddress(LibId, "viSetBuf");

  errorInfoAddClass(VISA_ERR_VISA_CLASS, errVisaToStr);
  viOpenDefaultRM_s(&sess_m);

  ERRORINFO_CATCH_RETHROW_M
}

/* Destructeur de session visa niveau carte */
void visaDefaultRM_C::CloseDefaultRm(void) {
  ERRORINFO_TRY_M

  viClose_s(sess_m);
  FreeLibrary(LibId);

  ERRORINFO_CATCH_RETHROW_M
}

/* Constructeur de session au niveau instrumant */
visa_C::visa_C() {

  debug_m = false;
  deviceClosed_m = true;
}

/* Destructeur de session au niveau instrumant */
visa_C::~visa_C() {
  ERRORINFO_TRY_M

  if (!deviceClosed_m)
    viClose_s(session_m);

  deviceClosed_m = true;

  ERRORINFO_CATCH_RETHROW_M
}

/* Ouverture de session au niveau instrument */
void visa_C::Open(visaDefaultRM_C *viRM, char *instr_i) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  ret_l = viOpen_s(viRM->sess_m, instr_i, 0, 0, &session_m);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viOpen", "Unable to open visa ressource");
  }
  visaRessource_m = instr_i;
  deviceClosed_m = false;

  ERRORINFO_CATCH_RETHROW_M
}

/* Lecture en binaire */
void visa_C::ReadBinary(char *buf_i, long sizeBuf_i, unsigned long *retCnt_i) {
  ERRORINFO_TRY_M

  int ret_l;

  ret_l = viRead_s(session_m, (ViByte*)buf_i, sizeBuf_i, retCnt_i);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viRead", "Unable to read on visa ressource");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Lecture en ASCII */
void visa_C::ReadAscii(string *data_i) {
  ERRORINFO_TRY_M

  char buf_l[BUFFER_LENGTH];

  unsigned long retCnt_l = 0;

  this->ReadBinary(buf_l, sizeof(buf_l) / sizeof(buf_l[0]), &retCnt_l);
  buf_l[retCnt_l] = '\0';
  *data_i = (string)buf_l;
  if (debug_m) {
    cout << visaRessource_m << "<-" << *data_i << endl;
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Lecture en ASCII avec taille de buffer allouee dynamiquement */
void visa_C::ReadAscii(string *data_i, unsigned int bufferLength_i) {
  ERRORINFO_TRY_M

  char *buf_l;

  buf_l = new char[bufferLength_i];

  unsigned long retCnt_l = 0;

  this->ReadBinary(buf_l, bufferLength_i, &retCnt_l);
  buf_l[retCnt_l] = '\0';
  *data_i = buf_l;
  delete[]buf_l;

  ERRORINFO_CATCH_RETHROW_M
}

/* Ecriture en binaire */
void visa_C::WriteBinary(const char *data_i, int size_i) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  unsigned long retcnt_l = 0;
  char error_l[1024];

  ret_l = viWrite_s(session_m, (unsigned char *)data_i, size_i, &retcnt_l);
  if (ret_l < 0) {
    sprintf(error_l, "viWrite(%s)", data_i);
    throwError(VISA_ERR_VISA_CLASS, ret_l, error_l, "Unable to write to visa ressource");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Ecriture en ASCII sous forme string */
void visa_C::WriteAscii(const string *data_i) {
  ERRORINFO_TRY_M

  this->WriteBinary(data_i->c_str(), data_i->size());

  if (debug_m) {
    cout << visaRessource_m << "->" << *data_i << endl;
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Ecriture en ASCII suivant parametres sous forme char* */
void visa_C::WriteAscii(const char *data_i) {
  ERRORINFO_TRY_M

  this->WriteBinary(data_i, strlen(data_i));

  if (debug_m) {
    cout << visaRessource_m << "->" << data_i << endl;
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Effacement */
void visa_C::Clear() {
  ERRORINFO_TRY_M

  long ret_l = 0;

  ret_l = viClear_s(session_m);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viClear", "Unable to clear visa ressource");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Lecture STB */
long visa_C::ReadSTB() {
  ERRORINFO_TRY_M

  long ret_l = 0;

  unsigned short stat_l = 0;

  ret_l = viReadSTB_s(session_m, &stat_l);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viReadSTB", "Unable to read STB on visa ressource");
  }

  return stat_l;

  ERRORINFO_CATCH_RETHROW_M
}

/* Fermeture session instrument */
void visa_C::Close() {
  ERRORINFO_TRY_M

  long ret_l = 0;

  if (!deviceClosed_m)
    ret_l = viClose_s(session_m);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viClose", "Unable to close visa ressource");
  }

  deviceClosed_m = true;
  ERRORINFO_CATCH_RETHROW_M
}

/* Ecriture des attributs */
void visa_C::SetAttribute(long attr, long attrstate) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  ret_l = viSetAttribute_s(session_m, attr, attrstate);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viSetAttribute", "Unable to set visa ressource attribute");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Lecture des attributs */
void visa_C::GetAttribute(long attr, void _VI_PTR attrstate) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  ret_l = viGetAttribute_s(session_m, attr, attrstate);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viGetAttribute", "Unable to get visa ressource attribute");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Gestion du mask */
void visa_C::Flush(long mask_i) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  ret_l = viFlush_s(session_m, mask_i);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viFlush", "Unable to set visa mask");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Gestion du mask */
void visa_C::SetBuf(long mask_i, long size_i) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  ret_l = viSetBuf_s(session_m, mask_i, size_i);

  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viSetBuf", "Unable to set visa buffer");
  }

  ERRORINFO_CATCH_RETHROW_M
}

/* Attente */
void visa_C::Wait(int Delay_ms_i) {
  ERRORINFO_TRY_M

  viEnableEvent_s(session_m, VI_EVENT_SERVICE_REQ, VI_QUEUE, VI_NULL);
  viWaitOnEvent_s(session_m, VI_EVENT_SERVICE_REQ, Delay_ms_i, VI_NULL, VI_NULL);
  viDisableEvent_s(session_m, VI_EVENT_SERVICE_REQ, VI_QUEUE);
  // ReadSTB();

  ERRORINFO_CATCH_RETHROW_M
}

/* Attente OPC */
void visa_C::OperationComplete(int Timeout_ms_i) {
  ERRORINFO_TRY_M

  long ret_l = 0;

  viEnableEvent_s(session_m, VI_EVENT_SERVICE_REQ, VI_QUEUE, VI_NULL);
  ret_l = viWaitOnEvent_s(session_m, VI_EVENT_SERVICE_REQ, Timeout_ms_i, VI_NULL, VI_NULL);
  viDisableEvent_s(session_m, VI_EVENT_SERVICE_REQ, VI_QUEUE);
  ReadSTB();
  if (ret_l < 0) {
    throwError(VISA_ERR_VISA_CLASS, ret_l, "viOperationComplete", "Time-out occured before visa ressource complete operation");
  }

  ERRORINFO_CATCH_RETHROW_M
}

void visa_C::setDebug(bool debug_i) {
  debug_m = debug_i;
}

void visa_C::SetTimeOutMs(long timeOutMs) {
  ERRORINFO_TRY_M

  this->SetAttribute(VI_ATTR_TMO_VALUE, timeOutMs);

  ERRORINFO_CATCH_RETHROW_M
}

ViStatus visa_C::viSetAttribute(long attr_i, ViAttrState attrstate_i){
  return viSetAttribute_s(session_m, attr_i, attrstate_i);
}

ViStatus visa_C::viGetAttribute(long attr_i, void _VI_PTR attrstate_i){
  return viGetAttribute_s(session_m, attr_i, attrstate_i);
}

ViStatus visa_C::viRead(ViPBuf buf, ViUInt32 cnt, ViPUInt32 retCnt){
  return viRead_s(session_m, buf, cnt, retCnt);
}

ViStatus visa_C::viWrite(ViBuf  buf, ViUInt32 cnt, ViPUInt32 retCnt){
  return viWrite_s(session_m, buf, cnt, retCnt);
}

ViStatus visa_C::viPrintf(ViString writeFmt, void _VI_PTR param){
  return viPrintf_s(session_m, writeFmt, param);
}

ViStatus visa_C::viQueryf(ViString writeFmt, ViString readFmt){
  return viQueryf_s(session_m, writeFmt, readFmt);
}

ViStatus visa_C::viQueryf(ViString writeFmt, ViString readFmt, void _VI_PTR param){
  return viQueryf_s(session_m, writeFmt, readFmt, param);
}

ViStatus visa_C::viQueryf(ViString writeFmt, ViString readFmt, void _VI_PTR param, void _VI_PTR param2){
  return viQueryf_s(session_m, writeFmt, readFmt, param, param2);
}

ViStatus visa_C::viScanf(ViString readFmt, void _VI_PTR param){
  return viScanf_s(session_m, readFmt, param);
}

ViStatus visa_C::viStatusDesc(ViStatus status, ViChar _VI_FAR desc[]){
  return viStatusDesc_s(session_m, status, desc);
}

ViStatus visa_C::viReadSTB(ViPUInt16 status){
  return viReadSTB_s(session_m, status);
}

ViStatus visa_C::viFlush(ViUInt16 mask){
  return viFlush_s(session_m, mask);
}

