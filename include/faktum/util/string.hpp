#pragma once

#include "faktum/api.hpp"



enum ENCODING {};


class FString {

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
	int Find(const wchar_t* str, unsigned int pos) const;
	int Find(wchar_t c) const;
	int Find(wchar_t c, unsigned int pos) const;
	int FindOneOf(const wchar_t* str) const;
	void Format(const wchar_t* str, ...);
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


FAK_API char* FtIToStrA(int number, char* str, int base);
FAK_API wchar_t* FtIToStrW(int number, wchar_t* str, int base);
FAK_API unsigned int FtStrAnsiToGeneric(wchar_t* dest, const char* src, unsigned int count);
FAK_API unsigned int FtStrAnsiToWide(wchar_t* dest, const char* src, unsigned int count);
FAK_API unsigned int FtStrGenericToAnsi(char* dest, const wchar_t* src, unsigned int count);
FAK_API unsigned int FtStrGenericToWide(wchar_t* dest, const wchar_t* src, unsigned int count);
FAK_API unsigned int FtStrHash(const char* str);
FAK_API unsigned int FtStrHash(const wchar_t* str);
FAK_API BOOL FtStrICmpA(const char* a, const char* b);
FAK_API BOOL FtStrICmpW(const wchar_t* a, const wchar_t* b);
FAK_API BOOL FtStrNICmpA(const char* a, const char* b, unsigned int count);
FAK_API BOOL FtStrNICmpW(const wchar_t* a, const wchar_t* b, unsigned int count);
FAK_API unsigned int FtStrPrintFCVA(const char* str, va_list args);
FAK_API unsigned int FtStrPrintFCVW(const wchar_t* str, va_list args);
FAK_API const char* FtStrRChrA(const char* str, int c, int pos = -1);
FAK_API const wchar_t* FtStrRChrW(const wchar_t* str, int c, int pos = -1);
FAK_API const char* FtStrRStrA(const char* a, const char* b, unsigned int pos = -1);
FAK_API const wchar_t* FtStrRStrW(const wchar_t* a, const wchar_t* b, unsigned int pos = -1);
FAK_API float FtStrToFA(const char* str);
FAK_API float FtStrToFW(const wchar_t* str);
FAK_API int FtStrToIA(const char* str);
FAK_API int FtStrToIA(const char* str, int base);
FAK_API int FtStrToIW(const wchar_t* str);
FAK_API int FtStrToIW(const wchar_t* str, int base);
FAK_API unsigned int FtStrToUIA(const char* str, int base);
FAK_API unsigned int FtStrToUIW(const wchar_t* str, int base);
FAK_API unsigned int FtStrWideToAnsi(char* dest, const wchar_t* src, unsigned int count);
FAK_API unsigned int FtStrWideToGeneric(wchar_t* dest, const wchar_t* src, unsigned int count);
FAK_API char* FtUIToStrA(unsigned int number, char* str, int base);
FAK_API wchar_t* FtUIToStrW(unsigned int number, wchar_t* str, int base);

FAK_API void _FtXToStr(unsigned int number, char* str, unsigned int base, BOOL negative);
