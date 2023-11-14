#pragma once

#include "faktum/api.hpp"
#include "faktum/object/mutable.hpp"


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

class FUIElement : public FMutable { // TODO Members, functions

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

	enum VISIBILITY {}; // TODO Contents


	FUIElement(const FUIElement& other);
	FUIElement(FUIContext* context);

	~FUIElement() override;

	FUIElement& operator=(const FUIElement& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void Serialize(FArchive& archive) override;
	//virtual FTList<FUIElement*>::Iterator BeginChildren();
	virtual FRect GetClipRect() const;
	virtual void Tick(float);
	virtual void Render(FCanvas* canvas);

	void Arrange(const FRect& rect);
	BOOL BringToTop();
	BOOL CaptureMouse();
	void ClipToParent(int);
	void Disable();
	void Enable(int);
	void EnableDesign(int);
	BOOL Focus();
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
	BOOL HasChild(FUIElement* element);
	FUIElement* HitTest(const FVector2& pos);
	void InvalidateArrange();
	void InvalidateMeasure();
	BOOL IsDesigning() const;
	BOOL IsEnabled() const;
	BOOL IsFocused() const;
	BOOL IsVisible() const;
	void Measure(const FSize& size);
	void RaiseEvent(int, EventArgs* args);
	void ReleaseMouse();
	void SetContext(FUIContext*);
	void SetContextMenu(FContextMenu*);
	void SetHeight(const FLength& height);
	BOOL SetModal(int);
	void SetParent(FUIElement* parent);
	void SetRenderTransform(const FMatrix4& transform);
	void SetStyle(FStyle* style);
	void SetTransform(const FMatrix4& transform);
	void SetUIElementFlags(unsigned int);
	void SetUserData(void* data);
	void SetVisibility(VISIBILITY visibility);
	void SetWidth(const FLength& width);
	void UpdateLayout();

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();

	FAK_API static int EventIDCapturedMouse;
	FAK_API static int EventIDContextMenuClosing;
	FAK_API static int EventIDContextMenuOpening;
	FAK_API static int EventIDControllerButtonDown;
	FAK_API static int EventIDControllerButtonUp;
	FAK_API static int EventIDControllerMove;
	FAK_API static int EventIDDragBegin;
	FAK_API static int EventIDDragEnter;
	FAK_API static int EventIDDragLeave;
	FAK_API static int EventIDDragOver;
	FAK_API static int EventIDDrop;
	FAK_API static int EventIDEndComposition;
	FAK_API static int EventIDGotFocus;
	FAK_API static int EventIDGotFocusPreview;
	FAK_API static int EventIDKeyDown;
	FAK_API static int EventIDKeyUp;
	FAK_API static int EventIDLayoutChanged;
	FAK_API static int EventIDLostFocus;
	FAK_API static int EventIDLostFocusPreview;
	FAK_API static int EventIDMouseButtonDown;
	FAK_API static int EventIDMouseButtonDownPreview;
	FAK_API static int EventIDMouseButtonUp;
	FAK_API static int EventIDMouseButtonUpPreview;
	FAK_API static int EventIDMouseEnter;
	FAK_API static int EventIDMouseLeave;
	FAK_API static int EventIDMouseMove;
	FAK_API static int EventIDMouseMovePreview;
	FAK_API static int EventIDMouseWheel;
	FAK_API static int EventIDReleasedMouse;
	FAK_API static int EventIDSetVisibility;


	unsigned char unk38[0x1FC];

protected:

	virtual FSize MeasureCore(const FSize& size);
	virtual void ArrangeCore(const FRect& rect);
	virtual void OnEndComposition(EndCompositionEventArgs* args);
	virtual void OnKeyDown(KeyEventArgs* args);
	virtual void OnKeyUp(KeyEventArgs* args);
	virtual void OnMouseButtonDownPreview(MouseButtonEventArgs* args);
	virtual void OnMouseButtonDown(MouseButtonEventArgs* args);
	virtual void OnMouseButtonUpPreview(MouseButtonEventArgs* args);
	virtual void OnMouseButtonUp(MouseButtonEventArgs* args);
	virtual void OnMouseEnter(MouseEventArgs* args);
	virtual void OnMouseLeave(MouseEventArgs* args);
	virtual void OnMouseMovePreview(MouseEventArgs* args);
	virtual void OnMouseMove(MouseEventArgs* args);
	virtual void OnControllerButtonDown(ControllerButtonEventArgs* args);
	virtual void OnControllerButtonUp(ControllerButtonEventArgs* args);
	virtual void OnControllerMove(ControllerMoveEventArgs* args);
	virtual void OnLostFocusPreview(FocusEventArgs* args);
	virtual void OnLostFocus(FocusEventArgs* args);
	virtual void OnGotFocusPreview(FocusEventArgs* args);
	virtual void OnGotFocus(FocusEventArgs* args);
	virtual void OnContextMenuOpening(ContextMenuEventArgs* args);
	virtual void OnContextMenuClosing(ContextMenuEventArgs* args);
	virtual void OnDragBegin(DragEventArgs* args);
	virtual void OnDragEnter(DragEventArgs* args);
	virtual void OnDragLeave(DragEventArgs* args);
	virtual void OnDragOver(DragEventArgs* args);
	virtual void OnDrop(DragEventArgs* args);
	virtual void OnSetVisibility(VisibilityEventArgs* args);
	virtual int AddChild(FUIElement* element);
	virtual int RemoveChild(FUIElement* element);
	virtual void RemoveAllChildren();

private:

	void RaiseEventInternal(FEvent* event, EventArgs* args);

	static FClass* StaticConstructClassFUIElement();
	static void StaticInitClassFUIElement();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FUIElement, 0x234);
