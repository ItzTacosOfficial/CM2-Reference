#pragma once

#include "core.hpp"
#include "faktum/object.hpp"


class CM2Game;
class CM2MsgPopUp;
class CM2MsgBox;
class CM2ProgressDialog;
class CM2TutorialDialog;
class FCanvas;
class FGraphicsDevice;
class FTexture;
class FCamera;
class FMatrix4;
class FLevel;
class FGraphicsProgram;
class FMesh;

class CM2_IMPORT CM2Mode : public FObject { // TODO Members, virtuals, functions

public:

	enum SIMULATIONSPEED {}; // TODO Contents


	CM2Mode(const CM2Mode& other);
	CM2Mode();
	
	~CM2Mode() override;
	
	static void* __cdecl operator new(unsigned int, FObject*, const FName&, const FName&, unsigned int);
	
	CM2Mode& operator=(const CM2Mode& other);

	virtual int Init(CM2Game* game, int);
	virtual void Exit();
	virtual void Tick(float, unsigned int);
	virtual void Render(FCanvas* canvas);
	virtual void ResolutionChanged(unsigned int, unsigned int, int);
	virtual void LeftPanel();
	virtual void AwardReceived();
	virtual void SetMusicVolume(float, int);
	virtual void SetChannelVolume(int, float);
	//?
	virtual void PostRegister(unsigned long);
	virtual void PostLogin(unsigned long);
	//?
	//?
	//?
	virtual void PostGetSolutionList(unsigned long);
	//?
	//?
	virtual void PostSendSolutionUpload(unsigned long);
	virtual void PostSendSolutionDownload(unsigned long);
	virtual void PostSendUserUpdate(unsigned long);
	//?
	virtual void MsgBoxDisconnected();

	virtual void PostGetLabList(unsigned long);
	virtual void PostGetSkuInfo(unsigned long);
	virtual void PostGetSkuList(unsigned long);
	virtual void PostGetUserProfile(unsigned long);
	virtual void PostLogout(unsigned long);
	virtual void PostSendLabUpload(unsigned long);
	virtual void RefreshMode();

	void DrawCubeBackground(FGraphicsDevice*, FTexture*, FCamera*);
	void EnableUI(int);
	int FindAddLabProgress();
	CM2Game* GetGame() const;
	void GetLabList(int, int, int, wchar_t*, int, int, int);
	CM2MsgPopUp* GetMessagePopUp();
	CM2MsgBox* GetMsgBox() const;
	CM2ProgressDialog* GetProgressDialog();
	//void GetSkuInfo(FTArray<wchar_t*>, int);
	//void GetSkuList(unsigned long, unsigned long, CM2HTTPClient::SORT_KEY, CM2HTTPClient::SKU_TYPE, CM2HTTPClient::SKU_CATEGORY, int, int);
	void GetSolutionList(wchar_t*, unsigned long, unsigned long, int, int, int, int);
	CM2TutorialDialog* GetTutorialDialog();
	FMatrix4 GetUITransform();
	void GetUserProfile(int);
	void OnVerifyGetLabList();
	void OnVerifyGetSkuInfo();
	void OnVerifyGetSkuList();
	void OnVerifyGetSolutionList();
	void OnVerifyGetUserProfile();
	void OnVerifySendHeartbeat();
	void OnVerifySendLabUpload();
	void OnVerifySendLogin();
	void OnVerifySendLogout();
	void OnVerifySendRegister();
	void OnVerifySendSolutionDownload();
	void OnVerifySendSolutionUpload();
	void OnVerifyUserUpdate();
	void PlayUISample(int, float);
	void ReconnectCheck();
	void SendHeartbeat();
	void SendLabUpload(const wchar_t*, int);
	void SendLogin(int);
	void SendLogin(const wchar_t*, const wchar_t*, int);
	void SendLogout(int);
	void SendRegister(int);
	void SendRegister(const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, int);
	void SendSolutionDownload(const wchar_t*, unsigned long, int);
	void SendSolutionUpload(FLevel*, wchar_t*, unsigned long, wchar_t*, unsigned long, unsigned long, unsigned long, int, int);
	void SendUserUpdate(const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, int, int, const wchar_t*, const wchar_t*, int);
	void SetSimulationSpeed(SIMULATIONSPEED simulationSpeed);
	void StartTimer();
	void SynchronizeLabs();

	static FClass* __cdecl StaticGetClass();
	static int __cdecl StaticIsPhysicsFluidHardwarePresent();
	static int __cdecl StaticIsPhysicsHardwarePresent();
	static void __cdecl StaticUnregisterClass();


	unsigned char unk28[0xD0];
	
private:

	FGraphicsProgram* InitCubeFragmentProgram();
	FGraphicsProgram* InitCubeVertexProgram();
	FMesh* InitQuad(int, int);

	static FClass* __cdecl StaticConstructClassCM2Mode();
	static void __cdecl StaticInitClassCM2Mode();

	static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2Mode, 0xF8);
