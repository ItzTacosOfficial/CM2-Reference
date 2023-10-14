#pragma once

#include "core.hpp"
#include "object.hpp"
#include "zlib.h"


class FAK_IMPORT FCodec : public FObject {

public:

	enum TYPE {
		Encode = 1,
		Decode,
	};


	FCodec();
	FCodec(const FCodec& other);

	~FCodec() override;

	FCodec& operator=(const FCodec& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	virtual int Begin(TYPE type, unsigned int bufferSize);
	virtual void End();
	virtual unsigned int ProcessBuffer(void* data, unsigned int size) = 0;

	unsigned char* GetBuffer() const;
	unsigned int GetBufferLength() const;
	unsigned int GetBufferSize() const;
	TYPE GetType() const;
	void ResetBuffer();

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	TYPE type;
	unsigned char* buffer;
	unsigned int bufferLength;
	unsigned int bufferSize;

private:

	static FClass* __cdecl StaticConstructClassFCodec();
	static void __cdecl StaticInitClassFCodec();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCodec, 0x38);

class FAK_IMPORT FCodecRaw : public FCodec {

public:

	FCodecRaw();
	FCodecRaw(const FCodecRaw& other);

	~FCodecRaw() override;

	FCodecRaw& operator=(const FCodecRaw& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	unsigned int ProcessBuffer(void* data, unsigned int size) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFCodecRaw();
	static void __cdecl StaticInitClassFCodecRaw();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCodecRaw, 0x38);

class FAK_IMPORT FCodecZip : public FCodec {

public:

	FCodecZip();
	FCodecZip(const FCodecZip& other);

	~FCodecZip() override;

	FCodecZip& operator=(const FCodecZip& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	int Begin(TYPE type, unsigned int bufferSize) override;
	void End() override;
	unsigned int ProcessBuffer(void* data, unsigned int size) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	z_streamp stream;
	int zlibResult;

private:

	static FClass* __cdecl StaticConstructClassFCodecZip();
	static void __cdecl StaticInitClassFCodecZip();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCodecZip, 0x40);
