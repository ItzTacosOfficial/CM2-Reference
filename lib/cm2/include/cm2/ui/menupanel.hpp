#pragma once

#include "cm2/api.hpp"
#include "canvaspanel.hpp"


class CM2MenuPanel : public CM2CanvasPanel { // TODO Members, functions

public:

	CM2MenuPanel(const CM2MenuPanel& other);
	CM2MenuPanel(CM2Mode* mode);

	~CM2MenuPanel() override;

	CM2MenuPanel& operator=(const CM2MenuPanel& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void Tick(float) override;
	void Render(FCanvas* canvas) override;
	void Enter() override;
	void Leave() override;
	void ResolutionChanged(const FMatrix4&, int) override;

	void SetCM2LogoAlpha(unsigned const char&);
	//void SetNewsTickerText(FTArray<struct CM2HTTPClient::MsgFeed> const&);
	void UpdateNewsTicker();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	int unk264;
	unsigned char unk268[0x44];
	FRefCount* unk2AC;

protected:

	CM2MenuPanel();

	void OnMouseButtonDown(MouseButtonEventArgs*) override;
	void OnMouseButtonUp(MouseButtonEventArgs*) override;
	void OnMouseMove(MouseEventArgs*) override;
	void OnLeft() override;

	void InitBarButtons(int count, char** names, EventHandlerT* handlers, char** tooltips);

private:

	void HelpButtonClick(FObject*, EventArgs*);
	//void MessageBoxLabDownload(FObject*, CM2Dialog::ClickEventArgs*);
	//void TickerClick(FObject*, FTicker::TickerClickEventArgs*);

	static FClass* StaticConstructClassCM2MenuPanel();
	static void StaticInitClassCM2MenuPanel();

	CM2_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(CM2MenuPanel, 0x2B0);
