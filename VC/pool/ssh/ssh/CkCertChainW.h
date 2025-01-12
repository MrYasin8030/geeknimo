// CkCertChainW.h: interface for the CkCertChainW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCertChainW_H
#define _CkCertChainW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkWideCharBase.h"

class CkCertW;
class CkTrustedRootsW;



#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkCertChainW
class CkCertChainW  : public CkWideCharBase
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCertChainW(const CkCertChainW &);
	CkCertChainW &operator=(const CkCertChainW &);

    public:
	CkCertChainW(void);
	virtual ~CkCertChainW(void);

	static CkCertChainW *createNew(void);
	

	
	void inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of certificates in the chain. The end-user subscriber certificate is
	// at index 0. This is the certificate most removed from the trusted root.
	// Intermediate certificates are at indices 1 to NumCerts - 2. The trusted root (or
	// self-signed certificate) is at index NumCerts - 1.
	int get_NumCerts(void);

	// Returns the number of certificates in the chain that have expired.
	int get_NumExpiredCerts(void);



	// ----------------------
	// Methods
	// ----------------------
	// Returns the Nth certificate in the chain.
	// The caller is responsible for deleting the object returned by this method.
	CkCertW *GetCert(int index);

	// Verifies the certificate signatures to the root. Returns true if all
	// certificate signatures are valid.
	bool VerifyCertSignatures(void);

	// Returns true if the root of the certificate chain is a certificate found in
	// ARG1.
	bool IsRootTrusted(CkTrustedRootsW &trustedRoots);





	// END PUBLIC INTERFACE


};
#ifndef __sun__
#pragma pack (pop)
#endif


	
#endif
