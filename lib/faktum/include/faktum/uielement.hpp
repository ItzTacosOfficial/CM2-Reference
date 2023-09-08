#pragma once

#include "core.hpp"
#include "mutable.hpp"


class FUIContext;
class FRect;
class FSize;
class FContextMenu;
class FLength;
class FInputDevice;
class FStyle;
class FMatrix4;
class FVector2;
class FCanvas;

class FAK_IMPORT FUIElement : public FMutable { // TODO Members, functions

public:

	struct EventArgs {}; // TODO Contents

	struct ContextMenuEventArgs {}; // TODO Contents

	struct ControllerButtonEventArgs {}; // TODO Contents

	struct ControllerMoveEventArgs {}; // TODO Contents

	struct DragEventArgs {}; // TODO Contents

	struct EndCompositionEventArgs {}; // TODO Contents

	struct KeyEventArgs {}; // TODO Contents

	struct FocusEventArgs {}; // TODO Contents

	struct MouseButtonEventArgs {}; // TODO Contents

	struct MouseEventArgs {}; // TODO Contents

	struct VisibilityEventArgs {}; // TODO Contents

	enum VISIBILITY { // TODO Contents
		Unknown0,
		Unknown1,
		Unknown2
	};


	FUIElement(const FUIElement& other);
	FUIElement(FUIContext* context);

	~FUIElement() override;

	FUIElement& operator=(const FUIElement& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	void Serialize(FArchive&) override;
	//virtual FTList<FUIElement*>::Iterator BeginChildren();
	virtual FRect GetClipRect() const;
	virtual void Tick(float);
	virtual void Render(FCanvas* canvas);

	void Arrange(const FRect&);
	int BringToTop();
	int CaptureMouse();
	void ClipToParent(int);
	void Disable();
	void Enable(int);
	void EnableDesign(int);
	int Focus();
	FSize GetActualSize() const;
	int GetChildCount() const;
	FUIContext* GetContext() const;
	FContextMenu* GetContextMenu() const;
	FSize GetDesiredSize() const;
	FLength GetHeight() const;
	FInputDevice* GetInputDevice() const;
	FUIElement* GetParent() const;
	FRect GetRect() const;
	unsigned int GetState() const;
	FStyle* GetStyle() const;
	FMatrix4 GetTransform() const;
	unsigned int GetUIElementFlags() const;
	void* GetUserData() const;
	VISIBILITY GetVisibility() const;
	FMatrix4 GetVisualTransform() const;
	FLength GetWidth() const;
	BOOL HasChild(FUIElement*);
	FUIElement* HitTest(const FVector2&);
	void InvalidateArrange();
	void InvalidateMeasure();
	BOOL IsDesigning() const;
	BOOL IsEnabled() const;
	BOOL IsFocused() const;
	BOOL IsVisible() const;
	void Measure(const FSize&);
	void RaiseEvent(int, EventArgs*);
	void ReleaseMouse();
	void SetContext(FUIContext*);
	void SetContextMenu(FContextMenu*);
	void SetHeight(const FLength& height);
	int SetModal(int);
	void SetParent(FUIElement* parent);
	void SetRenderTransform(const FMatrix4& transform);
	void SetStyle(FStyle* style);
	void SetTransform(const FMatrix4& transform);
	void SetUIElementFlags(unsigned int);
	void SetUserData(void* data);
	void SetVisibility(VISIBILITY visibility);
	void SetWidth(const FLength& width);
	void UpdateLayout();

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticInitClass();
	static void __cdecl StaticUnregisterClass();

	static int EventIDCapturedMouse;
	static int EventIDContextMenuClosing;
	static int EventIDContextMenuOpening;
	static int EventIDControllerButtonDown;
	static int EventIDControllerButtonUp;
	static int EventIDControllerMove;
	static int EventIDDragBegin;
	static int EventIDDragEnter;
	static int EventIDDragLeave;
	static int EventIDDragOver;
	static int EventIDDrop;
	static int EventIDEndComposition;
	static int EventIDGotFocus;
	static int EventIDGotFocusPreview;
	static int EventIDKeyDown;
	static int EventIDKeyUp;
	static int EventIDLayoutChanged;
	static int EventIDLostFocus;
	static int EventIDLostFocusPreview;
	static int EventIDMouseButtonDown;
	static int EventIDMouseButtonDownPreview;
	static int EventIDMouseButtonUp;
	static int EventIDMouseButtonUpPreview;
	static int EventIDMouseEnter;
	static int EventIDMouseLeave;
	static int EventIDMouseMove;
	static int EventIDMouseMovePreview;
	static int EventIDMouseWheel;
	static int EventIDReleasedMouse;
	static int EventIDSetVisibility;


	unsigned char unk38[0x1FC];

protected:

	virtual FSize MeasureCore(const FSize&);
	virtual void ArrangeCore(const FRect&);
	virtual void OnEndComposition(EndCompositionEventArgs*);
	virtual void OnKeyDown(KeyEventArgs*);
	virtual void OnKeyUp(KeyEventArgs*);
	virtual void OnMouseButtonDownPreview(MouseButtonEventArgs*);
	virtual void OnMouseButtonDown(MouseButtonEventArgs*);
	virtual void OnMouseButtonUpPreview(MouseButtonEventArgs*);
	virtual void OnMouseButtonUp(MouseButtonEventArgs*);
	virtual void OnMouseEnter(MouseEventArgs*);
	virtual void OnMouseLeave(MouseEventArgs*);
	virtual void OnMouseMovePreview(MouseEventArgs*);
	virtual void OnMouseMove(MouseEventArgs*);
	virtual void OnControllerButtonDown(ControllerButtonEventArgs*);
	virtual void OnControllerButtonUp(ControllerButtonEventArgs*);
	virtual void OnControllerMove(ControllerMoveEventArgs*);
	virtual void OnLostFocusPreview(FocusEventArgs*);
	virtual void OnLostFocus(FocusEventArgs*);
	virtual void OnGotFocusPreview(FocusEventArgs*);
	virtual void OnGotFocus(FocusEventArgs*);
	virtual void OnContextMenuOpening(ContextMenuEventArgs*);
	virtual void OnContextMenuClosing(ContextMenuEventArgs*);
	virtual void OnDragBegin(DragEventArgs*);
	virtual void OnDragEnter(DragEventArgs*);
	virtual void OnDragLeave(DragEventArgs*);
	virtual void OnDragOver(DragEventArgs*);
	virtual void OnDrop(DragEventArgs*);
	virtual void OnSetVisibility(VisibilityEventArgs*);
	virtual int AddChild(FUIElement*);
	virtual int RemoveChild(FUIElement*);
	virtual void RemoveAllChildren();

private:

	void RaiseEventInternal(FEvent*, EventArgs*);

	static FClass* __cdecl StaticConstructClassFUIElement();
	static void __cdecl StaticInitClassFUIElement();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FUIElement, 0x234);
