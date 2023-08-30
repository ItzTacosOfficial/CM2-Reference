#pragma once

#include "core.hpp"


class FName;
class FObject;
class FString;

class FAK_IMPORT FArchive {

public:

	enum FAK_ASSUMED FLAG {
		Loading		= 0x1,
		Storing		= 0x2,
		Persistent	= 0x4,
		Unknown8	= 0x8,
	};


	FArchive(const FArchive& other);
	
	FArchive& operator=(const FArchive& other);

	virtual int Close() = 0;
	virtual unsigned int Read(void*, unsigned int) = 0;
	virtual unsigned int Write(const void*, unsigned int) = 0;
	virtual void Flush() = 0;
	virtual int Tell();
	virtual void Seek(int pos);
	virtual int Size();
	virtual int End();
	virtual void ReadName(FName& name);
	virtual void WriteName(const FName& name);
	virtual FObject* ReadObject();
	virtual void WriteObject(const FObject* object);

	BOOL IsLoading() const;
	BOOL IsPersistent() const;
	BOOL IsStoring() const;
	void ReadByteOrder(void*, unsigned int);
	void WriteByteOrder(const void*, unsigned int);


	FLAG arcFlags;

protected:

	FArchive(unsigned int);

};
FAK_SIZE_GUARD(FArchive, 0x8);


FAK_IMPORT FArchive& __cdecl operator>>(FArchive& arc, FString& string);
FAK_IMPORT FArchive& __cdecl operator<<(FArchive& arc, FString& string);
