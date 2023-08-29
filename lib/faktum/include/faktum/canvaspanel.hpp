#pragma once

#include "core.hpp"
#include "panel.hpp"


class FAK_IMPORT FCanvasPanel : public FPanel { // TODO Members

public:

	FCanvasPanel(const FCanvasPanel& other);
	FCanvasPanel(FUIContext* context);

	~FCanvasPanel() override;

	FCanvasPanel& operator=(const FCanvasPanel& other);

	static void* __cdecl operator new(unsigned int, FObject*, const FName&, const FName&, unsigned int);

	void Render(FCanvas* canvas) override;
	void Serialize(FArchive&) override;
	int AddChild(FUIElement* child) override;
	int RemoveChild(FUIElement* child) override;
	void RemoveAllChildren() override;
	FUIElement* GetChild(int) override;

	int AddChild(const FRect& rect, FUIElement* child);
	int SetRect(FUIElement* child, const FRect& rect);

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticInitClass();
	static void __cdecl StaticUnregisterClass();


	unsigned char unk23C[0x20];

protected:
	
	void ArrangeCore(const FRect&) override;

	void MouseButtonDown(FObject*, MouseButtonEventArgs* args);
	void MouseButtonUp(FObject*, MouseButtonEventArgs* args);
	void MouseMove(FObject*, MouseEventArgs* args);

private:

	static FClass* __cdecl StaticConstructClassFCanvasPanel();
	static void __cdecl StaticInitClassFCanvasPanel();
	
	
	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCanvasPanel, 0x25C);
