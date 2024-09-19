#pragma once

#include "cm2/api.hpp"
#include "faktum/object.hpp"



class CM2Experiment;
class CM2LabHandler;
class CM2LabProgress;
class FTexture;
class FText;
class FGuid;
class FLevel;


class CM2Lab : public FObject {

public:

	struct Chapter {};

	enum TYPE {};


	CM2Lab();
	CM2Lab(const CM2Lab& other);

	~CM2Lab() override;

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	CM2Lab& operator=(const CM2Lab& other);

	void Serialize(FArchive& archive) override;
	
	void AddSkuGuid(const FGuid&);
	int AppendExportedLab(const wchar_t*);
	void DeleteChapter(int);
	void DeleteExperiment(int, int);
	int Export(const wchar_t*);
	CM2Experiment* GetActualExperiment();
	const wchar_t* GetAuthor() const;
	int GetAvailableSolveHintCount() const;
	int GetAvailableSpotHintCount() const;
	FTexture* GetBanner() const;
	Chapter* GetChapter(int);
	int GetChapterCount() const;
	FText* GetChapterDescription(int) const;
	FText* GetChapterTitle(int) const;
	FText* GetDescription() const;
	CM2Experiment* GetExperiment(int, int) const;
	int GetExperimentCount(int) const;
	int GetExperimentCount() const;
	int GetExperimentIndexInLab(int, int);
	unsigned int GetFlags() const;
	FGuid GetGUID() const;
	CM2LabHandler* GetLabHandler();
	CM2LabProgress* GetLabProgress() const;
	const wchar_t* GetMD5();
	int GetNextPlayableLevel(int&, int&);
	const wchar_t* GetPassword() const;
	float GetRating();
	int GetSkuCount();
	FGuid GetSkuGuid(int);
	FText* GetSubtitle() const;
	FText* GetTitle() const;
	unsigned int GetVersion() const;
	int InsertChapter(int);
	FLevel* InsertLoadExperiment(int, int);
	int IsAllExperimentsHaveMedals(int);
	int IsGenuineLab();
	int IsMyLab();
	int IsUserLab();
	FLevel* LoadExperiment(FGuid& guid);
	FLevel* LoadExperiment(int, int);
	void MoveChapter(int, int);
	void MoveExperiment(int, int, int, int);
	CM2LabProgress* NewLabProgress();
	void ResetActualExperiment();
	void ResetChapterProgress(int);
	int Save(const wchar_t*, int);
	void SetActualExperiment(int, int);
	void SetAuthor(const wchar_t* author);
	void SetDescription(const wchar_t* description);
	void SetFlags(unsigned int flags);
	void SetLabHandler(CM2LabHandler* handler);
	void SetLabProgress(CM2LabProgress* progress);
	void SetMD5(const wchar_t* md5);
	void SetPassword(const wchar_t* password);
	void SetRating(float rating);
	void SetTitle(const wchar_t* title);
	void SetVersion(unsigned int version);
	
	static void StaticAppendWT(void*);
	static void StaticConstructor(void* data);
	static void StaticExportWT(void*);
	static FClass* StaticGetClass();
	static int StaticImport(CM2Lab*, const wchar_t*, const wchar_t*);
	static void StaticImportWT(void*);
	static CM2Lab* StaticLoad(const wchar_t*);
	static void StaticUnregisterClass();

	CM2_API static int EventIDWorkProgress;


	unsigned char unk28[0x80];

private:

	static FClass* StaticConstructClassCM2Lab();
	static void StaticInitClassCM2Lab();

	CM2_API static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2Lab, 0xA8);
