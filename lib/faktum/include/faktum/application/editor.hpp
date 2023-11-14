#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"


class FNewObjectDlg;
class FGame;
class FLevel;
class FRay;
class FCamera;
class FVector3;

class FEditor : public FObject { // TODO Members, functions

public:

	FEditor();
	FEditor(const FEditor& other);

	~FEditor() override;

	FEditor& operator=(const FEditor& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

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

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


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
	BOOL InitConvertToMeshDlg();
	BOOL InitDialogs();
	BOOL InitImportObjectDlg();
	BOOL InitInformationDlg();
	BOOL InitLevelHandlingDlg();
	BOOL InitMenus();
	BOOL InitNewObjectDlg();
	BOOL InitOpenStorageDlg();
	BOOL InitSplitNodeMenu();
	BOOL InitSplitterMenu();
	void LayoutContextMenu(FObject*, FUIElement::ContextMenuEventArgs*);
	void LayoutDeleteControl(FObject*, FUIElement::EventArgs*);
	void LayoutInsertControl(FObject*, FUIElement::EventArgs*);
	void LayoutRemoveSplit(FObject*, FUIElement::EventArgs*);
	void LayoutSplitHorizontal(FObject*, FUIElement::EventArgs*);
	void LayoutSplitVertical(FObject*, FUIElement::EventArgs*);
	BOOL LoadLevel(const wchar_t* path);
	BOOL LoadStorageObjects(const wchar_t* path);
	BOOL NewLevel(const wchar_t*, FString);
	//void OnInformationDlgClick(FObject*, FInformationDlg::ClickEventArgs*);
	unsigned int PickTransformGizmo(const FMatrix4&, const FRay&, float*);
	void RefreshBrowserControls();
	void RefreshPropertyControls();
	BOOL SaveLevel(const wchar_t* path);
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

	static FClass* StaticConstructClassFEditor();
	static void StaticInitClassFEditor();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FEditor, 0x130);
