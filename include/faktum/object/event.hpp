#pragma once

#include "faktum/api.hpp"
#include "field.hpp"



class FEvent : public FField {

public:

	FEvent(const FEvent& other);
	FEvent(unsigned int objectSize, ROUTING routing);

	~FEvent() override;

	FEvent& operator=(const FEvent& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	ROUTING GetRouting() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned int unk2C;
	unsigned int objectSize;
	ROUTING routing;

protected:

	FEvent();

private:

	static FClass* StaticConstructClassFEvent();
	static void StaticInitClassFEvent();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FEvent, 0x38);
