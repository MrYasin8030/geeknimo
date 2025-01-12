// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkEmailBundle_H
#define _C_CkEmailBundle_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkEmailBundle CkEmailBundle_Create(void);
void CkEmailBundle_Dispose(HCkEmailBundle handle);
void CkEmailBundle_getDebugLogFilePath(HCkEmailBundle cHandle, HCkString retval);
void CkEmailBundle_putDebugLogFilePath(HCkEmailBundle cHandle, const char *newVal);
const char *CkEmailBundle_debugLogFilePath(HCkEmailBundle cHandle);
void CkEmailBundle_getLastErrorHtml(HCkEmailBundle cHandle, HCkString retval);
const char *CkEmailBundle_lastErrorHtml(HCkEmailBundle cHandle);
void CkEmailBundle_getLastErrorText(HCkEmailBundle cHandle, HCkString retval);
const char *CkEmailBundle_lastErrorText(HCkEmailBundle cHandle);
void CkEmailBundle_getLastErrorXml(HCkEmailBundle cHandle, HCkString retval);
const char *CkEmailBundle_lastErrorXml(HCkEmailBundle cHandle);
int CkEmailBundle_getMessageCount(HCkEmailBundle cHandle);
BOOL CkEmailBundle_getUtf8(HCkEmailBundle cHandle);
void CkEmailBundle_putUtf8(HCkEmailBundle cHandle, BOOL newVal);
BOOL CkEmailBundle_getVerboseLogging(HCkEmailBundle cHandle);
void CkEmailBundle_putVerboseLogging(HCkEmailBundle cHandle, BOOL newVal);
void CkEmailBundle_getVersion(HCkEmailBundle cHandle, HCkString retval);
const char *CkEmailBundle_version(HCkEmailBundle cHandle);
BOOL CkEmailBundle_AddEmail(HCkEmailBundle cHandle, HCkEmail email);
HCkEmail CkEmailBundle_FindByHeader(HCkEmailBundle cHandle, const char *headerFieldName, const char *headerFieldValue);
HCkEmail CkEmailBundle_GetEmail(HCkEmailBundle cHandle, int index);
HCkStringArray CkEmailBundle_GetUidls(HCkEmailBundle cHandle);
BOOL CkEmailBundle_GetXml(HCkEmailBundle cHandle, HCkString outXml);
const char *CkEmailBundle_getXml(HCkEmailBundle cHandle);
BOOL CkEmailBundle_LoadXml(HCkEmailBundle cHandle, const char *filename);
BOOL CkEmailBundle_LoadXmlString(HCkEmailBundle cHandle, const char *xmlStr);
BOOL CkEmailBundle_RemoveEmail(HCkEmailBundle cHandle, HCkEmail email);
BOOL CkEmailBundle_RemoveEmailByIndex(HCkEmailBundle cHandle, int index);
BOOL CkEmailBundle_SaveLastError(HCkEmailBundle cHandle, const char *path);
BOOL CkEmailBundle_SaveXml(HCkEmailBundle cHandle, const char *filename);
void CkEmailBundle_SortByDate(HCkEmailBundle cHandle, BOOL ascending);
void CkEmailBundle_SortByRecipient(HCkEmailBundle cHandle, BOOL ascending);
void CkEmailBundle_SortBySender(HCkEmailBundle cHandle, BOOL ascending);
void CkEmailBundle_SortBySubject(HCkEmailBundle cHandle, BOOL ascending);
#endif
