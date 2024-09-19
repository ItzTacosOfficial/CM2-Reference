#pragma once

#include "faktum/api.hpp"
#include "resource.hpp"



class FSample : public FResource {

public:

	enum FORMAT {
		FMT_NONE = 1,
		FMT_RAW,
		FMT_OGG
	};


	FSample();
	FSample(const FSample& other);

	~FSample() override;

	FSample& operator=(const FSample& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Serialize(FArchive& archive) override;

	void Exit();
	unsigned int GetBitsPerSample();
	unsigned int GetChannels();
	void* GetData();
	unsigned int GetDataSize();
	FORMAT GetFormat();
	unsigned int GetFrequency();
	unsigned int GetPCMSize();
	BOOL Init(FORMAT format, unsigned int channels, unsigned int bitsPerSample, unsigned int frequency, unsigned int pcmSize, unsigned int dataSize, const void* data);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned int channels;
	unsigned int frequency;
	unsigned int bitsPerSample;
	FORMAT format;
	unsigned int dataSize;
	unsigned int pcmSize;
	void* data;

private:

	static FClass* StaticConstructClassFSample();
	static void StaticInitClassFSample();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FSample, 0x50);
