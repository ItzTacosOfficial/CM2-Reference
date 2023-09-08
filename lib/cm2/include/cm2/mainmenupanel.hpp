#pragma once

#include "core.hpp"
#include "menupanel.hpp"


class CM2_IMPORT CM2MainMenuPanel : public CM2MenuPanel {

public:

	CM2MainMenuPanel(const CM2MainMenuPanel& other);
	CM2MainMenuPanel(CM2Mode* mode);

	~CM2MainMenuPanel() override;

	CM2MainMenuPanel& operator=(const CM2MainMenuPanel& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	void Render(FCanvas*) override;
	void Enter() override;
	void Leave() override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

protected:

	CM2MainMenuPanel();

private:

	void AchievmentsButtonClick(FObject*, EventArgs*);
	void OnlineButtonClick(FObject*, EventArgs*);
	void OptionsButtonClick(FObject*, EventArgs*);
	void PlayButtonClick(FObject*, EventArgs*);
	void QuitButtonClick(FObject*, EventArgs*);

	static FClass* __cdecl StaticConstructClassCM2MainMenuPanel();
	static void __cdecl StaticInitClassCM2MainMenuPanel();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(CM2MainMenuPanel, 0x2B0);
