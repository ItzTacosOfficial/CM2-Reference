#pragma once

#include "cm2/api.hpp"
#include "menupanel.hpp"


class CM2MainMenuPanel : public CM2MenuPanel {

public:

	CM2MainMenuPanel(const CM2MainMenuPanel& other);
	CM2MainMenuPanel(CM2Mode* mode);

	~CM2MainMenuPanel() override;

	CM2MainMenuPanel& operator=(const CM2MainMenuPanel& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Render(FCanvas* canvas) override;
	void Enter() override;
	void Leave() override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

protected:

	CM2MainMenuPanel();

private:

	void AchievmentsButtonClick(FObject*, EventArgs*);
	void OnlineButtonClick(FObject*, EventArgs*);
	void OptionsButtonClick(FObject*, EventArgs*);
	void PlayButtonClick(FObject*, EventArgs*);
	void QuitButtonClick(FObject*, EventArgs*);

	static FClass* StaticConstructClassCM2MainMenuPanel();
	static void StaticInitClassCM2MainMenuPanel();

	CM2_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(CM2MainMenuPanel, 0x2B0);
