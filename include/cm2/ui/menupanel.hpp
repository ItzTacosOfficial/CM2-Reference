#pragma once

#include "cm2/api.hpp"
#include "canvaspanel.hpp"
#include "cm2/core/httpclient.hpp"



class CM2MenuPanel : public CM2CanvasPanel {

public:

	CM2MenuPanel(const CM2MenuPanel& other);
	CM2MenuPanel(CM2Mode* mode);

	~CM2MenuPanel() override;

	CM2MenuPanel& operator=(const CM2MenuPanel& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Tick(float) override;
	void Render(FCanvas* canvas) override;
	void Enter() override;
	void Leave() override;
	void ResolutionChanged(const FMatrix4&, int) override;

	void SetCM2LogoAlpha(unsigned const char& alpha);
	void SetNewsTickerText(FTArray<CM2HTTPClient::MsgFeed> const& array);
	void UpdateNewsTicker();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	int unk264;
	unsigned char unk268[0x44];
	FRefCount* unk2AC;

protected:

	CM2MenuPanel();

	void OnMouseButtonDown(MouseButtonEventArgs* args) override;
	void OnMouseButtonUp(MouseButtonEventArgs* args) override;
	void OnMouseMove(MouseEventArgs* args) override;
	void OnLeft() override;

	void InitBarButtons(int count, char** names, EventHandlerT* handlers, char** tooltips);

private:

	void HelpButtonClick(FObject* object, EventArgs* args);
	void MessageBoxLabDownload(FObject* object, CM2Dialog::ClickEventArgs* args);
	//void TickerClick(FObject*, FTicker::TickerClickEventArgs*);

	static FClass* StaticConstructClassCM2MenuPanel();
	static void StaticInitClassCM2MenuPanel();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2MenuPanel, 0x2B0);
