#pragma once

#include "core.hpp"
#include "application.hpp"
#include "scene.hpp"


class FLevel;
class FEditor;
class FViewport;
class FRenderer;

class FAK_IMPORT FGame : public FApplication { // TODO Members

public:

	FGame();
	FGame(const FGame& other);

	~FGame() override;

	FGame& operator=(const FGame& other);

	static void* __cdecl operator new(unsigned int, FObject*, const FName&, const FName&, unsigned int);

	void DrawLevel(FLevel* level, FCanvas* canvas, FScene::TYPE sceneType);
	FEditor* GetEditor() const;
	FLevel* GetLevel() const;
	FViewport* GetMainViewport() const;
	FRenderer* GetRenderer() const;
	int IsEditor() const;
	void PreCacheLevel(FLevel* level);
	void SetLevel(FLevel* level);

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	int unk4C;
	FLevel* unk50;
	int unk54;
	FEditor* editor;
	int unk5C;

protected:

	int Init() override;
	void Exit() override;
	void PreTick(float) override;
	void PostTick(float) override;
	void Tick(float, unsigned int) override;
	void Render(FCanvas* canvas) override;
	virtual void ToggleEditor();

private:

	static FClass* __cdecl StaticConstructClassFGame();
	static void __cdecl StaticInitClassFGame();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FGame, 0x64);
