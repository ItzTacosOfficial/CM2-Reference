#pragma once

#include "faktum/api.hpp"


class FString;

FAK_API unsigned long FtChecksumCRC32(void* data, unsigned int size);
FAK_API int FtChecksumMD5A(char*, int, void*, unsigned int);
FAK_API FString FtChecksumMD5W(void*, unsigned int);
FAK_API int FtChecksumMD5W(wchar_t*, int, void*, unsigned int);
FAK_API int FtChecksumMD5W(wchar_t*, int, const wchar_t*);
FAK_API void FtChecksumMD5W(unsigned char* const, void*, unsigned int);
