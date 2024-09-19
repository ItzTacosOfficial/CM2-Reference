#pragma once

#include "faktum/api.hpp"
#include "keycontroller.hpp"



class FVector3Controller : public FKeyController {

public:

	FVector3Controller();
	FVector3Controller(const FVector3Controller& other);

	~FVector3Controller() override;

	FVector3Controller& operator=(const FVector3Controller& other);

	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Serialize(FArchive& archive) override;
	void GetValue(float, void*) override;
	int GetCurveCount() override;
	CURVE GetCurveDesc(int) override;
	float GetCurveValue(int, float) override;
	int GetKeyCount() const override;
	Key* GetKey(int) const override;
	int InsertKey(float) override;
	void DeleteKey(int) override;
	void SortKeys() override;
	void SetKeyCurveValue(int, int, float) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFVector3Controller();
	static void StaticInitClassFVector3Controller();

	FAK_API static FClass* ms_pClass;

};
//FAK_SIZE_GUARD(FVector3Controller, );
