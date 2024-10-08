#pragma once

#include "faktum/api.hpp"
#include "application.hpp"
#include "faktum/graphics/scene.hpp"



class FLevel;
class FEditor;
class FViewport;
class FRenderer;


class FGame : public FApplication {

public:

	FGame();
	FGame(const FGame& other);

	~FGame() override;

	FGame& operator=(const FGame& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void DrawLevel(FLevel* level, FCanvas* canvas, FScene::TYPE sceneType);
	FEditor* GetEditor() const;
	FLevel* GetLevel() const;
	FViewport* GetMainViewport() const;
	FRenderer* GetRenderer() const;
	BOOL IsEditor() const;
	void PreCacheLevel(FLevel* level);
	void SetLevel(FLevel* level);

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	int unk4C;
	FLevel* level;
	int unk54;
	FEditor* editor;
	int unk5C;

protected:

	BOOL Init() override;
	void Exit() override;
	void PreTick(float) override;
	void PostTick(float) override;
	void Tick(float, unsigned int) override;
	void Render(FCanvas* canvas) override;
	virtual void ToggleEditor();

private:

	static FClass* StaticConstructClassFGame();
	static void StaticInitClassFGame();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FGame, 0x64);
