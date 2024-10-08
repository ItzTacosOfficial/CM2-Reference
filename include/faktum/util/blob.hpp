#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"



class FBlob : public FObject {

public:

	FBlob();
	FBlob(const FBlob& other);
	FBlob(unsigned int size);
	FBlob(const void* data, unsigned int size);

	~FBlob() override;

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	FBlob& operator=(const FBlob& other);

	void Serialize(FArchive& archive) override;

	void* GetData() const;
	unsigned int GetSize() const;
	BOOL Save(const wchar_t* path);
	void SetSize(unsigned int size);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	unsigned int size;
	void* data;

private:

	static FClass* StaticConstructClassFBlob();
	static void StaticInitClassFBlob();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FBlob, 0x30);
