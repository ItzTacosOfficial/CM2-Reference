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

#define FAK_SIZE_GUARD(type, value) static_assert(sizeof(type) == (value), "Size of type '"#type"' does not match expected value '"#value"'")

// Marks a definition that left either partial or no traces in the original binary and existance was assumed
#define FAK_ASSUMED /* Annotation */

// Marks a definition that was most likely not present in the original library yet useful for the end user
#define FAK_EXTENSION /* Annotation */


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

FAK_IMPORT BOOL FtAssertBreak(BOOL condition, const wchar_t* location, const wchar_t* subText, BOOL* abort);


FAK_ASSUMED inline void _FtAssert(BOOL condition, const wchar_t* location, const wchar_t* subText) {

	BOOL abort = FALSE;

	BOOL debug = FtAssertBreak(condition, location, subText, &abort);

	// Also abort if 'Retry' but debugger not present
	abort |= (debug && !IsDebuggerPresent());

	if (abort) {
		ExitProcess(-1);
	} else if (IsDebuggerPresent()) {
		DebugBreak();
	}

}


#ifdef __CLION_IDE__ // Clang-Tidy does not handle __FUNCTION__ well
	#define _FAK_ASSERT_LOCATION() L""
#else
	#define _FAK_ASSERT_LOCATION() L"In function: '" __FUNCTION__ "'"
#endif

#ifdef _DEBUG
	#define FAK_ASSERT(cond, msg) FAK_ASSUMED do { _FtAssert(cond, _FAK_ASSERT_LOCATION(), msg); } while (false)
	#define FAK_FORCE_ASSERT(msg) FAK_ASSUMED FAK_ASSERT(FALSE, msg)
#else
	#define FAK_ASSERT(cond, location, msg) FAK_ASSUMED do {} while (false)
	#define FAK_FORCE_ASSERT(location, msg) FAK_ASSUMED do {} while (false)
#endif
