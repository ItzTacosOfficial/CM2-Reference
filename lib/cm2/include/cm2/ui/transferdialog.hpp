#pragma once

#include "cm2/api.hpp"
#include "dialog.hpp"


class CM2Button;

class CM2TransferDialog : public CM2Dialog {

public:

	CM2TransferDialog(const CM2TransferDialog& other);
	CM2TransferDialog(CM2Mode* mode, unsigned int);

	~CM2TransferDialog() override;

	CM2TransferDialog& operator=(const CM2TransferDialog& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	CM2Button* GetButton();
	void Reset(int);
	void SetBarPercentValue(float value);
	void SetMode(int mode);
	void SetType(unsigned int type);
	void ShowMessage(unsigned long id);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

	CM2_API static int EventIDCancel;
	CM2_API static int EventIDOk;


	unsigned char unk2C4[0x48];

protected:

	CM2TransferDialog();

	void CancelButtonClick(FObject* object, EventArgs* args);
	void InitButtons();
	void InitPanel(CM2Mode* mode);
	void OKButtonClick(FObject* object, EventArgs* args);

private:

	static FClass* StaticConstructClassCM2TransferDialog();
	static void StaticInitClassCM2TransferDialog();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2TransferDialog, 0x30C);
