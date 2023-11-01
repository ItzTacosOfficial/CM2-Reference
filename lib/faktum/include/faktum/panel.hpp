#pragma once

#include "core.hpp"
#include "uielement.hpp"


class FBrush;

class FAK_IMPORT FPanel : public FUIElement { // TODO Members

public:

	FPanel(const FPanel& other);
	FPanel(FUIContext* context);

	~FPanel() override;

	FPanel& operator=(const FPanel& other);

	static void* __cdecl operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void Serialize(FArchive& archive) override;
	void Render(FCanvas* canvas) override;
	BOOL AddChild(FUIElement* child) override;
	BOOL RemoveChild(FUIElement* child) override;
	void RemoveAllChildren() override;
	virtual FUIElement* GetChild(int id);

	void SetBackgroundBrush(FBrush* brush);

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticInitClass();
	static void __cdecl StaticUnregisterClass();


	unsigned char unk234[0x8];

private:

	static FClass* __cdecl StaticConstructClassFPanel();
	static void __cdecl StaticInitClassFPanel();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FPanel, 0x23C);
