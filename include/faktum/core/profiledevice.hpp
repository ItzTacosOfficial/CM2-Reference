#pragma once

#include "faktum/api.hpp"
#include "faktum/util/time.hpp"



class FProfileSample;


class FProfileDevice {};
FAK_SIZE_GUARD(FProfileDevice, 0x1);


class FProfileDeviceWindow : public FProfileDevice {

public:

	FProfileDeviceWindow(const FProfileDeviceWindow& other);
	FProfileDeviceWindow(const wchar_t* name);

	~FProfileDeviceWindow();

	FProfileDeviceWindow& operator=(const FProfileDeviceWindow& other);

	FTime GetUpdateInterval() const;
	void SetUpdateInterval(const FTime& time);


	FTime updateInterval;
	FTime unk10;
	HWND windowHandle;
	HWND listViewHandle;

protected:

	virtual void Print(const FProfileSample* sample);

private:

	static int StaticTrayMessage(HWND hwnd, unsigned long, unsigned int, HICON icon, wchar_t*);
	static long CALLBACK StaticWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

};
FAK_SIZE_GUARD(FProfileDeviceWindow, 0x20);


FAK_API void FtResetProfile();
FAK_API void FtSetProfileDevice(FProfileDevice* device);
