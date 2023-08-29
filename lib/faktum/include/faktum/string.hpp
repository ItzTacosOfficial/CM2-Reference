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
	int CountChars(wchar_t c, unsigned int) const;
	unsigned int Delete(unsigned int, unsigned int);
	void Empty();
	int Find(const wchar_t*) const;
	int Find(const wchar_t*, unsigned int) const;
	int Find(wchar_t) const;
	int Find(wchar_t, unsigned int) const;
	int FindOneOf(const wchar_t*) const;
	void __cdecl Format(const wchar_t*, ...);
	void FormatV(const wchar_t*, char*);
	wchar_t& GetAt(unsigned int) const;
	wchar_t* GetBuffer(unsigned int);
	unsigned int GetBufferLength() const;
	unsigned int GetLength() const;
	unsigned int Insert(unsigned int, const wchar_t*);
	unsigned int Insert(unsigned int, wchar_t);
	BOOL IsEmpty() const;
	void LastErrorWin32();
	FString Left(unsigned int) const;
	BOOL Load(const wchar_t* str, ENCODING encoding);
	FString Mid(unsigned int, unsigned int) const;
	unsigned int Remove(wchar_t);
	unsigned int Replace(const wchar_t*, const wchar_t*);
	unsigned int Replace(wchar_t, wchar_t);
	void Reverse();
	int ReverseFind(const wchar_t*) const;
	int ReverseFind(const wchar_t*, unsigned int) const;
	int ReverseFind(wchar_t) const;
	int ReverseFind(wchar_t, unsigned int) const;
	FString Right(unsigned int) const;
	BOOL Save(const wchar_t* str, ENCODING encoding);
	void SetAt(unsigned int, wchar_t);
	void Shrink();
	void ToLowerCase();
	void ToUpperCase();
	FString& Trim(const wchar_t*);
	FString& Trim();
	FString& Trim(wchar_t);
	FString& TrimLeft(const wchar_t*);
	FString& TrimLeft();
	FString& TrimLeft(wchar_t);
	FString& TrimRight(const wchar_t*);
	FString& TrimRight();
	FString& TrimRight(wchar_t);
	void Truncate(unsigned int);
	

	wchar_t* data;
	int allocatedSize;

private:

	void Concat(unsigned int, const wchar_t*);
	void ConcatCopy(unsigned int, const wchar_t*, unsigned int, const wchar_t*);

};
FAK_SIZE_GUARD(FString, 0x8);