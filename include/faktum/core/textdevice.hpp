#pragma once

#include "faktum/api.hpp"
#include "faktum/util/thread.hpp"
#include "faktum/util/mutex.hpp"

#include <cstdio>



class FTextDevice {

public:

	enum FORMAT {
		FMT_CRITICAL = 1,
		FMT_ERROR,
		FMT_WARNING,
		FMT_ABOVE_WARNING,
		FMT_INIT,
		FMT_EXIT,
		FMT_ABOVE_EXIT,
		FMT_DEV,
	};


	FTextDevice();
	FTextDevice(const FTextDevice& other);

	~FTextDevice();

	FTextDevice& operator=(const FTextDevice& other);

	unsigned int GetLevel() const;
	void Log(const wchar_t* text);
	void Log(FORMAT level, const wchar_t* text);
	void Logf(const wchar_t* text, ...);
	void Logf(FORMAT level, const wchar_t* text, ...);
	void SetLevel(FORMAT level);


	unsigned int level;
	FMutex mutex;

protected:

	virtual void Serialize(FORMAT format, const wchar_t* text) = 0;

};
FAK_SIZE_GUARD(FTextDevice, 0x28);


class FTextDeviceNull : public FTextDevice {

public:

	FTextDeviceNull();
	FTextDeviceNull(const FTextDeviceNull& other);

	~FTextDeviceNull();

	FTextDeviceNull& operator=(const FTextDeviceNull& other);

protected:

	void Serialize(FORMAT format, const wchar_t* text) override;

};
FAK_SIZE_GUARD(FTextDeviceNull, 0x28);


class FTextDeviceFile : public FTextDevice {

public:

	FTextDeviceFile(const FTextDeviceFile& other);
	FTextDeviceFile(const wchar_t* path);

	~FTextDeviceFile();

	FTextDeviceFile& operator=(const FTextDeviceFile& other);


	FILE* file;
	FMutex fileMutex;

protected:

	void Serialize(FORMAT format, const wchar_t* text) override;

};
FAK_SIZE_GUARD(FTextDeviceFile, 0x4C);


class FTextDeviceWindow : public FTextDevice {

public:

	FTextDeviceWindow(const FTextDeviceWindow& other);
	FTextDeviceWindow(const wchar_t* windowTitle, const wchar_t* path);

	~FTextDeviceWindow();

	FTextDeviceWindow& operator=(const FTextDeviceWindow& other);


	wchar_t* windowTitle;
	FThread thread;
	FILE* file;
	FMutex richEditMutex;
	HWND windowHandle;
	HWND richEditHandle;

protected:

	void Serialize(FORMAT format, const wchar_t* text) override;

private:

	static int StaticTrayMessage(HWND hwnd, unsigned long, unsigned int, HICON icon, wchar_t*);
	static long CALLBACK StaticWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static void* __stdcall StaticWndThread(FTextDeviceWindow* self);

};
FAK_SIZE_GUARD(FTextDeviceWindow, 0x68);


#include "textdevicestd.inl"


FAK_API FTextDevice* FtGetTextDevice();
FAK_API FTextDevice* FtGetTextDeviceNull();


#define FtLog(...)	FAK_ASSUMED FtGetTextDevice()->Log(__VA_ARGS__);
#define FtLogf(...)	FAK_ASSUMED FtGetTextDevice()->Logf(__VA_ARGS__);
