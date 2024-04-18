#pragma once

#include "cm2/api.hpp"
#include "faktum/ui/window.hpp"


class CM2Dialog : public FWindow {

public:

	struct ClickEventArgs {};


	CM2Dialog(const CM2Dialog& other);
	CM2Dialog(CM2Mode* mode);

	~CM2Dialog() override;

	CM2Dialog& operator=(const CM2Dialog& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Render(FCanvas* canvas) override;
	void OnSetVisibility(VisibilityEventArgs* args) override;
	virtual void OnClick(ClickEventArgs* args);

	void CenterWindow();
	void GetButtonPositioning(float*, unsigned int);
	CM2Mode* GetMode() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

	CM2_API static int EventIDClick;


	unsigned char unk2A0[0x20];

private:

	static FClass* StaticConstructClassCM2Dialog();
	static void StaticInitClassCM2Dialog();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2Dialog, 0x2C4);
