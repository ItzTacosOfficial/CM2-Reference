#pragma once

#include "faktum/api.hpp"
#include "uielement.hpp"



class FBrush;
class FFont;
class FVector4;

class FControl : public FUIElement {

public:

	FControl(const FControl& other);
	FControl(FUIContext* context);

	~FControl() override;

	FControl& operator=(const FControl& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void PropertyChanged(FProperty* property) override;
	void Render(FCanvas* canvas) override;
	void Serialize(FArchive& archive) override;

	FBrush* GetBackgroundBrush() const;
	FFont* GetFont() const;
	FRect GetPadding() const;
	FVector4 GetTextColor() const;
	unsigned int GetTextFormat() const;
	FUIElement* GetToolTip() const;
	void SetBackgroundBrush(FBrush* brush);
	void SetFont(FFont* font);
	void SetPadding(const FRect& padding);
	void SetTextColor(const FVector4& color);
	void SetTextFormat(unsigned int format);
	void SetToolTip(FUIElement* toolTip);

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();

	FAK_API static int EventIDSetFont;


	unsigned char unk230[0x40];

protected:

	void OnMouseEnter(MouseEventArgs* args) override;
	void OnMouseLeave(MouseEventArgs* args) override;
	void OnSetVisibility(VisibilityEventArgs* args) override;
	virtual void OnSetFont(EventArgs* args);

private:

	static FClass* StaticConstructClassFControl();
	static void StaticInitClassFControl();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FControl, 0x274);
