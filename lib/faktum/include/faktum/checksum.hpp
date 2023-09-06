#pragma once

#include "core.hpp"


class FString;

FAK_IMPORT unsigned long __cdecl FtChecksumCRC32(void*, unsigned int);
FAK_IMPORT int __cdecl FtChecksumMD5A(char*, int, void*, unsigned int);
FAK_IMPORT FString __cdecl FtChecksumMD5W(void*, unsigned int);
FAK_IMPORT int __cdecl FtChecksumMD5W(wchar_t*, int, void*, unsigned int);
FAK_IMPORT int __cdecl FtChecksumMD5W(wchar_t*, int, const wchar_t*);
FAK_IMPORT void __cdecl FtChecksumMD5W(unsigned char* const, void*, unsigned int);
