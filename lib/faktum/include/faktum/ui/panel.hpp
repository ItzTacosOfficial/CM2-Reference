#pragma once

#include "faktum/api.hpp"
#include "uielement.hpp"


class FBrush;

class FAK_API FPanel : public FUIElement { // TODO Members

public:

	FPanel(const FPanel& other);
	FPanel(FUIContext* context);

	~FPanel() override;

	FPanel& operator=(const FPanel& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void Serialize(FArchive& archive) override;
	void Render(FCanvas* canvas) override;
	BOOL AddChild(FUIElement* child) override;
	BOOL RemoveChild(FUIElement* child) override;
	void RemoveAllChildren() override;
	virtual FUIElement* GetChild(int id);

	void SetBackgroundBrush(FBrush* brush);

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	unsigned char unk234[0x8];

private:

	static FClass* StaticConstructClassFPanel();
	static void StaticInitClassFPanel();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FPanel, 0x23C);
