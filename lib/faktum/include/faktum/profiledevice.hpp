#pragma once

#include "core.hpp"


class FTime;
class FProfileSample;

class FAK_IMPORT FProfileDevice { // TODO Verify dummy

public:

};
FAK_SIZE_GUARD(FProfileDevice, 0x1);

class FAK_IMPORT FProfileDeviceWindow : public FProfileDevice { // TODO Members, size

public:

	FProfileDeviceWindow(const FProfileDeviceWindow& other);
	FProfileDeviceWindow(const wchar_t* name);

	~FProfileDeviceWindow();

	FProfileDeviceWindow& operator=(const FProfileDeviceWindow& other);

	FTime GetUpdateInterval() const;
	void SetUpdateInterval(const FTime& time);


	int unk4;
	LARGE_INTEGER updateInterval;
	int unk10;
	int unk14;
	HWND unk18;
	HWND unk1C;

protected:

	virtual void Print(const FProfileSample* sample);

private:

	static int __cdecl StaticTrayMessage(HWND hwnd, unsigned long, unsigned int, HICON icon, wchar_t*);
	static long __stdcall StaticWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

};
//FAK_SIZE_GUARD(FProfileDeviceWindow, );


FAK_IMPORT void __cdecl FtResetProfile();
FAK_IMPORT void __cdecl FtSetProfileDevice(FProfileDevice*);
