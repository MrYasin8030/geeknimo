
/*
* 带密钥的md5算法库md5lib.h共有下列函数:
*
* char* MDString (char *);
* 输入任意一个字符串，经过md5运算后,返回32个字符长的字符串
*
* char* MDFile (char *);
* 输入任意一个文件名，文件内容经过md5运算后，返回32个字符长的字符串
*
* char* hmac_md5(char* text, char* key);
* 输入任意一个字符串text，和一个用做密钥的字符串key，
* 经过hmac_md5算法处理，返回处理结果：一个定长字符串(32个字符)
*/

/* MD5lib.h - md5 library
*
* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All
* rights reserved.

* RSA Data Security, Inc. makes no representations concerning either
* the merchantability of this software or the suitability of this
* software for any particular purpose. It is provided "as is"
* without express or implied warranty of any kind.

* These notices must be retained in any copies of any part of this
* documentation and/or software.

* The following makes MD default to MD5 if it has not already been
* defined with C compiler flags.
*/
#ifndef _MD5_PASSWORD_H_
#define _MD5_PASSWORD_H_	

#include <stdio.h>
#include <time.h>
#include <string.h>

#define MD 5

/* GLOBAL.H - RSAREF types and constants

* PROTOTYPES should be set to one if and only if the compiler supports
* function argument prototyping.
* The following makes PROTOTYPES default to 0 if it has not already
* been defined with C compiler flags.
*/

#ifndef PROTOTYPES
#define PROTOTYPES 1
#endif

typedef unsigned char *POINTER; /* POINTER defines a generic pointer type */
typedef unsigned short int UINT2; /* UINT2 defines a two byte word */
typedef unsigned long int UINT4; /* UINT4 defines a four byte word */

/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
   If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it returns an empty list. */

#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif

/* Length of test block, number of test blocks. */
#define TEST_BLOCK_LEN 1000
#define TEST_BLOCK_COUNT 1000

/* Constants for MD5Transform routine. */
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

char* MDString PROTO_LIST ((char *));
char* MDFile PROTO_LIST ((char *));
char* hmac_md5(char* text, char* key);

typedef struct {
    UINT4 state[4];    /* state (ABCD) */
    UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
    unsigned char buffer[64]; /* input buffer */
} MD5_CTX;

static unsigned char PADDING[64] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/* F, G, H and I are basic MD5 functions. */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits. */
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
   Rotation is separate from addition to prevent recomputation. */
#define FF(a, b, c, d, x, s, ac) { \
    (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
    (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
    (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
    (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
}

void MD5Init (MD5_CTX *context);
void MD5Update(MD5_CTX *context, unsigned char *input,unsigned int inputLen);

void MD5Final (unsigned char digest[16], MD5_CTX *context);
static void MD5Transform (UINT4 [4], unsigned char [64]) ;
static void Encode(unsigned char *, UINT4 *, unsigned int);
static void Decode (UINT4 *, unsigned char *, unsigned int);
static void MD5_memcpy(POINTER, POINTER, unsigned int);
static void MD5_memset(POINTER, int, unsigned int);


#endif