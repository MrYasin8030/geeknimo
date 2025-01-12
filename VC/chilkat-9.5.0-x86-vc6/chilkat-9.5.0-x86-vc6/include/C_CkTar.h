// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkTar_H
#define _C_CkTar_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkTar CkTar_Create(void);
void CkTar_Dispose(HCkTar handle);
void CkTar_getCharset(HCkTar cHandle, HCkString retval);
void CkTar_putCharset(HCkTar cHandle, const char *newVal);
const char *CkTar_charset(HCkTar cHandle);
void CkTar_getDebugLogFilePath(HCkTar cHandle, HCkString retval);
void CkTar_putDebugLogFilePath(HCkTar cHandle, const char *newVal);
const char *CkTar_debugLogFilePath(HCkTar cHandle);
int CkTar_getDirMode(HCkTar cHandle);
void CkTar_putDirMode(HCkTar cHandle, int newVal);
void CkTar_getDirPrefix(HCkTar cHandle, HCkString retval);
void CkTar_putDirPrefix(HCkTar cHandle, const char *newVal);
const char *CkTar_dirPrefix(HCkTar cHandle);
int CkTar_getFileMode(HCkTar cHandle);
void CkTar_putFileMode(HCkTar cHandle, int newVal);
int CkTar_getGroupId(HCkTar cHandle);
void CkTar_putGroupId(HCkTar cHandle, int newVal);
void CkTar_getGroupName(HCkTar cHandle, HCkString retval);
void CkTar_putGroupName(HCkTar cHandle, const char *newVal);
const char *CkTar_groupName(HCkTar cHandle);
int CkTar_getHeartbeatMs(HCkTar cHandle);
void CkTar_putHeartbeatMs(HCkTar cHandle, int newVal);
void CkTar_getLastErrorHtml(HCkTar cHandle, HCkString retval);
const char *CkTar_lastErrorHtml(HCkTar cHandle);
void CkTar_getLastErrorText(HCkTar cHandle, HCkString retval);
const char *CkTar_lastErrorText(HCkTar cHandle);
void CkTar_getLastErrorXml(HCkTar cHandle, HCkString retval);
const char *CkTar_lastErrorXml(HCkTar cHandle);
BOOL CkTar_getNoAbsolutePaths(HCkTar cHandle);
void CkTar_putNoAbsolutePaths(HCkTar cHandle, BOOL newVal);
int CkTar_getNumDirRoots(HCkTar cHandle);
int CkTar_getScriptFileMode(HCkTar cHandle);
void CkTar_putScriptFileMode(HCkTar cHandle, int newVal);
BOOL CkTar_getUntarCaseSensitive(HCkTar cHandle);
void CkTar_putUntarCaseSensitive(HCkTar cHandle, BOOL newVal);
BOOL CkTar_getUntarDebugLog(HCkTar cHandle);
void CkTar_putUntarDebugLog(HCkTar cHandle, BOOL newVal);
BOOL CkTar_getUntarDiscardPaths(HCkTar cHandle);
void CkTar_putUntarDiscardPaths(HCkTar cHandle, BOOL newVal);
void CkTar_getUntarFromDir(HCkTar cHandle, HCkString retval);
void CkTar_putUntarFromDir(HCkTar cHandle, const char *newVal);
const char *CkTar_untarFromDir(HCkTar cHandle);
void CkTar_getUntarMatchPattern(HCkTar cHandle, HCkString retval);
void CkTar_putUntarMatchPattern(HCkTar cHandle, const char *newVal);
const char *CkTar_untarMatchPattern(HCkTar cHandle);
int CkTar_getUntarMaxCount(HCkTar cHandle);
void CkTar_putUntarMaxCount(HCkTar cHandle, int newVal);
int CkTar_getUserId(HCkTar cHandle);
void CkTar_putUserId(HCkTar cHandle, int newVal);
void CkTar_getUserName(HCkTar cHandle, HCkString retval);
void CkTar_putUserName(HCkTar cHandle, const char *newVal);
const char *CkTar_userName(HCkTar cHandle);
BOOL CkTar_getUtf8(HCkTar cHandle);
void CkTar_putUtf8(HCkTar cHandle, BOOL newVal);
BOOL CkTar_getVerboseLogging(HCkTar cHandle);
void CkTar_putVerboseLogging(HCkTar cHandle, BOOL newVal);
void CkTar_getVersion(HCkTar cHandle, HCkString retval);
const char *CkTar_version(HCkTar cHandle);
void CkTar_getWriteFormat(HCkTar cHandle, HCkString retval);
void CkTar_putWriteFormat(HCkTar cHandle, const char *newVal);
const char *CkTar_writeFormat(HCkTar cHandle);
BOOL CkTar_AddDirRoot(HCkTar cHandle, const char *dirPath);
BOOL CkTar_GetDirRoot(HCkTar cHandle, int index, HCkString outStr);
const char *CkTar_getDirRoot(HCkTar cHandle, int index);
BOOL CkTar_ListXml(HCkTar cHandle, const char *tarPath, HCkString outStr);
const char *CkTar_listXml(HCkTar cHandle, const char *tarPath);
BOOL CkTar_SaveLastError(HCkTar cHandle, const char *path);
BOOL CkTar_UnlockComponent(HCkTar cHandle, const char *unlockCode);
int CkTar_Untar(HCkTar cHandle, const char *tarPath);
BOOL CkTar_UntarBz2(HCkTar cHandle, const char *tarPath);
BOOL CkTar_UntarFirstMatchingToMemory(HCkTar cHandle, HCkByteData tarFileBytes, const char *matchPattern, HCkByteData outBytes);
int CkTar_UntarFromMemory(HCkTar cHandle, HCkByteData tarFileBytes);
BOOL CkTar_UntarGz(HCkTar cHandle, const char *tarPath);
BOOL CkTar_UntarZ(HCkTar cHandle, const char *tarPath);
BOOL CkTar_VerifyTar(HCkTar cHandle, const char *tarPath);
BOOL CkTar_WriteTar(HCkTar cHandle, const char *tarPath);
BOOL CkTar_WriteTarBz2(HCkTar cHandle, const char *bz2Path);
BOOL CkTar_WriteTarGz(HCkTar cHandle, const char *gzPath);
#endif
