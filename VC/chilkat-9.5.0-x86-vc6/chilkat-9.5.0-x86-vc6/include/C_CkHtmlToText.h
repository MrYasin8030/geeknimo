// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHtmlToText_H
#define _C_CkHtmlToText_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHtmlToText CkHtmlToText_Create(void);
void CkHtmlToText_Dispose(HCkHtmlToText handle);
void CkHtmlToText_getDebugLogFilePath(HCkHtmlToText cHandle, HCkString retval);
void CkHtmlToText_putDebugLogFilePath(HCkHtmlToText cHandle, const char *newVal);
const char *CkHtmlToText_debugLogFilePath(HCkHtmlToText cHandle);
BOOL CkHtmlToText_getDecodeHtmlEntities(HCkHtmlToText cHandle);
void CkHtmlToText_putDecodeHtmlEntities(HCkHtmlToText cHandle, BOOL newVal);
void CkHtmlToText_getLastErrorHtml(HCkHtmlToText cHandle, HCkString retval);
const char *CkHtmlToText_lastErrorHtml(HCkHtmlToText cHandle);
void CkHtmlToText_getLastErrorText(HCkHtmlToText cHandle, HCkString retval);
const char *CkHtmlToText_lastErrorText(HCkHtmlToText cHandle);
void CkHtmlToText_getLastErrorXml(HCkHtmlToText cHandle, HCkString retval);
const char *CkHtmlToText_lastErrorXml(HCkHtmlToText cHandle);
int CkHtmlToText_getRightMargin(HCkHtmlToText cHandle);
void CkHtmlToText_putRightMargin(HCkHtmlToText cHandle, int newVal);
BOOL CkHtmlToText_getSuppressLinks(HCkHtmlToText cHandle);
void CkHtmlToText_putSuppressLinks(HCkHtmlToText cHandle, BOOL newVal);
BOOL CkHtmlToText_getUtf8(HCkHtmlToText cHandle);
void CkHtmlToText_putUtf8(HCkHtmlToText cHandle, BOOL newVal);
BOOL CkHtmlToText_getVerboseLogging(HCkHtmlToText cHandle);
void CkHtmlToText_putVerboseLogging(HCkHtmlToText cHandle, BOOL newVal);
void CkHtmlToText_getVersion(HCkHtmlToText cHandle, HCkString retval);
const char *CkHtmlToText_version(HCkHtmlToText cHandle);
BOOL CkHtmlToText_IsUnlocked(HCkHtmlToText cHandle);
BOOL CkHtmlToText_ReadFileToString(HCkHtmlToText cHandle, const char *filename, const char *srcCharset, HCkString outStr);
const char *CkHtmlToText_readFileToString(HCkHtmlToText cHandle, const char *filename, const char *srcCharset);
BOOL CkHtmlToText_SaveLastError(HCkHtmlToText cHandle, const char *path);
BOOL CkHtmlToText_ToText(HCkHtmlToText cHandle, const char *html, HCkString outStr);
const char *CkHtmlToText_toText(HCkHtmlToText cHandle, const char *html);
BOOL CkHtmlToText_UnlockComponent(HCkHtmlToText cHandle, const char *code);
BOOL CkHtmlToText_WriteStringToFile(HCkHtmlToText cHandle, const char *stringToWrite, const char *filename, const char *outpuCharset);
#endif
