#pragma once

#include "core.hpp"
#include "faktum/canvaspanel.hpp"


class CM2Mode;

class CM2_IMPORT CM2CanvasPanel : public FCanvasPanel { // TODO Members

public:

	CM2CanvasPanel(const CM2CanvasPanel& other);
	CM2CanvasPanel(CM2Mode* mode);

	~CM2CanvasPanel() override;

	CM2CanvasPanel& operator=(const CM2CanvasPanel& other);

	static void* __cdecl operator new(unsigned int, FObject*, const FName&, const FName&, unsigned int);

	virtual void Enter();
	virtual void Leave();
	virtual void ResolutionChanged(const FMatrix4&, int);

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	unsigned char unk25C[0x8];

protected:

	CM2CanvasPanel();

	virtual void OnLeft();

private:

	void InitButtonMenuStyle();

	static FClass* __cdecl StaticConstructClassCM2CanvasPanel();
	static void __cdecl StaticInitClassCM2CanvasPanel();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(CM2CanvasPanel, 0x264);
