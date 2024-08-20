#pragma once

#include "faktum/api.hpp"


#if !defined(_M_IX86) && !defined(_X86_) && !defined(i386) && !defined(__i386) && !defined(__i386__)
	#error "CM2 is 32-bit only!"
#endif


#define CM2_VERSION "1.05.0385"


#define CM2_API FAK_API

#define CM2_SIZE_GUARD FAK_SIZE_GUARD


#define CM2_EXTENSION	FAK_EXTENSION
#define CM2_NEWNAME		FAK_NEWNAME
#define CM2_CUSTOM		FAK_CUSTOM
#define CM2_ASSUMED		FAK_ASSUMED
