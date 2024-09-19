#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"

#if __has_include(<zlib.h>)
	#include <zlib.h>
#else
	using z_streamp = void*;
#endif



class FCodec : public FObject {

public:

	enum TYPE {
		TYPE_ENCODE = 1,
		TYPE_DECODE,
	};


	FCodec();
	FCodec(const FCodec& other);

	~FCodec() override;

	FCodec& operator=(const FCodec& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	virtual BOOL Begin(TYPE type, unsigned int bufferSize);
	virtual void End();
	virtual unsigned int ProcessBuffer(void* data, unsigned int size) = 0;

	unsigned char* GetBuffer() const;
	unsigned int GetBufferLength() const;
	unsigned int GetBufferSize() const;
	TYPE GetType() const;
	void ResetBuffer();

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	TYPE type;
	unsigned char* buffer;
	unsigned int bufferLength;
	unsigned int bufferSize;

private:

	static FClass* StaticConstructClassFCodec();
	static void StaticInitClassFCodec();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCodec, 0x38);


class FCodecRaw : public FCodec {

public:

	FCodecRaw();
	FCodecRaw(const FCodecRaw& other);

	~FCodecRaw() override;

	FCodecRaw& operator=(const FCodecRaw& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	unsigned int ProcessBuffer(void* data, unsigned int size) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFCodecRaw();
	static void StaticInitClassFCodecRaw();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCodecRaw, 0x38);


class FCodecZip : public FCodec {

public:

	FCodecZip();
	FCodecZip(const FCodecZip& other);

	~FCodecZip() override;

	FCodecZip& operator=(const FCodecZip& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	BOOL Begin(TYPE type, unsigned int bufferSize) override;
	void End() override;
	unsigned int ProcessBuffer(void* data, unsigned int size) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	z_streamp stream;
	int zlibResult;

private:

	static FClass* StaticConstructClassFCodecZip();
	static void StaticInitClassFCodecZip();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCodecZip, 0x40);
