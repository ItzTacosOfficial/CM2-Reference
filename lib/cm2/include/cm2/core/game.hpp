#pragma once

#include "cm2/api.hpp"
#include "lab.hpp"
#include "faktum/application/game.hpp"
#include "faktum/util/cursor.hpp"
#include "faktum/core/filesystem.hpp"


class CM2CameraShaker;
class CM2Profile;
class CM2ElementDesc;
class CM2HTTPClient;
class CM2Mode;
class CM2Character;
class CM2Sku;
class CM2Statistics;
class CM2ThemeDesc;
class CM2UIHandler;
class FGuid;
class FFrustum;
class FRect;
class FWorkingThread;

class CM2Game : public FGame { // TODO Members, functions

public:

	struct VersionNumber {}; // TODO Contents

	struct PlugIn {}; // TODO Contents

	enum CURSOR {}; // TODO Contents


	CM2Game();
	CM2Game(const CM2Game& other);

	~CM2Game() override;

	CM2Game& operator=(const CM2Game& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	int Init() override;
	void Exit() override;
	void Tick(float, unsigned int) override;
	void Render(FCanvas* canvas) override;

	int AddSku(const FGuid&, unsigned int);
	int CreateProfile(const wchar_t*, const wchar_t*, FString, const FName&, int, int, int);
	void DecodeVersionNumber(unsigned long, VersionNumber*);
	void DeselectAll();
	unsigned long EncodeVersionNumber(VersionNumber);
	CM2Lab* FindLab(CM2Lab::TYPE, const wchar_t*);
	int FindSku(const FGuid&) const;
	CM2CameraShaker* GetCameraShaker();
	unsigned int GetCheats() const;
	void GetContinuousPlayerName(wchar_t*);
	CM2Profile* GetCurrentProfile() const;
	int GetCurrentProfileIndex() const;
	CM2ElementDesc* GetElementDesc(int) const;
	int GetElementDescCount() const;
	unsigned long GetEncodedGameVersionNumber();
	//FFrustum GetFrustum(const FRect&, FGraphicsDevice::const Viewport&) const;
	FTArray<CM2Lab*>* GetGenuineLabsArray();
	int GetGenuineLabsCount();
	CM2HTTPClient* GetHTTPClient() const;
	CM2Lab* GetLab() const;
	FName GetLanguageName(int);
	int GetLastLabChapter() const;
	int GetLastLabExperiment() const;
	CM2Lab::TYPE GetLastLabType() const;
	CM2Mode* GetMode() const;
	FTArray<CM2Lab*>* GetMyLabsArray();
	int GetMyLabsCount();
	unsigned int GetOnlineState();
	const PlugIn* GetPlugIn(int) const;
	int GetPlugInCount() const;
	int GetPostEffectQuality() const;
	CM2Character* GetProfessor() const;
	CM2Profile* GetProfile(int) const;
	int GetProfileCount() const;
	//FRay GetRay(const FVector2&, FGraphicsDevice::const Viewport&) const;
	FScene::TYPE GetSceneType() const;
	CM2Sku* GetSku(int) const;
	int GetSkuCount() const;
	CM2Statistics* GetStatistics();
	CM2ThemeDesc* GetThemeDesc(int) const;
	int GetThemeDescCount() const;
	CM2UIHandler* GetUIHandler() const;
	FTArray<CM2Lab*>* GetUserLabsArray();
	int GetUserLabsCount();
	FWorkingThread* GetWorkingThread();
	int InstallPackage(const wchar_t*);
	int IsBenchmarkStarted();
	int IsOfflineForced();
	int IsProfileDeactivated();
	//void LabAward(FObject*, CM2LabHandler::AwardReleasedEventArgs*);
	void LoadExperiment(CM2Lab*, int, int, int, const wchar_t*);
	void LoadLabLibraries();
	void LoadLabs();
	void LoadMenuW(int);
	void LoadMyLabs();
	void LoadProfiles();
	void LoadSkus();
	void LoadStoryLabs();
	void LoadUserLabs();
	void NewLab();
	//void OnClose(FObject*, FViewport::CloseEventArgs*);
	void RegisterPlugIn(const wchar_t*);
	void RegisterPlugIns();
	void ReleaseLab();
	void SetCheats(int);
	void SetCurrentProfileIndex(int);
	void SetCursor(CURSOR);
	void SetForceOffline(int);
	void SetLab(CM2Lab*, CM2Lab::TYPE);
	void SetLastLabChapter(int);
	void SetLastLabExperiment(int);
	void SetNewMode(CM2Mode*);
	void SetOnlineState(unsigned int);
	void SetPostEffectQuality(int);
	void SetProfileDeactivated(int);
	void SetSceneType(FScene::TYPE);
	void SetShowOnlineState(int);
	void SetStatistics(CM2Statistics*);
	int ShowOnlineState();
	void SortLabs(CM2Lab::TYPE);
	void SortProfiles();
	void StartBenchmark(const FName&);
	//void StatisticsAward(FObject*, CM2Statistics::StatisticsEventArgs*);
	void StopBenchmark();
	void UnloadLabLibraries();
	void UnloadLabs();
	void UnloadProfiles();
	void UnloadSkus();
	void UnregisterPlugIns();
	long ValidCD();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned char unk[0x19C];

private:

	void CheckCheats();
	void InitCursor(CURSOR, const char*, FCursor::TYPE);
	void InitCursors();
	void LoadAddOnLab(const FTArray<FString>&);
	void LoadForInstall();
	void Screenshot();
	void UnloadForInstall();

	static int StaticCompareFiles(FFileSystem::FindData*, FFileSystem::FindData*, void*);
	static int StaticCompareLabs(CM2Lab**, CM2Lab**, void*);
	static int StaticCompareProfiles(CM2Profile**, CM2Profile**, void*);
	static int StaticCompareStoryLabs(CM2Lab**, CM2Lab**, void*);
	static FClass* StaticConstructClassCM2Game();
	static void StaticInitClassCM2Game();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2Game, 0x200);
