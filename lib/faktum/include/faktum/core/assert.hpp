#pragma once

#include "faktum/api.hpp"


FAK_API BOOL FtAssertBreak(BOOL condition, const wchar_t* location, const wchar_t* subText, BOOL* abort);

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
	#define _FAK_ASSERT_LOCATION L""
#else
	#define _FAK_ASSERT_LOCATION L"In function: '" __FUNCTION__ "'"
#endif

#ifdef _DEBUG
	#define FAK_ASSERT(cond, msg) FAK_ASSUMED do { _FtAssert(cond, _FAK_ASSERT_LOCATION, msg); } while (false)
	#define FAK_FORCE_ASSERT(msg) FAK_ASSUMED FAK_ASSERT(FALSE, msg)
#else
	#define FAK_ASSERT(cond, msg) FAK_ASSUMED do {} while (false)
	#define FAK_FORCE_ASSERT(msg) FAK_ASSUMED do {} while (false)
#endif
