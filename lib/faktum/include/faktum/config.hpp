#pragma once

#include "core.hpp"


class FAK_IMPORT FConfig {

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

class FAK_IMPORT FConfigINI : public FConfig { // TODO Members

public:

	struct File {}; // TODO Contents


	FConfigINI(const FConfigINI& other);
	FConfigINI(const wchar_t* path);

	~FConfigINI();

	FConfigINI& operator=(const FConfigINI& other);

	void Dump(FTextDevice* device);

	BOOL __thiscall Init() override;
	void __thiscall Exit() override;
	void __thiscall Flush(int, const wchar_t*) override;
	BOOL __thiscall GetString(const wchar_t* section, const wchar_t* key, FString* value, const wchar_t* file) override;
	BOOL __thiscall GetString(const wchar_t* section, const wchar_t* key, wchar_t* value, unsigned int, const wchar_t* file) override;
	const wchar_t* __thiscall GetString(const wchar_t* section, const wchar_t* key, const wchar_t* file) override;
	BOOL __thiscall GetBool(const wchar_t* section, const wchar_t* key, int* value, const wchar_t* file) override;
	BOOL __thiscall GetInt(const wchar_t* section, const wchar_t* key, int* value, const wchar_t* file) override;
	BOOL __thiscall GetFloat(const wchar_t* section, const wchar_t* key, float* value, const wchar_t* file) override;
	void __thiscall SetString(const wchar_t* section, const wchar_t* key, const wchar_t* value, const wchar_t* file) override;
	void __thiscall SetBool(const wchar_t* section, const wchar_t* key, int value, const wchar_t* file) override;
	void __thiscall SetInt(const wchar_t* section, const wchar_t* key, int value, const wchar_t* file) override;
	void __thiscall SetFloat(const wchar_t* section, const wchar_t* key, float value, const wchar_t* file) override;
	void __thiscall EmptySection(const wchar_t*, const wchar_t*) override;


	wchar_t* text;
	int unk8;

private:

	File* FindFile(const wchar_t*, int);

};
FAK_SIZE_GUARD(FConfigINI, 0xC);
