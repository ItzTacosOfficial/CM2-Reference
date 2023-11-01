#pragma once

#include "core.hpp"
#include "canvaspanel.hpp"


class CM2_IMPORT CM2MenuPanel : public CM2CanvasPanel { // TODO Members, functions

public:

	CM2MenuPanel(const CM2MenuPanel& other);
	CM2MenuPanel(CM2Mode* mode);

	~CM2MenuPanel() override;

	CM2MenuPanel& operator=(const CM2MenuPanel& other);

	static void* __cdecl operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void Tick(float) override;
	void Render(FCanvas*) override;
	void Enter() override;
	void Leave() override;
	void ResolutionChanged(const FMatrix4&, int) override;

	void SetCM2LogoAlpha(unsigned const char&);
	//void SetNewsTickerText(FTArray<struct CM2HTTPClient::MsgFeed> const&);
	void UpdateNewsTicker();

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	int unk264;
	unsigned char unk268[0x44];
	FRefCount* unk2AC;

protected:

	CM2MenuPanel();

	virtual void OnMouseButtonDown(MouseButtonEventArgs*) override;
	virtual void OnMouseButtonUp(MouseButtonEventArgs*) override;
	virtual void OnMouseMove(MouseEventArgs*) override;
	virtual void OnLeft() override;

	void InitBarButtons(int count, char** names, EventHandlerT* handlers, char** tooltips);

private:

	void HelpButtonClick(FObject*, EventArgs*);
	//void MessageBoxLabDownload(FObject*, CM2Dialog::ClickEventArgs*);
	//void TickerClick(FObject*, FTicker::TickerClickEventArgs*);

	static FClass* __cdecl StaticConstructClassCM2MenuPanel();
	static void __cdecl StaticInitClassCM2MenuPanel();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(CM2MenuPanel, 0x2B0);
