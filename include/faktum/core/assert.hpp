#pragma once

#include "faktum/api.hpp"



FAK_API BOOL FtAssertBreak(BOOL condition, const wchar_t* location, const wchar_t* subText, BOOL* abort);

FAK_CUSTOM inline void _FtAssert(BOOL condition, const wchar_t* location, const wchar_t* subText) {

	BOOL abort = FALSE;

	BOOL fail = FtAssertBreak(condition, location, subText, &abort);

	if (!fail) {
		return;
	}

	// Also abort if 'Retry' but debugger not present
	abort |= !IsDebuggerPresent();

	if (abort) {
		ExitProcess(-1);
	} else if (IsDebuggerPresent()) {
		DebugBreak();
	}

}


#ifdef _DEBUG
	#define FAK_ASSERT(cond, msg) FAK_ASSUMED do { _FtAssert(cond, L"In function: '" __FUNCTION__ "'", msg); } while (false)
	#define FAK_FORCE_ASSERT(msg) FAK_ASSUMED FAK_ASSERT(FALSE, msg)
#else
	#define FAK_ASSERT(cond, msg) FAK_ASSUMED do {} while (false)
	#define FAK_FORCE_ASSERT(msg) FAK_ASSUMED do {} while (false)
#endif
