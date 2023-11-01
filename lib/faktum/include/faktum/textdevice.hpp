#pragma once

#include "core.hpp"
#include "thread.hpp"

#include <cstdio>


class FAK_IMPORT FTextDevice { // TODO Critical section

public:

	enum FORMAT { // TODO Contents
		Critical = 1,
		Error,
		Warning,
		AboveWarning,
		Init,
		Exit,
		AboveExit,
		Dev,
	};


	FTextDevice();
	FTextDevice(const FTextDevice& other);

	~FTextDevice();

	FTextDevice& operator=(const FTextDevice& other);

	unsigned int GetLevel() const;
	void Log(const wchar_t* text);
	void Log(FORMAT format, const wchar_t* text);
	void __cdecl Logf(const wchar_t* text, ...);
	void __cdecl Logf(FORMAT format, const wchar_t* text, ...);
	void SetLevel(FORMAT format);


	unsigned int level;
	BOOL deleteCriticalSection;
	CRITICAL_SECTION criticalSection;
	HANDLE handle;

protected:

	virtual void Serialize(FORMAT format, const wchar_t* text) = 0;

};
FAK_SIZE_GUARD(FTextDevice, 0x28);

class FAK_IMPORT FTextDeviceNull : public FTextDevice {

public:

	FTextDeviceNull();
	FTextDeviceNull(const FTextDeviceNull& other);

	~FTextDeviceNull();

	FTextDeviceNull& operator=(const FTextDeviceNull& other);

protected:

	void Serialize(FORMAT format, const wchar_t* text) override;

};
FAK_SIZE_GUARD(FTextDeviceNull, 0x28);

class FAK_IMPORT FTextDeviceFile : public FTextDevice { // TODO Critical section

public:

	FTextDeviceFile(const FTextDeviceFile& other);
	FTextDeviceFile(const wchar_t* path);

	~FTextDeviceFile();

	FTextDeviceFile& operator=(const FTextDeviceFile& other);


	FILE* file;
	BOOL useCriticalSection;
	CRITICAL_SECTION mutexCriticalSection;
	HANDLE mutexHandle;

protected:

	void Serialize(FORMAT format, const wchar_t* text) override;

};
FAK_SIZE_GUARD(FTextDeviceFile, 0x4C);

class FAK_IMPORT FTextDeviceWindow : public FTextDevice { // TODO Critical section

public:

	FTextDeviceWindow(const FTextDeviceWindow& other);
	FTextDeviceWindow(const wchar_t* windowTitle, const wchar_t* path);

	~FTextDeviceWindow();

	FTextDeviceWindow& operator=(const FTextDeviceWindow& other);


	wchar_t* windowTitle;
	FThread thread;
	FILE* file;
	BOOL useCriticalSection;
	CRITICAL_SECTION mutexCriticalSection;
	HANDLE mutexHandle;
	HWND windowHandle;
	HWND richEditHandle;

protected:

	void Serialize(FORMAT format, const wchar_t* text) override;

private:

	static int __cdecl StaticTrayMessage(HWND hwnd, unsigned long, unsigned int, HICON icon, wchar_t*);
	static long __stdcall StaticWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static void* __stdcall StaticWndThread(FTextDeviceWindow* self);

};
FAK_SIZE_GUARD(FTextDeviceWindow, 0x68);
