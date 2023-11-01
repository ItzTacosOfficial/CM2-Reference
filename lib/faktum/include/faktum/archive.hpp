#pragma once

#include "core.hpp"


class FName;
class FObject;
class FString;

class FAK_IMPORT FArchive {

public:

	enum FAK_ASSUMED FLAG {
		LOADING		= 0x1,
		STORING		= 0x2,
		PERSISTENT	= 0x4,
		UNK8		= 0x8,
	};


	FArchive(const FArchive& other);
	
	FArchive& operator=(const FArchive& other);

	virtual BOOL Close() = 0;
	virtual unsigned int Read(void* dest, unsigned int size) = 0;
	virtual unsigned int Write(const void* src, unsigned int size) = 0;
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
	void ReadByteOrder(void* dest, unsigned int size);
	void WriteByteOrder(const void* src, unsigned int size);


	unsigned int archiveFlags;

protected:

	FArchive(unsigned int flags);

};
FAK_SIZE_GUARD(FArchive, 0x8);


FAK_IMPORT FArchive& operator>>(FArchive& archive, FString& string);
FAK_IMPORT FArchive& operator<<(FArchive& archive, FString& string);
