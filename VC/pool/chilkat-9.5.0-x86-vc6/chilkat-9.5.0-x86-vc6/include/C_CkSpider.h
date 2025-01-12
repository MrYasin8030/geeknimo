// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkSpider_H
#define _C_CkSpider_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkSpider CkSpider_Create(void);
void CkSpider_Dispose(HCkSpider handle);
BOOL CkSpider_getAvoidHttps(HCkSpider cHandle);
void CkSpider_putAvoidHttps(HCkSpider cHandle, BOOL newVal);
void CkSpider_getCacheDir(HCkSpider cHandle, HCkString retval);
void CkSpider_putCacheDir(HCkSpider cHandle, const char *newVal);
const char *CkSpider_cacheDir(HCkSpider cHandle);
BOOL CkSpider_getChopAtQuery(HCkSpider cHandle);
void CkSpider_putChopAtQuery(HCkSpider cHandle, BOOL newVal);
int CkSpider_getConnectTimeout(HCkSpider cHandle);
void CkSpider_putConnectTimeout(HCkSpider cHandle, int newVal);
void CkSpider_getDebugLogFilePath(HCkSpider cHandle, HCkString retval);
void CkSpider_putDebugLogFilePath(HCkSpider cHandle, const char *newVal);
const char *CkSpider_debugLogFilePath(HCkSpider cHandle);
void CkSpider_getDomain(HCkSpider cHandle, HCkString retval);
const char *CkSpider_domain(HCkSpider cHandle);
BOOL CkSpider_getFetchFromCache(HCkSpider cHandle);
void CkSpider_putFetchFromCache(HCkSpider cHandle, BOOL newVal);
int CkSpider_getHeartbeatMs(HCkSpider cHandle);
void CkSpider_putHeartbeatMs(HCkSpider cHandle, int newVal);
void CkSpider_getLastErrorHtml(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastErrorHtml(HCkSpider cHandle);
void CkSpider_getLastErrorText(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastErrorText(HCkSpider cHandle);
void CkSpider_getLastErrorXml(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastErrorXml(HCkSpider cHandle);
BOOL CkSpider_getLastFromCache(HCkSpider cHandle);
void CkSpider_getLastHtml(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastHtml(HCkSpider cHandle);
void CkSpider_getLastHtmlDescription(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastHtmlDescription(HCkSpider cHandle);
void CkSpider_getLastHtmlKeywords(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastHtmlKeywords(HCkSpider cHandle);
void CkSpider_getLastHtmlTitle(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastHtmlTitle(HCkSpider cHandle);
void CkSpider_getLastModDate(HCkSpider cHandle, SYSTEMTIME *retval);
void CkSpider_getLastModDateStr(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastModDateStr(HCkSpider cHandle);
void CkSpider_getLastUrl(HCkSpider cHandle, HCkString retval);
const char *CkSpider_lastUrl(HCkSpider cHandle);
int CkSpider_getMaxResponseSize(HCkSpider cHandle);
void CkSpider_putMaxResponseSize(HCkSpider cHandle, int newVal);
int CkSpider_getMaxUrlLen(HCkSpider cHandle);
void CkSpider_putMaxUrlLen(HCkSpider cHandle, int newVal);
int CkSpider_getNumAvoidPatterns(HCkSpider cHandle);
int CkSpider_getNumFailed(HCkSpider cHandle);
int CkSpider_getNumOutboundLinks(HCkSpider cHandle);
int CkSpider_getNumSpidered(HCkSpider cHandle);
int CkSpider_getNumUnspidered(HCkSpider cHandle);
BOOL CkSpider_getPreferIpv6(HCkSpider cHandle);
void CkSpider_putPreferIpv6(HCkSpider cHandle, BOOL newVal);
void CkSpider_getProxyDomain(HCkSpider cHandle, HCkString retval);
void CkSpider_putProxyDomain(HCkSpider cHandle, const char *newVal);
const char *CkSpider_proxyDomain(HCkSpider cHandle);
void CkSpider_getProxyLogin(HCkSpider cHandle, HCkString retval);
void CkSpider_putProxyLogin(HCkSpider cHandle, const char *newVal);
const char *CkSpider_proxyLogin(HCkSpider cHandle);
void CkSpider_getProxyPassword(HCkSpider cHandle, HCkString retval);
void CkSpider_putProxyPassword(HCkSpider cHandle, const char *newVal);
const char *CkSpider_proxyPassword(HCkSpider cHandle);
int CkSpider_getProxyPort(HCkSpider cHandle);
void CkSpider_putProxyPort(HCkSpider cHandle, int newVal);
int CkSpider_getReadTimeout(HCkSpider cHandle);
void CkSpider_putReadTimeout(HCkSpider cHandle, int newVal);
BOOL CkSpider_getUpdateCache(HCkSpider cHandle);
void CkSpider_putUpdateCache(HCkSpider cHandle, BOOL newVal);
void CkSpider_getUserAgent(HCkSpider cHandle, HCkString retval);
void CkSpider_putUserAgent(HCkSpider cHandle, const char *newVal);
const char *CkSpider_userAgent(HCkSpider cHandle);
BOOL CkSpider_getUtf8(HCkSpider cHandle);
void CkSpider_putUtf8(HCkSpider cHandle, BOOL newVal);
BOOL CkSpider_getVerboseLogging(HCkSpider cHandle);
void CkSpider_putVerboseLogging(HCkSpider cHandle, BOOL newVal);
void CkSpider_getVersion(HCkSpider cHandle, HCkString retval);
const char *CkSpider_version(HCkSpider cHandle);
int CkSpider_getWindDownCount(HCkSpider cHandle);
void CkSpider_putWindDownCount(HCkSpider cHandle, int newVal);
void CkSpider_AddAvoidOutboundLinkPattern(HCkSpider cHandle, const char *pattern);
void CkSpider_AddAvoidPattern(HCkSpider cHandle, const char *pattern);
void CkSpider_AddMustMatchPattern(HCkSpider cHandle, const char *pattern);
void CkSpider_AddUnspidered(HCkSpider cHandle, const char *url);
BOOL CkSpider_CanonicalizeUrl(HCkSpider cHandle, const char *url, HCkString outStr);
const char *CkSpider_canonicalizeUrl(HCkSpider cHandle, const char *url);
void CkSpider_ClearFailedUrls(HCkSpider cHandle);
void CkSpider_ClearOutboundLinks(HCkSpider cHandle);
void CkSpider_ClearSpideredUrls(HCkSpider cHandle);
BOOL CkSpider_CrawlNext(HCkSpider cHandle);
BOOL CkSpider_FetchRobotsText(HCkSpider cHandle, HCkString outStr);
const char *CkSpider_fetchRobotsText(HCkSpider cHandle);
BOOL CkSpider_GetAvoidPattern(HCkSpider cHandle, int index, HCkString outStr);
const char *CkSpider_getAvoidPattern(HCkSpider cHandle, int index);
BOOL CkSpider_GetBaseDomain(HCkSpider cHandle, const char *domain, HCkString outStr);
const char *CkSpider_getBaseDomain(HCkSpider cHandle, const char *domain);
BOOL CkSpider_GetFailedUrl(HCkSpider cHandle, int index, HCkString outStr);
const char *CkSpider_getFailedUrl(HCkSpider cHandle, int index);
BOOL CkSpider_GetOutboundLink(HCkSpider cHandle, int index, HCkString outStr);
const char *CkSpider_getOutboundLink(HCkSpider cHandle, int index);
BOOL CkSpider_GetSpideredUrl(HCkSpider cHandle, int index, HCkString outStr);
const char *CkSpider_getSpideredUrl(HCkSpider cHandle, int index);
BOOL CkSpider_GetUnspideredUrl(HCkSpider cHandle, int index, HCkString outStr);
const char *CkSpider_getUnspideredUrl(HCkSpider cHandle, int index);
BOOL CkSpider_GetUrlDomain(HCkSpider cHandle, const char *url, HCkString outStr);
const char *CkSpider_getUrlDomain(HCkSpider cHandle, const char *url);
void CkSpider_Initialize(HCkSpider cHandle, const char *domain);
BOOL CkSpider_RecrawlLast(HCkSpider cHandle);
BOOL CkSpider_SaveLastError(HCkSpider cHandle, const char *path);
void CkSpider_SkipUnspidered(HCkSpider cHandle, int index);
void CkSpider_SleepMs(HCkSpider cHandle, int numMilliseconds);
#endif
