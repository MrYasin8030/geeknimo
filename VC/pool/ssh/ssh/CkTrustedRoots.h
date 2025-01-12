// CkTrustedRoots.h: interface for the CkTrustedRoots class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkTrustedRoots_H
#define _CkTrustedRoots_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkMultiByteBase.h"

class CkCert;
class CkBaseProgress;



#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkTrustedRoots
class CkTrustedRoots  : public CkMultiByteBase
{
    private:
	CkBaseProgress *m_callback;

	// Don't allow assignment or copying these objects.
	CkTrustedRoots(const CkTrustedRoots &);
	CkTrustedRoots &operator=(const CkTrustedRoots &);

    public:
	CkTrustedRoots(void);
	virtual ~CkTrustedRoots(void);

	static CkTrustedRoots *createNew(void);
	void inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	CkBaseProgress *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkBaseProgress *progress);


	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of certificates contained within this object.
	int get_NumCerts(void);



	// ----------------------
	// Methods
	// ----------------------
	// Loads a CA bundle in PEM format. This is a file containing CA root certificates
	// that are to be trusted. An example of one such file is the CA certs from
	// mozilla.org exported to a cacert.pem file by the mk-ca-bundle tool located here:
	// http://curl.haxx.se/docs/caextract.html.
	// 
	// Note: This can also be called to load the /etc/ssl/certs/ca-certificates.crt
	// file on Linux systems.
	// 
	bool LoadCaCertsPem(const char *path);

	// Returns the Nth cert contained within this object. The 1st certificate is at
	// index 0.
	// The caller is responsible for deleting the object returned by this method.
	CkCert *GetCert(int index);

	// Activates this collection of trusted roots as the set of CA and self-signed root
	// certificates that are to be trusted Chilkat-wide for PKCS7 signature validation
	// and SSL/TLS server certificate validation.
	bool Activate(void);

	// Deactivates a previously set of activated trusted roots so that all roots /
	// self-signed certificates are implicitly trusted.
	bool Deactivate(void);





	// END PUBLIC INTERFACE


};
#ifndef __sun__
#pragma pack (pop)
#endif


	
#endif
