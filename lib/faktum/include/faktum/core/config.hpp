#pragma once

#include "faktum/api.hpp"


class FString;
class FTextDevice;

class FConfig {

public:

	FConfig();
	FConfig(const FConfig& other);

	FConfig& operator=(const FConfig& other);

	virtual BOOL Init() = 0;
	virtual void Exit() = 0;
	virtual void Flush(int, const wchar_t*) = 0;
	virtual BOOL GetString(const wchar_t* section, const wchar_t* key, FString* value, const wchar_t* file) = 0;
	virtual BOOL GetString(const wchar_t* section, const wchar_t* key, wchar_t* value, unsigned int, const wchar_t* file) = 0;
	virtual const wchar_t* GetString(const wchar_t* section, const wchar_t* key, const wchar_t* file) = 0;
	virtual BOOL GetBool(const wchar_t* section, const wchar_t* key, int* value, const wchar_t* file) = 0;
	virtual BOOL GetInt(const wchar_t* section, const wchar_t* key, int* value, const wchar_t* file) = 0;
	virtual BOOL GetFloat(const wchar_t* section, const wchar_t* key, float* value, const wchar_t* file) = 0;
	virtual void SetString(const wchar_t* section, const wchar_t* key, const wchar_t* value, const wchar_t* file) = 0;
	virtual void SetBool(const wchar_t* section, const wchar_t* key, int value, const wchar_t* file) = 0;
	virtual void SetInt(const wchar_t* section, const wchar_t* key, int value, const wchar_t* file) = 0;
	virtual void SetFloat(const wchar_t* section, const wchar_t* key, float value, const wchar_t* file) = 0;
	virtual void EmptySection(const wchar_t*, const wchar_t*) = 0;

};
FAK_SIZE_GUARD(FConfig, 0x4);

class FConfigINI : public FConfig { // TODO Members

public:

	struct File {}; // TODO Contents


	FConfigINI(const FConfigINI& other);
	FConfigINI(const wchar_t* path);

	~FConfigINI();

	FConfigINI& operator=(const FConfigINI& other);

	void Dump(FTextDevice* device);

	BOOL Init() override;
	void Exit() override;
	void Flush(int, const wchar_t*) override;
	BOOL GetString(const wchar_t* section, const wchar_t* key, FString* value, const wchar_t* file) override;
	BOOL GetString(const wchar_t* section, const wchar_t* key, wchar_t* value, unsigned int, const wchar_t* file) override;
	const wchar_t* GetString(const wchar_t* section, const wchar_t* key, const wchar_t* file) override;
	BOOL GetBool(const wchar_t* section, const wchar_t* key, int* value, const wchar_t* file) override;
	BOOL GetInt(const wchar_t* section, const wchar_t* key, int* value, const wchar_t* file) override;
	BOOL GetFloat(const wchar_t* section, const wchar_t* key, float* value, const wchar_t* file) override;
	void SetString(const wchar_t* section, const wchar_t* key, const wchar_t* value, const wchar_t* file) override;
	void SetBool(const wchar_t* section, const wchar_t* key, int value, const wchar_t* file) override;
	void SetInt(const wchar_t* section, const wchar_t* key, int value, const wchar_t* file) override;
	void SetFloat(const wchar_t* section, const wchar_t* key, float value, const wchar_t* file) override;
	void EmptySection(const wchar_t*, const wchar_t*) override;


	wchar_t* text;
	int unk8;

private:

	File* FindFile(const wchar_t*, int);

};
FAK_SIZE_GUARD(FConfigINI, 0xC);


FAK_API FConfig* FtGetConfig();
