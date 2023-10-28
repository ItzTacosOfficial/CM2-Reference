#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class FConfig;
class FCpuInfo;
class FFileSystem;
class FMemManager;
class FTextDevice;
class FTimer;


#define FAK_IMPORT __declspec(dllimport)

#define FAK_SIZE_GUARD(class, value) static_assert(sizeof(class) == (value), "Size of class '"#class"' does not match expected value '"#value"'")

// Marks a type/function which left no trace in the original binary and that was assumed from decompilations
#define FAK_ASSUMED /* Annotation */


FAK_IMPORT void FtInit(const wchar_t* args, FMemManager* memManager, FTextDevice* textDevice, FFileSystem* fileSystem, FConfig* config);
FAK_IMPORT void __cdecl FtExit();

FAK_IMPORT const wchar_t* FtGetCommandLine();
FAK_IMPORT FConfig* FtGetConfig();
FAK_IMPORT FCpuInfo* FtGetCpuInfo();
FAK_IMPORT FFileSystem* FtGetFileSystem();
FAK_IMPORT FMemManager* FtGetMemManager();
FAK_IMPORT const wchar_t* FtGetOSInfoString();
FAK_IMPORT FTextDevice* FtGetTextDevice();
FAK_IMPORT FTextDevice* FtGetTextDeviceNull();
FAK_IMPORT FTimer* FtGetTimer();

FAK_IMPORT BOOL FtAssertBreak(BOOL condition, const wchar_t* mainText, const wchar_t* subText, BOOL* abort);


#ifdef _DEBUG
	#define FAK_ASSERT(cond, mainText, subText, abort) FAK_ASSUMED do { FtAssertBreak(cond, mainText, subText, abort); } while (false)
	#define FAK_FORCE_ASSERT(mainText, subText, abort) FAK_ASSUMED FAK_ASSERT(FALSE, mainText, subText, abort);
#else
	#define FAK_ASSERT(cond, mainText, subText, abort) FAK_ASSUMED do {} while (false)
	#define FAK_FORCE_ASSERT(mainText, subText, abort) FAK_ASSUMED do {} while (false)
#endif
