#pragma once

#include "faktum/api.hpp"
#include "controller.hpp"



class FKeyController : public FController {

public:

	struct Key {

	};
	//FAK_SIZE_GUARD(Key, );


	FKeyController();
	FKeyController(const FKeyController& other);

	~FKeyController() override;

	FKeyController& operator=(const FKeyController& other);

	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Serialize(FArchive& archive) override;
	virtual int GetKeyCount() const = 0;
	virtual Key* GetKey(int index) const = 0;
	virtual int InsertKey(float) = 0;
	virtual void DeleteKey(int) = 0;
	virtual void SortKeys(void) = 0;
	virtual void SetKeyCurveValue(int, int, float) = 0;

	Key* FindKey(float);

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	unsigned int unk24[3];

protected:

	static int StaticCompareKeys(const Key* a, const Key* b, void* param);

private:

	static FClass* StaticConstructClassFKeyController();
	static void StaticInitClassFKeyController();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FKeyController, 0x34);
