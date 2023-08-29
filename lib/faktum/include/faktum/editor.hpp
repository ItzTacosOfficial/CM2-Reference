#pragma once

#include "core.hpp"
#include "object.hpp"


class FNewObjectDlg;
class FGame;
class FLevel;
class FRay;
class FCamera;
class FVector3;

class FAK_IMPORT FEditor : public FObject { // TODO Members, functions

public:

	FEditor();
	FEditor(const FEditor& other);

	~FEditor() override;

	FEditor& operator=(const FEditor& other);

	static void* __cdecl operator new(unsigned int, FObject*, const FName&, const FName&, unsigned int);

	void CloseInformationDlg();
	void Exit();
	FUIElement* GetControl(FClass*, int);
	int GetControlCount();
	FNewObjectDlg* GetNewObjectDlg();
	int Init(FGame* game);
	void Refresh();
	void Render(FCanvas* canvas);
	void ShowInformationDlg(const wchar_t*, unsigned int, FObject*, void (FObject::*)(FObject*, void*));
	void Tick(float, unsigned int);

	static void __cdecl StaticConstructor(void*);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	int unk24[0x42];

private:

	//void BrowserDeleteItem(FObject*, FBrowserControl::SelectEventArgs*);
	//void BrowserEnterItem(FObject*, FBrowserControl::SelectEventArgs*);
	void Convert();
	void DeselectAll();
	//void DlgConvertToMeshOk(FObject*, FNewObjectDlg::OkEventArgs*);
	//void DlgImportObjectOk(FObject*, FImportObjectDlg::OkEventArgs*);
	//void DlgLevelHandlingAction(FObject*, FLevelHandlingDlg::ActionEventArgs*);
	//void DlgNewObjectOk(FObject*, FNewObjectDlg::OkEventArgs*);
	//void DlgOpenStorageOk(FObject*, FOpenStorageDlg::OkEventArgs*);
	FLevel* GetLevel() const;
	FMatrix4 GetTransformGizmoMatrix(FCamera*, const FVector3&);
	//void GridSnapUpdate(FObject*, FGridSnapControl::UpdateEventArgs*);
	int InitConvertToMeshDlg();
	int InitDialogs();
	int InitImportObjectDlg();
	int InitInformationDlg();
	int InitLevelHandlingDlg();
	int InitMenus();
	int InitNewObjectDlg();
	int InitOpenStorageDlg();
	int InitSplitNodeMenu();
	int InitSplitterMenu();
	void LayoutContextMenu(FObject*, FUIElement::ContextMenuEventArgs*);
	void LayoutDeleteControl(FObject*, FUIElement::EventArgs*);
	void LayoutInsertControl(FObject*, FUIElement::EventArgs*);
	void LayoutRemoveSplit(FObject*, FUIElement::EventArgs*);
	void LayoutSplitHorizontal(FObject*, FUIElement::EventArgs*);
	void LayoutSplitVertical(FObject*, FUIElement::EventArgs*);
	int LoadLevel(const wchar_t* path);
	int LoadStorageObjects(const wchar_t* path);
	int NewLevel(const wchar_t*, FString);
	//void OnInformationDlgClick(FObject*, FInformationDlg::ClickEventArgs*);
	unsigned int PickTransformGizmo(const FMatrix4&, const FRay&, float*);
	void RefreshBrowserControls();
	void RefreshPropertyControls();
	int SaveLevel(const wchar_t* path);
	void SetEventHandlers(FUIElement*);
	void SetPropertyControlObject(FObject*);
	void SurfaceEditChanged(FObject*, void*);
	void UpdateSelectionMesh();
	void UpdateTransformGizmo();
	void ViewDropObject(FObject*, FUIElement::DragEventArgs*);
	void ViewKeyDown(FObject*, FUIElement::KeyEventArgs*);
	void ViewMouseButtonDown(FObject*, FUIElement::MouseButtonEventArgs*);
	void ViewMouseButtonUp(FObject*, FUIElement::MouseButtonEventArgs*);
	void ViewMouseMove(FObject*, FUIElement::MouseEventArgs*);
	//void ViewRender(FObject*, F3DView::RenderEventArgs*);

	static FClass* __cdecl StaticConstructClassFEditor();
	static void __cdecl StaticInitClassFEditor();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FEditor, 0x130);
