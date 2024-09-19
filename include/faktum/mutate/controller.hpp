#pragma once

#include "faktum/api.hpp"
#include "mutator.hpp"



class FController : public FMutator {

public:

	enum CURVE {};


	FController();
	FController(const FController& other);

	~FController() override;

	FController& operator=(const FController& other);

	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	BOOL Mutate(FObject*, FProperty*, float) override;
	virtual BOOL IsCompatible(FProperty* property);
	virtual void GetValue(float, void*) = 0;
	virtual void SetValue(float, void*);
	virtual int GetCurveCount();
	virtual CURVE GetCurveDesc(int);
	virtual float GetCurveValue(int, float);

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFController();
	static void StaticInitClassFController();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FController, 0x28);
