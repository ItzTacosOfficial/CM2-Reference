#pragma once

#include "core.hpp"


enum ENCODING {}; // TODO Contents

class FAK_IMPORT FString {

public:

	FString();
	FString(const FString& other);
	FString(unsigned int size, const wchar_t* data);
	FString(const wchar_t* str);
	FString(wchar_t c, unsigned int count);

	~FString();

	const FString& operator=(const FString& other);
	const FString& operator=(const wchar_t* str);
	const FString& operator=(wchar_t c);
	wchar_t& operator[](int index) const;
	wchar_t& operator[](unsigned int index) const;
	operator wchar_t*();
	operator int() const;
	operator float() const;
	operator const wchar_t*() const;
	const FString& operator+=(const FString& str);
	const FString& operator+=(const wchar_t* str);
	const FString& operator+=(wchar_t c);

	BOOL Compare(const wchar_t* str);
	BOOL CompareNoCase(const wchar_t* str);
	int CountChars(wchar_t c, unsigned int pos) const;
	unsigned int Delete(unsigned int pos, unsigned int count);
	void Empty();
	int Find(const wchar_t* str) const;
	int Find(const wchar_t* str, unsigned int ofs) const;
	int Find(wchar_t c) const;
	int Find(wchar_t c, unsigned int pos) const;
	int FindOneOf(const wchar_t* str) const;
	void __cdecl Format(const wchar_t* str, ...);
	void FormatV(const wchar_t* str, va_list va);
	wchar_t& GetAt(unsigned int index) const;
	wchar_t* GetBuffer(unsigned int size);
	unsigned int GetBufferLength() const;
	unsigned int GetLength() const;
	unsigned int Insert(unsigned int pos, const wchar_t* str);
	unsigned int Insert(unsigned int pos, wchar_t c);
	BOOL IsEmpty() const;
	void LastErrorWin32();
	FString Left(unsigned int pos) const;
	BOOL Load(const wchar_t* path, ENCODING encoding);
	FString Mid(unsigned int pos, unsigned int count) const;
	unsigned int Remove(wchar_t c);
	unsigned int Replace(const wchar_t* a, const wchar_t* b);
	unsigned int Replace(wchar_t a, wchar_t b);
	void Reverse();
	int ReverseFind(const wchar_t* str) const;
	int ReverseFind(const wchar_t* str, unsigned int pos) const;
	int ReverseFind(wchar_t c) const;
	int ReverseFind(wchar_t c, unsigned int pos) const;
	FString Right(unsigned int pos) const;
	BOOL Save(const wchar_t* path, ENCODING encoding);
	void SetAt(unsigned int index, wchar_t c);
	void Shrink();
	void ToLowerCase();
	void ToUpperCase();
	FString& Trim(const wchar_t* str);
	FString& Trim();
	FString& Trim(wchar_t c);
	FString& TrimLeft(const wchar_t* str);
	FString& TrimLeft();
	FString& TrimLeft(wchar_t c);
	FString& TrimRight(const wchar_t* str);
	FString& TrimRight();
	FString& TrimRight(wchar_t c);
	void Truncate(unsigned int pos);
	

	wchar_t* buffer;
	int bufferLength;

private:

	void Concat(unsigned int length, const wchar_t* str);
	void ConcatCopy(unsigned int length0, const wchar_t* str0, unsigned int length1, const wchar_t* str1);

};
FAK_SIZE_GUARD(FString, 0x8);


FAK_IMPORT char* __cdecl FtIToStrA(int, char*, int);
FAK_IMPORT wchar_t* __cdecl FtIToStrW(int, wchar_t*, int);
FAK_IMPORT unsigned int __cdecl FtStrAnsiToGeneric(wchar_t*, const char*, unsigned int);
FAK_IMPORT unsigned int __cdecl FtStrAnsiToWide(wchar_t*, const char*, unsigned int);
FAK_IMPORT unsigned int __cdecl FtStrGenericToAnsi(char*, const wchar_t*, unsigned int);
FAK_IMPORT unsigned int __cdecl FtStrGenericToWide(wchar_t*, const wchar_t*, unsigned int);
FAK_IMPORT unsigned int __cdecl FtStrHash(const char* str);
FAK_IMPORT unsigned int __cdecl FtStrHash(const wchar_t* str);
FAK_IMPORT BOOL __cdecl FtStrICmpA(const char*, const char*);
FAK_IMPORT BOOL __cdecl FtStrICmpW(const wchar_t*, const wchar_t*);
FAK_IMPORT BOOL __cdecl FtStrNICmpA(const char*, const char*, unsigned int);
FAK_IMPORT BOOL __cdecl FtStrNICmpW(const wchar_t*, const wchar_t*, unsigned int);
FAK_IMPORT unsigned int __cdecl FtStrPrintFCVA(const char*, char*);
FAK_IMPORT unsigned int __cdecl FtStrPrintFCVW(const wchar_t*, char*);
FAK_IMPORT const char* __cdecl FtStrRChrA(const char*, int, int);
FAK_IMPORT const wchar_t* __cdecl FtStrRChrW(const wchar_t*, int, int);
FAK_IMPORT const char* __cdecl FtStrRStrA(const char*, const char*, unsigned int);
FAK_IMPORT const wchar_t* __cdecl FtStrRStrW(const wchar_t*, const wchar_t*, unsigned int);
FAK_IMPORT float __cdecl FtStrToFA(const char*);
FAK_IMPORT float __cdecl FtStrToFW(const wchar_t*);
FAK_IMPORT BOOL __cdecl FtStrToIA(const char*);
FAK_IMPORT BOOL __cdecl FtStrToIA(const char*, int);
FAK_IMPORT BOOL __cdecl FtStrToIW(const wchar_t*);
FAK_IMPORT BOOL __cdecl FtStrToIW(const wchar_t*, int);
FAK_IMPORT unsigned int __cdecl FtStrToUIA(const char*, int);
FAK_IMPORT unsigned int __cdecl FtStrToUIW(const wchar_t*, int);
FAK_IMPORT unsigned int __cdecl FtStrWideToAnsi(char*, const wchar_t*, unsigned int);
FAK_IMPORT unsigned int __cdecl FtStrWideToGeneric(wchar_t*, const wchar_t*, unsigned int);
FAK_IMPORT char* __cdecl FtUIToStrA(unsigned int, char*, int);
FAK_IMPORT wchar_t* __cdecl FtUIToStrW(unsigned int, wchar_t*, int);

FAK_IMPORT void __cdecl _FtXToStr(unsigned int, char*, unsigned int, int);
