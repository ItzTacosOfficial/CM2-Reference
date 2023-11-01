#pragma once

#include "core.hpp"


class FString;

FAK_IMPORT unsigned long FtChecksumCRC32(void* data, unsigned int size);
FAK_IMPORT int FtChecksumMD5A(char*, int, void*, unsigned int);
FAK_IMPORT FString FtChecksumMD5W(void*, unsigned int);
FAK_IMPORT int FtChecksumMD5W(wchar_t*, int, void*, unsigned int);
FAK_IMPORT int FtChecksumMD5W(wchar_t*, int, const wchar_t*);
FAK_IMPORT void FtChecksumMD5W(unsigned char* const, void*, unsigned int);
