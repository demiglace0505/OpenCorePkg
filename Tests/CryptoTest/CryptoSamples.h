/** @file
  Test crypto algos support.

Copyright (c) 2018, savvas. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#define HASH_SAMPLES_NUM 4
#define AES_SAMPLE_DATA_LEN 64
#define SIGNED_DATA_LEN 512

//
// Data samples for hash algorithms
//
const CHAR8 Sample1 [] = "Test string\0";
const CHAR8 Sample2 [] = "Test string test\0";
const CHAR8 Sample3 [] = "Test string test test\0";
const CHAR8 Sample4 [] = "Test string test test. Test?"\
                        " Or test? Maybe test? Give me some test\0";

//
// Data structures for samples
//
typedef struct AES_128_CBC_SAMPLE_ {
  UINT8  IV[AES_BLOCK_SIZE];
  UINT8  PlainText[AES_SAMPLE_DATA_LEN];
  UINT8  CipherText[AES_SAMPLE_DATA_LEN];
  UINT8  Key[CONFIG_AES_KEY_SIZE];
} AES_128_CBC_SAMPLE;

typedef struct AES_128_CTR_SAMPLE_ {
  UINT8  IV[AES_BLOCK_SIZE];
  UINT8  PlainText[AES_SAMPLE_DATA_LEN];
  UINT8  CipherText[AES_SAMPLE_DATA_LEN];
  UINT8  Key[CONFIG_AES_KEY_SIZE];
} AES_128_CTR_SAMPLE;

typedef struct HASH_SAMPLE_ {
  UINT8  *PlainText;
  UINTN  PlainTextLen;
  UINT8  Md5Hash[MD5_DIGEST_SIZE];
  UINT8  Sha1Hash[SHA1_DIGEST_SIZE];
  UINT8  Sha256Hash[SHA256_DIGEST_SIZE];
  UINT8  Sha512Hash[SHA512_DIGEST_SIZE];
  UINT8  Sha384Hash[SHA384_DIGEST_SIZE];
} HASH_SAMPLE;

typedef struct RSA2048SHA256_SIGN_SAMPLE_ {
  UINT8 Data[SIGNED_DATA_LEN];
  UINT8 Signature[256];
  UINT8 PublicKey[520];
} RSA2048SHA256_SIGN_SAMPLE;

//
// RSA2048SHA256
// Signature
//
RSA2048SHA256_SIGN_SAMPLE Rsa2048Sha256Sample = {
  //
  // Data
  //
  {
    0x96, 0x6c, 0x91, 0xaf, 0x6c, 0xc7,
    0x6b, 0x72, 0xf5, 0xa2, 0xc2, 0xbf,
    0x14, 0xf2, 0x4e, 0xe7, 0x29, 0x7e,
    0xc2, 0xca, 0xa7, 0x6f, 0xca, 0x09,
    0xe7, 0x5a, 0xbe, 0x8b, 0x73, 0x3a,
    0x5e, 0x3d, 0x58, 0x54, 0xbe, 0x32,
    0x48, 0x33, 0x27, 0x99, 0x1e, 0x6b,
    0x41, 0x13, 0x9e, 0x29, 0xe3, 0x96,
    0x12, 0xdd, 0x58, 0x56, 0x1c, 0x76,
    0x54, 0x31, 0x92, 0xcb, 0xa2, 0xec,
    0xc3, 0x4f, 0xe3, 0x9d, 0x8b, 0xd2,
    0xb0, 0x9b, 0x6f, 0x07, 0x54, 0x7a,
    0x38, 0x1b, 0x97, 0x02, 0x67, 0x73,
    0x54, 0x5c, 0x07, 0x6c, 0xeb, 0x21,
    0xe0, 0x0b, 0x61, 0x09, 0x79, 0x48,
    0xe0, 0xe1, 0x69, 0xa7, 0x41, 0x88,
    0x7c, 0x0f, 0x03, 0x82, 0x6a, 0x9f,
    0xdc, 0xa9, 0x63, 0x7d, 0xa7, 0x2f,
    0xf4, 0x4f, 0x3d, 0x0b, 0xce, 0xfd,
    0xc5, 0x65, 0x19, 0x73, 0xb6, 0xe1,
    0xb3, 0xc7, 0xde, 0xc4, 0x45, 0xf6,
    0x34, 0xe0, 0x7a, 0x4e, 0xc2, 0xc2,
    0x66, 0xfc, 0x64, 0x41, 0x9a, 0xb0,
    0xe6, 0x36, 0x4d, 0xc9, 0xf9, 0x59,
    0x4d, 0x77, 0x3d, 0x18, 0xe1, 0x7d,
    0x75, 0x91, 0xee, 0x26, 0x9c, 0x1f,
    0x4b, 0x83, 0xae, 0x94, 0xb4, 0xdc,
    0xd4, 0x2f, 0xc7, 0x03, 0xb3, 0x84,
    0x2b, 0xe6, 0xf3, 0x03, 0xb5, 0x9c,
    0x26, 0xcd, 0x02, 0x3c, 0x96, 0x00,
    0x93, 0x7c, 0x7b, 0xd3, 0x5f, 0xbb,
    0x90, 0x00, 0x52, 0xe7, 0x64, 0x40,
    0xba, 0x92, 0x65, 0x61, 0x6c, 0xae,
    0xe2, 0x83, 0xd4, 0x86, 0xa6, 0x5a,
    0x41, 0x81, 0xd5, 0x40, 0x83, 0xb0,
    0xe0, 0x35, 0xff, 0xc0, 0xd2, 0x2b,
    0xc0, 0xfb, 0x7e, 0x4c, 0x42, 0x80,
    0xeb, 0x40, 0x4e, 0xd5, 0x7c, 0x2f,
    0xd8, 0x42, 0x0e, 0x0d, 0x28, 0x2b,
    0x8f, 0x39, 0x69, 0x90, 0xb5, 0x82,
    0xd9, 0xf8, 0x39, 0xa3, 0x90, 0xce,
    0xb5, 0xfe, 0x74, 0xd9, 0x9d, 0x5a,
    0xa4, 0xfd, 0xa1, 0x99, 0x0f, 0xc8,
    0x8e, 0xee, 0x65, 0xce, 0x85, 0xf9,
    0x6d, 0xf6, 0xb1, 0x46, 0x89, 0x54,
    0x6d, 0xce, 0x00, 0x54, 0x12, 0x75,
    0x5a, 0x2e, 0xfd, 0x37, 0x90, 0x04,
    0xaf, 0x0f, 0xd4, 0xca, 0xf6, 0x0f,
    0x88, 0x2d, 0xc4, 0xd6, 0xc8, 0x49,
    0x84, 0x31, 0x18, 0x48, 0x3f, 0x23,
    0x83, 0xa4, 0xee, 0x2f, 0x13, 0xb3,
    0x9b, 0x4e, 0xc3, 0x65, 0x8b, 0xf5,
    0x9c, 0x05, 0x06, 0x53, 0x50, 0x0e,
    0x96, 0xf3, 0xba, 0xb1, 0x28, 0x82,
    0x45, 0xd2, 0x17, 0x34, 0xbc, 0xc4,
    0x5a, 0x57, 0xf2, 0x9b, 0x59, 0xf0,
    0x7b, 0xfa, 0x53, 0xac, 0xbd, 0x7e,
    0xde, 0x69, 0x16, 0x34, 0xc9, 0x05,
    0xc0, 0xb8, 0x59, 0x19, 0x04, 0xca,
    0xb7, 0xe5, 0x0c, 0x4a, 0x54, 0x3e,
    0x92, 0x1b, 0x98, 0x0f, 0x37, 0xe0,
    0x96, 0x03, 0x96, 0x7d, 0xa7, 0x2b,
    0x93, 0x3f, 0x17, 0x89, 0xb7, 0x3a,
    0x3d, 0xe0, 0x47, 0x72, 0x36, 0xe5,
    0x69, 0xb8, 0x50, 0x89, 0x02, 0x3b,
    0xa3, 0xc4, 0xac, 0x27, 0x8a, 0x45,
    0xa8, 0x32, 0x30, 0x3c, 0x2a, 0x2c,
    0x4f, 0xb2, 0x86, 0x9c, 0xe4, 0xce,
    0xa1, 0xd9, 0xdb, 0xd5, 0x52, 0x35,
    0xe5, 0xf7, 0x68, 0x4f, 0x3c, 0x40,
    0x69, 0xd2, 0x61, 0x07, 0xe6, 0x7c,
    0xb3, 0x3d, 0x9a, 0x16, 0x16, 0x27,
    0xdf, 0x71, 0x88, 0xe9, 0xff, 0x59,
    0x35, 0x07, 0xc8, 0xa8, 0x9b, 0x71,
    0x46, 0x59, 0x6b, 0xfc, 0x6a, 0x61,
    0x79, 0x21, 0xdd, 0xda, 0x01, 0x09,
    0x05, 0x31, 0x25, 0x5e, 0x19, 0x94,
    0x65, 0xcc, 0xcc, 0x39, 0x73, 0xb5,
    0xa3, 0x8d, 0x8c, 0x45, 0xd7, 0x5b,
    0xcf, 0xdf, 0x18, 0xcc, 0x4e, 0x30,
    0xd3, 0x8a, 0x5a, 0x2e, 0x2b, 0x0f,
    0xbd, 0x60, 0x89, 0xcb, 0xf1, 0x60,
    0x2c, 0x5b, 0xcc, 0x47, 0x97, 0x34,
    0x4f, 0x94, 0x55, 0x13, 0xbd, 0x42,
    0x76, 0x68, 0x26, 0xff, 0x3a, 0x58,
    0x70, 0xaf
  },
  //
  // Signature
  //
  {
    0xd9, 0xf1, 0xc0, 0x86, 0x87, 0x76,
    0x42, 0xcd, 0xd1, 0x00, 0xe3, 0x8b,
    0x8d, 0xf3, 0x47, 0xbc, 0x1a, 0xf9,
    0xb2, 0xd9, 0x22, 0x0c, 0x44, 0xab,
    0x8e, 0x3e, 0xb3, 0xd1, 0xc8, 0xf0,
    0xf1, 0x53, 0xdb, 0xb6, 0x29, 0xcd,
    0x16, 0xc9, 0x36, 0xbd, 0xb8, 0x32,
    0x53, 0x6a, 0xa2, 0x44, 0xa6, 0x8a,
    0x82, 0x86, 0xde, 0xbf, 0x61, 0x69,
    0xe7, 0x0d, 0x52, 0x05, 0xcb, 0x5b,
    0xad, 0x75, 0xd7, 0x38, 0x31, 0xb8,
    0x02, 0xb0, 0xeb, 0x51, 0xa4, 0x07,
    0x70, 0x83, 0x12, 0xf3, 0xf4, 0xa1,
    0x23, 0x3b, 0x0b, 0xbe, 0x3f, 0x7b,
    0x31, 0x5e, 0x26, 0x59, 0xb2, 0xaf,
    0x34, 0x11, 0x25, 0xfc, 0x17, 0xea,
    0xe0, 0x5f, 0x48, 0x77, 0x14, 0xb0,
    0x44, 0x5b, 0xd2, 0xea, 0xcd, 0x0e,
    0xe5, 0x27, 0x4e, 0x5d, 0x05, 0xd6,
    0x7b, 0xf3, 0x35, 0x17, 0x4b, 0xf6,
    0xcd, 0xda, 0x17, 0x96, 0x56, 0xd8,
    0x99, 0xbb, 0x17, 0x2d, 0xa3, 0xa1,
    0x1c, 0x72, 0xbb, 0x06, 0x92, 0x32,
    0x08, 0x38, 0x4d, 0xb8, 0x02, 0x18,
    0xb4, 0x21, 0x59, 0x58, 0x41, 0x19,
    0x70, 0xe4, 0x9d, 0x34, 0x1b, 0xdc,
    0xbe, 0x81, 0x99, 0xf6, 0x70, 0x49,
    0x48, 0xd6, 0x88, 0xb0, 0x98, 0x1e,
    0x25, 0x14, 0x8f, 0x47, 0x62, 0x0f,
    0xcd, 0xdf, 0xaa, 0x64, 0x2b, 0x11,
    0xb9, 0x54, 0xb6, 0x11, 0xb8, 0xb4,
    0xad, 0xf2, 0xc7, 0x65, 0x43, 0xf0,
    0xe7, 0x93, 0xfb, 0x78, 0x87, 0xc9,
    0x3e, 0xa8, 0xa7, 0x79, 0xe9, 0x1c,
    0x0f, 0xe1, 0x36, 0x8e, 0x2f, 0xee,
    0x58, 0xa7, 0x54, 0x84, 0x51, 0x32,
    0xc3, 0x5a, 0x21, 0x7a, 0x58, 0xd9,
    0x38, 0xea, 0xca, 0xcd, 0xb7, 0x29,
    0x1f, 0x1e, 0xa9, 0x60, 0xce, 0x4a,
    0xfd, 0x61, 0xd6, 0x1e, 0x9c, 0x04,
    0x65, 0x47, 0x94, 0xd5, 0xca, 0x26,
    0x7a, 0x80, 0xcc, 0xb1, 0x54, 0x4b,
    0x3e, 0xe7, 0x71, 0xc1
  },
  //
  // Public key
  //
  {
    0x40, 0x00, 0x00, 0x00, 0xeb, 0x5a,
    0xbc, 0xa0, 0x3d, 0x82, 0x19, 0x84,
    0x5d, 0x8b, 0x97, 0xc9, 0xf1, 0x76,
    0xb9, 0xab, 0x21, 0xd1, 0xea, 0xc5,
    0x77, 0x69, 0xd4, 0x08, 0xec, 0x3f,
    0xb5, 0x3b, 0xff, 0xc0, 0x43, 0x6c,
    0x76, 0x6f, 0xf8, 0x19, 0xcf, 0x53,
    0x28, 0xf0, 0x79, 0xa0, 0xc5, 0x62,
    0x3b, 0xec, 0x4a, 0x00, 0x0d, 0xc4,
    0x8c, 0x30, 0xb7, 0xb9, 0x81, 0xd7,
    0xd3, 0xea, 0x86, 0xaa, 0xc1, 0xe5,
    0x26, 0xa6, 0xc0, 0xbc, 0xd9, 0xf1,
    0x3c, 0x42, 0x1e, 0x9b, 0x6c, 0xe3,
    0xbe, 0x60, 0x1a, 0x91, 0x55, 0x6a,
    0x4c, 0xcb, 0x82, 0x16, 0x10, 0x69,
    0x68, 0x7e, 0xa5, 0xa6, 0xa6, 0x5f,
    0x6c, 0xfe, 0x7c, 0x79, 0x08, 0xe6,
    0x91, 0x46, 0xfa, 0x5d, 0x27, 0x03,
    0x78, 0x28, 0x05, 0x08, 0xbb, 0x7a,
    0x83, 0x04, 0xf0, 0x6d, 0x23, 0x08,
    0x5a, 0x62, 0x03, 0x83, 0xa3, 0x3c,
    0x75, 0xd8, 0xdf, 0x26, 0xab, 0x10,
    0xa7, 0x80, 0x29, 0xf1, 0x95, 0xe9,
    0x35, 0x6a, 0x9e, 0xbb, 0xfe, 0xa7,
    0x10, 0x7a, 0xcc, 0xbd, 0x8a, 0xdf,
    0x6a, 0x35, 0x17, 0x53, 0x28, 0x7e,
    0xfe, 0x64, 0x50, 0x28, 0x4b, 0xd9,
    0x8f, 0x5f, 0xcd, 0x79, 0x88, 0xa4,
    0xd2, 0xe7, 0x51, 0xee, 0x2b, 0xfa,
    0x6c, 0x71, 0xf6, 0xc4, 0x50, 0x3f,
    0x23, 0x28, 0x98, 0x76, 0xd0, 0x91,
    0x84, 0x69, 0x34, 0xa4, 0x05, 0x7e,
    0x25, 0x45, 0xd8, 0x6d, 0xe4, 0x58,
    0x8b, 0x6e, 0xcb, 0xed, 0xe6, 0xe9,
    0x53, 0xf5, 0x0b, 0x3c, 0x51, 0xd8,
    0xbb, 0x6b, 0x49, 0xa1, 0x93, 0x71,
    0x6e, 0xa8, 0x7f, 0x92, 0xb5, 0x5f,
    0x88, 0x86, 0x38, 0x16, 0x3b, 0x06,
    0x02, 0x3f, 0xf9, 0x2c, 0x1d, 0x33,
    0x8b, 0x3c, 0xa5, 0x04, 0xdd, 0xf9,
    0xfe, 0x7a, 0x3d, 0xcb, 0xf8, 0x7a,
    0x6b, 0x31, 0x36, 0x2b, 0xed, 0x90,
    0x50, 0x62, 0x22, 0x89, 0x96, 0xae,
    0xf6, 0x57, 0x89, 0xae, 0xf5, 0xdd,
    0xf5, 0xaa, 0x0b, 0x16, 0x32, 0x3f,
    0xf0, 0xe9, 0x6a, 0x74, 0x1f, 0x17,
    0x52, 0x40, 0xa6, 0xc8, 0x45, 0x5d,
    0x2d, 0x72, 0x2c, 0x01, 0x6b, 0x25,
    0x02, 0x92, 0x55, 0xe3, 0x8b, 0x60,
    0x99, 0xda, 0xf1, 0x9a, 0x89, 0x9c,
    0xe0, 0x84, 0x97, 0x64, 0x79, 0x53,
    0x21, 0x95, 0xdc, 0x30, 0x61, 0xc1,
    0xa1, 0x11, 0x3d, 0x37, 0xb0, 0x1b,
    0xe5, 0x4a, 0xbb, 0x9d, 0x5b, 0xca,
    0xce, 0x10, 0xb6, 0x64, 0x28, 0x64,
    0x29, 0x00, 0x5f, 0xe1, 0x27, 0x45,
    0x89, 0xc9, 0x2e, 0x4e, 0xe9, 0x3a,
    0x6c, 0x3c, 0x29, 0x7e, 0x00, 0xa1,
    0xb8, 0x41, 0x26, 0x0d, 0xd5, 0xb8,
    0x75, 0x8f, 0x78, 0xb0, 0xb5, 0x01,
    0x2c, 0xe5, 0xd2, 0xdf, 0x0a, 0x42,
    0xd8, 0xa2, 0x8a, 0xb5, 0x77, 0x07,
    0xdd, 0xdb, 0x6d, 0xba, 0x6f, 0xf6,
    0xfc, 0x48, 0x52, 0xd0, 0xbf, 0x49,
    0xb7, 0xad, 0xe1, 0x6e, 0x75, 0xd4,
    0x6d, 0x37, 0xa0, 0x2a, 0x25, 0xd9,
    0xf6, 0xd3, 0x5f, 0xf3, 0xed, 0xa1,
    0x36, 0x95, 0xf8, 0x18, 0xd0, 0xed,
    0x57, 0x36, 0x50, 0x9c, 0x3a, 0x00,
    0xa4, 0x07, 0xc2, 0xfb, 0x63, 0x2d,
    0x6a, 0x40, 0x1b, 0xdd, 0x5e, 0x41,
    0xb0, 0xb6, 0xd1, 0xba, 0x45, 0xce,
    0xce, 0xb8, 0x0f, 0x7d, 0x84, 0xa4,
    0x37, 0x01, 0x65, 0xf3, 0x2a, 0x9c,
    0x02, 0x87, 0xe7, 0x58, 0xf4, 0x99,
    0x1d, 0x65, 0x20, 0x39, 0xd9, 0x05,
    0x9a, 0xbb, 0x78, 0xcb, 0x0a, 0x3f,
    0x4d, 0x6d, 0x10, 0xc8, 0x2f, 0x69,
    0x32, 0xa3, 0xd2, 0x94, 0x3e, 0xdc,
    0x17, 0x7a, 0x20, 0x8d, 0x49, 0x16,
    0x5c, 0x39, 0x7e, 0x71, 0xc1, 0x76,
    0xda, 0x78, 0x1b, 0x56, 0x48, 0x6a,
    0xc1, 0xdc, 0xf7, 0x88, 0x15, 0x42,
    0x3c, 0x85, 0x2b, 0xb5, 0xeb, 0x9e,
    0xce, 0xa1, 0x44, 0xf4, 0x4b, 0x6d,
    0x1b, 0x9e, 0xb3, 0xe0, 0xd2, 0xdf,
    0xa2, 0x58, 0x1c, 0x17
  }
};

//
// AES-128-CBC data sample
//
AES_128_CBC_SAMPLE AesCbcSample = {
  //
  // IV
  //
  {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
    0x0c, 0x0d, 0x0e, 0x0f
  },
  //
  // Plain text
  //
  {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40,
    0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
    0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d,
    0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf,
    0x8e, 0x51, 0x30, 0xc8, 0x1c, 0x46,
    0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb,
    0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f,
    0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b,
    0xe6, 0x6c, 0x37, 0x10
  },
  //
  // Cipher text
  //
  {
    0x76, 0x49, 0xab, 0xac, 0x81, 0x19,
    0xb2, 0x46, 0xce, 0xe9, 0x8e, 0x9b,
    0x12, 0xe9, 0x19, 0x7d, 0x50, 0x86,
    0xcb, 0x9b, 0x50, 0x72, 0x19, 0xee,
    0x95, 0xdb, 0x11, 0x3a, 0x91, 0x76,
    0x78, 0xb2, 0x73, 0xbe, 0xd6, 0xb8,
    0xe3, 0xc1, 0x74, 0x3b, 0x71, 0x16,
    0xe6, 0x9e, 0x22, 0x22, 0x95, 0x16,
    0x3f, 0xf1, 0xca, 0xa1, 0x68, 0x1f,
    0xac, 0x09, 0x12, 0x0e, 0xca, 0x30,
    0x75, 0x86, 0xe1, 0xa7
  },
  //
  // Key
  //
  {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae,
    0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88,
    0x09, 0xcf, 0x4f, 0x3c
  }
};


AES_128_CTR_SAMPLE AesCtrSample = {
  //
  // IV
  //
  {
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5,
    0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb,
    0xfc, 0xfd, 0xfe, 0xff
  },
  //
  // Plain text
  //
  {
    0x87, 0x4d, 0x61, 0x91, 0xb6, 0x20,
    0xe3, 0x26, 0x1b, 0xef, 0x68, 0x64,
    0x99, 0x0d, 0xb6, 0xce, 0x98, 0x06,
    0xf6, 0x6b, 0x79, 0x70, 0xfd, 0xff,
    0x86, 0x17, 0x18, 0x7b, 0xb9, 0xff,
    0xfd, 0xff, 0x5a, 0xe4, 0xdf, 0x3e,
    0xdb, 0xd5, 0xd3, 0x5e, 0x5b, 0x4f,
    0x09, 0x02, 0x0d, 0xb0, 0x3e, 0xab,
    0x1e, 0x03, 0x1d, 0xda, 0x2f, 0xbe,
    0x03, 0xd1, 0x79, 0x21, 0x70, 0xa0,
    0xf3, 0x00, 0x9c, 0xee
  },
  //
  // Cipher text
  //
  {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40,
    0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
    0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d,
    0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf,
    0x8e, 0x51, 0x30, 0xc8, 0x1c, 0x46,
    0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb,
    0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f,
    0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b,
    0xe6, 0x6c, 0x37, 0x10
  },
  //
  // Key
  //
  {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae,
    0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88,
    0x09, 0xcf, 0x4f, 0x3c
  }
};

//
// Hash algorithms samples
//
HASH_SAMPLE HashSamples[4] = {
  {
    (UINT8 *) Sample1,
    11,
    {
      0x0f, 0xd3, 0xdb, 0xec, 0x97, 0x30,
      0x10, 0x1b, 0xff, 0x92, 0xac, 0xc8,
      0x20, 0xbe, 0xfc, 0x34
    },
    {
      0x18, 0xaf, 0x81, 0x91, 0x25, 0xb7,
      0x08, 0x79, 0xd3, 0x63, 0x78, 0x43,
      0x1c, 0x4e, 0x8d, 0x9b, 0xfa, 0x6a,
      0x25, 0x99
    },
    {
      0xa3, 0xe4, 0x9d, 0x84, 0x3d, 0xf1,
      0x3c, 0x2e, 0x2a, 0x77, 0x86, 0xf6,
      0xec, 0xd7, 0xe0, 0xd1, 0x84, 0xf4,
      0x5d, 0x71, 0x8d, 0x1a, 0xc1, 0xa8,
      0xa6, 0x3e, 0x57, 0x04, 0x66, 0xe4,
      0x89, 0xdd
    },
    {
      0x81, 0x1a, 0xa0, 0xc5, 0x3c, 0x00, 0x39, 0xb6, 0xea, 0xd0, 0xca, 0x87,
      0x8b, 0x09, 0x6e, 0xed, 0x1d, 0x39, 0xed, 0x87, 0x3f, 0xd2, 0xd2, 0xd2,
      0x70, 0xab, 0xfb, 0x9c, 0xa6, 0x20, 0xd3, 0xed, 0x56, 0x1c, 0x56, 0x5d,
      0x6d, 0xbd, 0x11, 0x14, 0xc3, 0x23, 0xd3, 0x8e, 0x3f, 0x59, 0xc0, 0x0d,
      0xf4, 0x75, 0x45, 0x1f, 0xc9, 0xb3, 0x00, 0x74, 0xf2, 0xab, 0xda, 0x35,
      0x29, 0xdf, 0x2f, 0xa7
    },
    {
      0x83, 0xca, 0x14, 0xeb, 0xf3, 0x00, 0x5a, 0x10, 0xf5, 0x08, 0x39, 0x74,
      0x2b, 0xda, 0x82, 0xaa, 0x60, 0x7d, 0x97, 0x2a, 0x03, 0xb1, 0xe6, 0xa3,
      0x08, 0x6e, 0x29, 0x19, 0x5c, 0xea, 0xf0, 0x5f, 0x03, 0x8f, 0xec, 0xdf,
      0xf0, 0x2a, 0xff, 0x6e, 0x9d, 0xcd, 0xd2, 0x73, 0x26, 0x88, 0x75, 0xf7
    }
  },
  {
    (UINT8 *) Sample2,
    16,
    {
      0x85, 0x3d, 0x68, 0xf8, 0x8d, 0x64,
      0x5c, 0xd0, 0xc8, 0x12, 0xe0, 0x1b,
      0x54, 0x5f, 0x8b, 0x89
    },
    {
      0xdf, 0xcc, 0x54, 0xa3, 0x66, 0x7a,
      0xfd, 0xc4, 0xa1, 0x99, 0xc7, 0x69,
      0xf9, 0xd2, 0xac, 0xe4, 0xdb, 0x41,
      0xe6, 0x5d
    },
    {
      0x3e, 0x58, 0x00, 0x91, 0x7c, 0x27,
      0x3c, 0xaa, 0x02, 0x91, 0xc8, 0x70,
      0xee, 0x21, 0x8f, 0xad, 0x41, 0xa4,
      0x0f, 0x6b, 0x95, 0x1c, 0xf5, 0x4e,
      0xb1, 0xa7, 0x03, 0xd2, 0x7b, 0x9b,
      0x41, 0x1c
    },
    {
      0x3d, 0x9d, 0xd2, 0x8b, 0xfe, 0x81, 0xca, 0x44, 0x7c, 0x62, 0xae, 0xf7,
      0x51, 0xf6, 0x70, 0x7c, 0x92, 0xa9, 0xb9, 0x03, 0xa1, 0x98, 0xc5, 0x8d,
      0xc9, 0x7a, 0xa3, 0x66, 0x94, 0x96, 0xca, 0x95, 0x43, 0x51, 0x38, 0x19,
      0x95, 0xe4, 0x42, 0xc9, 0x30, 0xc4, 0x55, 0xa0, 0x5d, 0x6d, 0x4b, 0xe9,
      0x5d, 0x94, 0x63, 0xe2, 0xb1, 0x9e, 0xb4, 0x83, 0x5b, 0x5e, 0xf5, 0x2a,
      0x6a, 0xf0, 0xd2, 0x0e
    },
    {
      0x83, 0xfc, 0x58, 0x0a, 0x84, 0xbe, 0x54, 0xb4, 0xb7, 0x7e, 0xda, 0xb5,
      0x70, 0x88, 0xeb, 0x1c, 0x85, 0x2e, 0xc3, 0x27, 0x4d, 0xec, 0x61, 0xea,
      0xd0, 0xbe, 0x0e, 0xb0, 0xd2, 0xda, 0x6d, 0xdc, 0x97, 0xe2, 0x9d, 0x8a,
      0x75, 0xc0, 0x79, 0xdd, 0xb3, 0x4f, 0x4f, 0xa4, 0xad, 0x53, 0x25, 0xc9
    }
  },
  {
    (UINT8 *) Sample3,
    21,
    {
      0x26, 0xc7, 0x17, 0xc6, 0x48, 0x26,
      0xff, 0x6c, 0x56, 0x34, 0xd9, 0x20,
      0x94, 0xf5, 0x0d, 0xe5
    },
    {
      0x76, 0x8b, 0xb0, 0x05, 0x96, 0xe7,
      0x96, 0x81, 0xb7, 0xf6, 0x5c, 0x70,
      0x88, 0x19, 0x0a, 0xf3, 0xb7, 0x73,
      0x29, 0x67
    },
    {
      0xa6, 0x50, 0x6f, 0x3e, 0xb2, 0x87,
      0x84, 0x1e, 0xfb, 0x63, 0x2f, 0xe0,
      0x1d, 0xe2, 0x35, 0x21, 0xf6, 0xd9,
      0x52, 0x9b, 0xc1, 0x7c, 0xfc, 0x13,
      0x04, 0xb1, 0xa2, 0x99, 0x59, 0x35,
      0x9d, 0xa3
    },
    {
      0x26, 0xdd, 0x63, 0xa6, 0x6f, 0x61, 0xc7, 0x04, 0xff, 0x80, 0x5b, 0x14,
      0x0a, 0x18, 0xab, 0x1f, 0x68, 0x58, 0xeb, 0x30, 0xde, 0x85, 0xe9, 0x85,
      0xa6, 0x64, 0xe9, 0x1e, 0x4c, 0x30, 0xf3, 0xc2, 0x83, 0x0f, 0x23, 0xc1,
      0xd9, 0x3d, 0xd0, 0xd2, 0x06, 0x4a, 0x79, 0x87, 0x59, 0x17, 0x95, 0x10,
      0x72, 0xd2, 0x5a, 0x26, 0xe2, 0xd4, 0xd9, 0x71, 0xb2, 0x1b, 0x33, 0x0d,
      0xcc, 0xf5, 0x88, 0xfa
    },
    {
      0x39, 0x08, 0xc5, 0xac, 0x2f, 0x18, 0x45, 0xe0, 0xf1, 0x1b, 0xb9, 0x50,
      0x4b, 0x44, 0xa6, 0x42, 0x60, 0x99, 0xe7, 0x31, 0xa2, 0xf0, 0x0e, 0x4a,
      0x78, 0xd3, 0xba, 0xa2, 0x40, 0x2e, 0x9e, 0x74, 0x5d, 0xee, 0x9c, 0xd6,
      0x82, 0x72, 0x5f, 0xbb, 0xfc, 0x72, 0x0f, 0x29, 0x91, 0x66, 0xa1, 0x49
    }
  },
  {
    (UINT8 *) Sample4,
    67,
    {
      0x3a, 0x60, 0x2a, 0x62, 0x6f, 0xd8,
      0x6e, 0xbc, 0xa8, 0x6c, 0xdf, 0x31,
      0x09, 0x45, 0x93, 0x19
    },
    {
      0x1f, 0xb6, 0xc8, 0x1a, 0x2b, 0xb4,
      0x07, 0x21, 0x3d, 0x1a, 0x30, 0x21,
      0x26, 0x7a, 0xb2, 0xe1, 0x5e, 0x63,
      0x07, 0x0d
    },
    {
      0xe4, 0xcf, 0x51, 0x6e, 0x7a, 0x3f,
      0xcb, 0x1f, 0x5b, 0x58, 0xf5, 0xff,
      0xc0, 0xd4, 0x0d, 0x18, 0x2e, 0x79,
      0xda, 0xb9, 0x9c, 0x87, 0x6d, 0x9f,
      0xe3, 0xc5, 0x92, 0x1d, 0x29, 0xbb,
      0x4d, 0x7e
    },
    {
      0x43, 0x49, 0xc0, 0xad, 0x5e, 0x82, 0xa1, 0xb1, 0x8b, 0x5e, 0x25, 0x60,
      0xba, 0xf0, 0x9d, 0x43, 0x33, 0xf1, 0xe2, 0xb0, 0x89, 0xec, 0x00, 0x08,
      0x94, 0x95, 0xb2, 0x49, 0x88, 0x14, 0x24, 0x90, 0x77, 0xc9, 0x0a, 0x37,
      0x0e, 0xab, 0x1b, 0x45, 0x3e, 0x41, 0x38, 0xa5, 0x2e, 0x23, 0x84, 0xfc,
      0x80, 0xc8, 0xc0, 0xfd, 0xd8, 0x58, 0xb6, 0xb6, 0x03, 0xb9, 0xbd, 0x60,
      0x86, 0xf9, 0x96, 0xf5
    },
    {
      0xe6, 0xf8, 0xea, 0x46, 0x17, 0xf1, 0x6d, 0x2f, 0xa2, 0x59, 0x83, 0x01,
      0x28, 0x9f, 0xc3, 0xf4, 0x36, 0xd6, 0x6d, 0x7c, 0xc7, 0x3b, 0xfe, 0xf1,
      0xfd, 0x02, 0x13, 0x8a, 0x56, 0xaa, 0x46, 0xdc, 0x07, 0x09, 0xe6, 0x6a,
      0x9d, 0xdd, 0xe2, 0x8d, 0xb1, 0xa7, 0x00, 0x5a, 0x99, 0x08, 0xd1, 0xe0
    }
  }
};
