#pragma once

#include "cm2/api.hpp"
#include "faktum/ui/canvaspanel.hpp"


class CM2Mode;

class CM2CanvasPanel : public FCanvasPanel { // TODO Members

public:

	CM2CanvasPanel(const CM2CanvasPanel& other);
	CM2CanvasPanel(CM2Mode* mode);

	~CM2CanvasPanel() override;

	CM2CanvasPanel& operator=(const CM2CanvasPanel& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	virtual void Enter();
	virtual void Leave();
	virtual void ResolutionChanged(const FMatrix4&, int);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned char unk25C[0x8];

protected:

	CM2CanvasPanel();

	virtual void OnLeft();

private:

	void InitButtonMenuStyle();

	static FClass* StaticConstructClassCM2CanvasPanel();
	static void StaticInitClassCM2CanvasPanel();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2CanvasPanel, 0x264);
