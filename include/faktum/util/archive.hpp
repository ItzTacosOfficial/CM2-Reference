#pragma once

#include "faktum/api.hpp"

#include <concepts>



class FName;
class FObject;
class FString;


class FArchive {

public:

	enum FLAG {
		ARC_LOADING			= 0x1,
		ARC_STORING			= 0x2,
		ARC_PERSISTENT		= 0x4,
		ARC_LITTLEENDIAN	= 0x8,
	};


	FArchive(const FArchive& other);
	
	FArchive& operator=(const FArchive& other);

	virtual BOOL Close() = 0;
	virtual size_t Read(void* dest, size_t size) = 0;
	virtual size_t Write(const void* src, size_t size) = 0;
	virtual void Flush() = 0;
	virtual int Tell();
	virtual void Seek(int pos);
	virtual int Size();
	virtual BOOL End();
	virtual void ReadName(FName& name);
	virtual void WriteName(const FName& name);
	virtual FObject* ReadObject();
	virtual void WriteObject(const FObject* object);

	BOOL IsLoading() const;
	BOOL IsPersistent() const;
	BOOL IsStoring() const;
	void ReadByteOrder(void* dest, size_t size);
	void WriteByteOrder(const void* src, size_t size);


	unsigned int archiveFlags;

protected:

	FArchive(unsigned int flags);

};
FAK_SIZE_GUARD(FArchive, 0x8);


FAK_API FArchive& operator>>(FArchive& archive, FString& string);
FAK_API FArchive& operator<<(FArchive& archive, FString& string);

template<class A> requires std::is_arithmetic_v<A>
FAK_EXTENSION inline FArchive& operator>>(FArchive& archive, A& a) {
	archive.ReadByteOrder(&a, sizeof(A));
	return archive;
}

template<class A> requires std::is_arithmetic_v<A>
FAK_EXTENSION inline FArchive& operator<<(FArchive& archive, const A& a) {
	archive.WriteByteOrder(&a, sizeof(A));
	return archive;
}

FAK_EXTENSION inline FArchive& operator<<(FArchive& archive, const char* str) {
	archive.WriteByteOrder(str, strlen(str));
	return archive;
}

FAK_EXTENSION inline FArchive& operator<<(FArchive& archive, const wchar_t* str) {
	archive.WriteByteOrder(str, wcslen(str));
	return archive;
}
