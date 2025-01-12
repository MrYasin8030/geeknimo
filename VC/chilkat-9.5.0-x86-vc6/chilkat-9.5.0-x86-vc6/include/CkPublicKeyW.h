// CkPublicKeyW.h: interface for the CkPublicKeyW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkPublicKeyW_H
#define _CkPublicKeyW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkWideCharBase.h"

class CkByteData;



#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkPublicKeyW
class CkPublicKeyW  : public CkWideCharBase
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkPublicKeyW(const CkPublicKeyW &);
	CkPublicKeyW &operator=(const CkPublicKeyW &);

    public:
	CkPublicKeyW(void);
	virtual ~CkPublicKeyW(void);

	static CkPublicKeyW *createNew(void);
	

	
	void inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------


	// ----------------------
	// Methods
	// ----------------------
	// Gets the public key in OpenSSL DER format.
	bool GetOpenSslDer(CkByteData &outData);

	// Gets the public key in OpenSSL PEM format.
	bool GetOpenSslPem(CkString &outStr);
	// Gets the public key in OpenSSL PEM format.
	const wchar_t *getOpenSslPem(void);
	// Gets the public key in OpenSSL PEM format.
	const wchar_t *openSslPem(void);

	// Gets the public key in RSA DER format.
	bool GetRsaDer(CkByteData &outData);

	// Gets the public key in XML format. The XML has this format where the key parts
	// are base64 encoded:
	// 
	// <RSAKeyValue>
	//   <Modulus>...</Modulus>
	//   <Exponent>...</Exponent>
	// </RSAKeyValue>
	bool GetXml(CkString &outStr);
	// Gets the public key in XML format. The XML has this format where the key parts
	// are base64 encoded:
	// 
	// <RSAKeyValue>
	//   <Modulus>...</Modulus>
	//   <Exponent>...</Exponent>
	// </RSAKeyValue>
	const wchar_t *getXml(void);
	// Gets the public key in XML format. The XML has this format where the key parts
	// are base64 encoded:
	// 
	// <RSAKeyValue>
	//   <Modulus>...</Modulus>
	//   <Exponent>...</Exponent>
	// </RSAKeyValue>
	const wchar_t *xml(void);

	// Loads a public key from in-memory OpenSSL DER formatted byte data.
	bool LoadOpenSslDer(const CkByteData &data);

	// Loads a public key from an OpenSSL DER format file.
	bool LoadOpenSslDerFile(const wchar_t *path);

	// Loads a public key from an OpenSSL PEM string.
	bool LoadOpenSslPem(const wchar_t *str);

	// Loads a public key from an OpenSSL PEM file.
	bool LoadOpenSslPemFile(const wchar_t *path);

	// Loads an RSA public key from PKCS#1 PEM format.
	bool LoadPkcs1Pem(const wchar_t *str);

	// Loads a public key from in-memory RSA DER formatted byte data.
	bool LoadRsaDer(const CkByteData &data);

	// Loads a public key from an RSA DER formatted file.
	bool LoadRsaDerFile(const wchar_t *path);

	// Loads a public key from an XML string.
	bool LoadXml(const wchar_t *xml);

	// Loads a public key from an XML file.
	bool LoadXmlFile(const wchar_t *path);

	// Saves the public key to an OpenSSL DER format file.
	bool SaveOpenSslDerFile(const wchar_t *path);

	// Saves the public key to an OpenSSL PEM format file.
	bool SaveOpenSslPemFile(const wchar_t *path);

	// Saves the public key to an RSA DER format file.
	bool SaveRsaDerFile(const wchar_t *path);

	// Saves the public key to an XML file.
	bool SaveXmlFile(const wchar_t *path);





	// END PUBLIC INTERFACE


};
#ifndef __sun__
#pragma pack (pop)
#endif


	
#endif
