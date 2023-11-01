#pragma once

#include "core.hpp"
#include "resource.hpp"


class FAK_IMPORT FSample : public FResource {

public:

	enum FORMAT {
		None = 1,
		Raw = 2,
		Ogg = 3
	};


	FSample();
	FSample(const FSample& other);

	~FSample() override;

	FSample& operator=(const FSample& other);

	static void* __cdecl operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

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

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	unsigned int channelsCount;
	unsigned int frequency;
	unsigned int bitsPerSample;
	FORMAT format;
	unsigned int dataSize;
	unsigned int pcmSize;
	void* data;

private:

	static FClass* __cdecl StaticConstructClassFSample();
	static void __cdecl StaticInitClassFSample();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FSample, 0x50);
