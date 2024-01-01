#pragma once

#include "faktum/api.hpp"
#include "panel.hpp"


class FCanvasPanel : public FPanel { // TODO Members

public:

	FCanvasPanel(const FCanvasPanel& other);
	FCanvasPanel(FUIContext* context);

	~FCanvasPanel() override;

	FCanvasPanel& operator=(const FCanvasPanel& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Render(FCanvas* canvas) override;
	void Serialize(FArchive&) override;
	int AddChild(FUIElement* child) override;
	int RemoveChild(FUIElement* child) override;
	void RemoveAllChildren() override;
	FUIElement* GetChild(int id) override;

	int AddChild(const FRect& rect, FUIElement* child);
	int SetRect(FUIElement* child, const FRect& rect);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	unsigned char unk23C[0x20];

protected:
	
	void ArrangeCore(const FRect& rect) override;

	void MouseButtonDown(FObject*, MouseButtonEventArgs* args);
	void MouseButtonUp(FObject*, MouseButtonEventArgs* args);
	void MouseMove(FObject*, MouseEventArgs* args);

private:

	static FClass* StaticConstructClassFCanvasPanel();
	static void StaticInitClassFCanvasPanel();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCanvasPanel, 0x25C);
