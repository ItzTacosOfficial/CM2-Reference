#pragma once

#include "faktum/api.hpp"
#include "control.hpp"


class FLabel;

class FWindow : public FControl {

public:

	FWindow(const FWindow& other);
	FWindow(FUIContext* context);

	~FWindow() override;

	FWindow& operator=(const FWindow& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Serialize(FArchive& archive) override;

	FObject* GetCaption() const;
	FLabel* GetCaptionLabel() const;
	FUIElement* GetClient() const;
	unsigned int GetWindowFlags() const;
	void Hide();
	void SetCaption(FObject* object);
	void SetCaptionRect(const FRect& rect);
	void SetClient(FUIElement* element);
	void SetPosition(const FVector2& position);
	void SetWindowFlags(unsigned int flags);
	void Show(int);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned char unk270[0x30];

protected:

	void ArrangeCore(const FRect& rect) override;
	void OnMouseButtonDown(MouseButtonEventArgs* args) override;
	void OnMouseButtonUp(MouseButtonEventArgs* args) override;
	void OnMouseMove(MouseEventArgs* args) override;

private:

	static FClass* StaticConstructClassFWindow();
	static void StaticInitClassFWindow();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FWindow, 0x2A4);
