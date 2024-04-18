#pragma once

#include "cm2/api.hpp"
#include "lab.hpp"
#include "faktum/object/object.hpp"
#include "faktum/ui/uielement.hpp"
#include "faktum/util/time.hpp"
#include "openssl/ssl.h"


class CM2Game;
class CM2TransferDialog;
class FThread;

class CM2HTTPClient : public FObject {

public:

	struct CM2_ASSUMED Handle {

		unsigned char unk0[0x400];
		unsigned int state;
		unsigned char randBytes[0x40];
		char* pemKeyBuffer;
		int pemKeyLength;
		char* requestBuffer;
		char* responseBuffer;
		unsigned int requestLength;
		unsigned int responseLength;
		unsigned int responseCode;
		unsigned int responseContentLength;
		unsigned char responseHeaders[0x1000];
		unsigned char responseMD5[0x1000];
		char hostname[0x100];
		FMutex mutex;
		SSL_CTX* context;
		BIO* bio;
		unsigned int blobBufferSize; // CCBS
		unsigned int rootCertSize; // CCCADS
		unsigned int clientCertSize; // CCCMDS

	};
	CM2_SIZE_GUARD(Handle, 0x2598);

	struct CM2_ASSUMED RequestArgument {

		wchar_t field[256];
		wchar_t value[1026];

	};
	CM2_SIZE_GUARD(RequestArgument, 0xA04);

	struct LabInfoServer {};

	struct MsgFeed {};

	struct SkuBigInfoServer {};

	struct SkuSmallInfoServer {};

	struct SolutionInfoServer {};

	struct TransferStatus {};

	struct UserProfile {

		unsigned char unk0[0x28];

	};
	CM2_SIZE_GUARD(UserProfile, 0x28);

	enum CM2_ASSUMED ERROR_CODE {

		SUCCESS = 0,
		TIMED_OUT = 1500,

		SEND_INVALID_PARAMS = 5,

		REQUEST_HANDSHAKE_FAIL = 13,
		REQUEST_BEGIN_FAIL = 41,
		REQUEST_ADD_HEADER_FAIL = 71,
		REQUEST_WRITE_HEADERS_FAIL = 51,
		REQUEST_WRITE_CONTENT_FAIL = 141,
		REQUEST_END_FAIL = 61,

		RESPONSE_INVALID_STATUS = 80,
		RESPONSE_EMPTY_CONTENT = 111,
		RESPONSE_READ_CONTENT_FAIL = 131,
		RESPONSE_TRANSFER_CANCELLED = 1000,
		RESPONSE_READ_MD5_FAIL = 120,
		RESPONSE_MD5_MISMATCH = 500,
		RESPONSE_101 = 101,

		UPLOAD_2 = 2,
		UPLOAD_150 = 150

	};

	enum SKU_CATEGORY {};

	enum SKU_TYPE {};

	enum SORT_KEY {};


	CM2HTTPClient();
	CM2HTTPClient(const CM2HTTPClient& other);

	~CM2HTTPClient() override;

	CM2HTTPClient& operator=(const CM2HTTPClient& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void InitializePostArguments();
	void AddGetArguments(const char* field, const char* value);
	void AddGetArguments(const wchar_t* field, const wchar_t* value);
	void AddPostArguments(const wchar_t* field, const wchar_t* value);
	BOOL IsBusy();
	BOOL IsClientSidedLoggedIn();
	BOOL IsLastProcess();
	void CancelTransfer(FObject* obj, FUIElement::EventArgs* args);
	BOOL IsLoggedIn();
	BOOL ProcessCancelable();
	void ClearLabInfoArray();
	void ReleaseTransferDialog();
	void ClearSkuBigInfoArray();
	void ClearSkuSmallInfoArray();
	void ClearSolutionInfoArray();
	BOOL RequestPost();
	BOOL Close();
	int RequestPostUpload(void* data, unsigned long size);
	int RequestPostUpload(wchar_t* path);
	void ResetClient(BOOL resetDialog);
	unsigned long SendGetLabList(unsigned long, unsigned long, unsigned char, const wchar_t*, int, int, int);
	unsigned long SendGetMsgFeed(int, unsigned long, unsigned long, int);
	unsigned long SendGetSkuInfo(FTArray<wchar_t*>, int);
	unsigned long SendGetSkuList(unsigned long, unsigned long, SORT_KEY sortKey, SKU_TYPE type, SKU_CATEGORY category, int, int, int);
	unsigned long SendGetSolutionList(wchar_t*, unsigned long, unsigned long, unsigned long, unsigned long, int, int);
	unsigned long SendGetUserProfile(int transferMode);
	unsigned long SendHeartbeat();
	unsigned long SendLabDownload(const wchar_t* unk, int transferMode);
	unsigned long SendLabUpload(CM2Lab* lab, int transferMode);
	unsigned long SendLogin(const wchar_t* name, const wchar_t* password, unsigned long unk, int transferMode);
	unsigned long SendLogout(int transferMode);
	unsigned long SendRate(const wchar_t*, unsigned char, unsigned char, unsigned long unk, int transferMode);
	unsigned long SendRegister(const wchar_t*, const wchar_t*, unsigned long unk, const wchar_t*, const wchar_t*, int);
	unsigned long SendScore(const wchar_t*, unsigned long, unsigned long, int);
	unsigned long SendSkuDownload(const wchar_t*, SKU_TYPE, int);
	unsigned long SendSolutionDownload(const wchar_t*, unsigned long, int);
	unsigned long SendSolutionUpload(FLevel*, wchar_t*, unsigned long, wchar_t*, unsigned long, unsigned long, unsigned long, int, int);
	unsigned long SendUpload(void* buffer, unsigned long size, int transferMode, int);
	unsigned long SendUserUpdate(const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, int, int, const wchar_t*, const wchar_t*, int transferMode);
	BOOL SetClientCert();
	void SetGame(CM2Game* game);
	int SetOwnErrorCode(unsigned long code);
	void SetStartListIndex(int index);
	void SetTransferDialog(CM2TransferDialog* dialog);
	void StartTimer();
	BOOL StopProcess(unsigned long);
	unsigned long StoreLabInBuffer(CM2Lab* lab);
	void Tick(float, unsigned int);
	unsigned long GetClientStatus() const;
	unsigned char* GetContentBuffer() const;
	unsigned long GetContentBufferSize() const;
	unsigned long GetEncodedProtocolVersionNumber();
	int GetFileSizeBytes() const;
	void URLDecode(char* dest, char* src);
	unsigned char* GetHeaderBuffer() const;
	unsigned long GetHeaderBufferSize() const;
	FTArray<LabInfoServer>* GetLabInfoArray();
	unsigned long GetLabListCurrentSize() const;
	unsigned long GetLabListMaxSize() const;
	unsigned long GetLabListOverallSize() const;
	unsigned long GetLastComError();
	FTArray<MsgFeed> GetMsgFeedArray() const;
	unsigned long GetOwnErrorCode();
	void URLDecode(wchar_t* dest, wchar_t* src);
	void URLEncode(wchar_t* dest, wchar_t* src);
	FTArray<SkuBigInfoServer>* GetSkuBigInfoArray();
	unsigned long GetSkuListCurrentSize() const;
	unsigned long GetSkuListMaxSize() const;
	unsigned long GetSkuListOverallSize() const;
	FTArray<SkuSmallInfoServer>* GetSkuSmallInfoArray();
	FTArray<SolutionInfoServer> GetSolutionInfoArray() const;
	FLevel* GetSolutionLevel() const;
	CM2TransferDialog* GetTransferDialog() const;
	int GetTransferOutputMode() const;
	int GetTransferredBytes() const;
	char* GetUpdateURL() const;
	UserProfile GetUserProfile();
	BOOL HasError();
	BOOL HasResult();
	void InitializeGetArguments();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

	CM2_API static int EventIDCancelTransfer;
	CM2_API static int EventIDDataTransferEnd;
	CM2_API static int EventIDDataTransferStart;
	CM2_API static int EventIDDataTransferTransmit;
	CM2_API static int EventIDError;


	unsigned int unk28;
	unsigned int unk2C;
	unsigned int unk30;
	unsigned int unk34;
	unsigned int unk38;
	unsigned int unk3C;
	unsigned int unk40;
	unsigned int unk44;
	unsigned int unk48;
	unsigned int unk4C;
	CM2Game* game;
	FThread* postRequestThread;
	CM2TransferDialog* transferDialog;
	void* evaluateFunction;
	FMutex processMutex;
	FMutex errorMutex;
	FTime someTime;
	FTime timeoutTime;
	FTime yeaTime;
	unsigned int unkB8;
	char phpSessionID[33];
	char unkFE[37];
	unsigned char unk102;
	unsigned char unk203;
	char* responseBuffer;
	char* updateUrl;
	FTArray<RequestArgument> postArgumentArray;
	FTArray<RequestArgument> getArgumentArray;
	FTArray<LabInfoServer> labInfoArray;
	FTArray<SkuBigInfoServer> skuBigInfoArray;
	FTArray<SkuSmallInfoServer> skuSmallInfoArray;
	FTArray<MsgFeed> msgFeedArray;
	FTArray<SolutionInfoServer> solutionInfoArray;
	UserProfile userProfile;
	FLevel* solutionLevel;
	Handle* handle;
	FString serialNumber;
	unsigned long labListOverallSize;
	unsigned long labListMaxSize;
	unsigned long labListCurrentSize;
	unsigned int skuListRelated;
	unsigned long skuListOverallSize;
	unsigned long skuListMaxSize;
	unsigned long skuListCurrentSize;
	unsigned int unk1D0;
	unsigned int unk1D4;
	unsigned int unk1D8;
	unsigned int unk1DC;
	unsigned int unk1E0;
	char* contentBuffer;
	char* headerBuffer;
	char* uploadBuffer;
	unsigned long lastComError;
	unsigned long ownErrorCode;
	unsigned int unk1F8;
	unsigned long contentBufferSize;
	unsigned long headerBufferSize;
	unsigned long responseBufferSize;
	unsigned int unk208;
	unsigned int unk20C;
	unsigned long clientStatus;
	int transferOutputMode;
	unsigned int unk218;
	unsigned int unk21C;
	unsigned int unk220;
	BOOL transferCancelled;
	BOOL loggedIn;
	BOOL clientSidedLoggedIn;
	BOOL unk230;
	BOOL hasResult;
	BOOL unk238;
	BOOL unk23C;
	BOOL processCancelable;
	BOOL timeoutCounterRelated;
	int transferredBytes;
	int fileSizeBytes;
	unsigned int unk250;
	const char* hostname;
	FText* serialNumberRegistry;
	unsigned int unk25C;

protected:

	void ClearUploadBuffer();
	void Error(FObject*, unsigned long);
	void EvaluateGetLabList();
	void EvaluateGetMsgFeed();
	void EvaluateGetSkuInfo();
	void EvaluateGetSkuList();
	void EvaluateGetSolutionList();
	void EvaluateGetUserProfile();
	void EvaluateHeartbeat();
	void EvaluateLabDownload();
	void EvaluateLabUpload();
	void EvaluateLogin();
	void EvaluateLogout();
	void EvaluateRate();
	void EvaluateScore();
	void EvaluateSkuDownload();
	void EvaluateSolutionDownload();
	void EvaluateSolutionUpload();
	void EvaluateUpload();
	void EvaluateUserUpdate();
	void EvaluateRegister();
	void ActivateTimeoutCounter(BOOL);
	void AdjustLabInfoListSize();
	void AdjustSkuBigInfoListSize();
	void AdjustSolutionInfoListSize();
	void FreeLabInfo(LabInfoServer& labInfo);
	void FreeMsgFeed(MsgFeed& msgFeed);
	void FreeSkuBigInfo(SkuBigInfoServer& skuBigInfo);
	void FreeSkuSmallInfo(SkuSmallInfoServer& skuSmallInfo);
	void FreeSolutionInfo(SolutionInfoServer& solutionInfo);
	void FreeUserProfile();
	unsigned long GetGetArguments(wchar_t* buffer, unsigned long length);
	unsigned long GetPostArguments(wchar_t* buffer, unsigned long length);
	void GetRebmunLaires(); // Nice try FAKT devs lmao
	void ClearContentBuffer();
	void ClearHeaderBuffer();
	void ClearMsgFeedArray();
	BOOL RequestPostUploadThreaded();
	BOOL RequestPostThreaded();
	void SetClientStatus(int status);
	void TransferStatusEnd(FObject* obj, TransferStatus* status);
	void TransferStatusStart(FObject* obj, TransferStatus* status);
	void TransferStatusTransmit(FObject* obj, TransferStatus* status);
	unsigned long StartProcess(BOOL cancelable);
	BOOL Response();

private:

	static void StaticInitClassCM2HTTPClient();
	static FClass* StaticConstructClassCM2HTTPClient();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2HTTPClient, 0x260);
