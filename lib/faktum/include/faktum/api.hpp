#pragma once

#include "win32.hpp"


#if !defined(_M_IX86) && !defined(_X86_) && !defined(i386) && !defined(__i386) && !defined(__i386__)
	#error "Faktum is 32-bit only!"
#endif


#define FAK_VERSION "1.05.0385"


#define FAK_API __declspec(dllimport)

#define FAK_SIZE_GUARD(type, value) static_assert(sizeof(type) == (value), "Size of type '" #type "' does not match expected '" #value "'")


#define _FAK_ANNOTATE(x) /* Annotation */

#define FAK_EXTENSION	_FAK_ANNOTATE(extension)	// Extension to the library
#define FAK_NEWNAME		_FAK_ANNOTATE(newname)		// Custom name (e.g. pure virtuals)
#define FAK_CUSTOM		_FAK_ANNOTATE(custom)		// Custom implementation (e.g. templated classes)
#define FAK_ASSUMED		_FAK_ANNOTATE(assumed)		// Not present in symbols, assumed from decompilations
#define FAK_INLINED		_FAK_ANNOTATE(inlined)		// Optimized away by LTO; may imply 'newname' and 'custom'


#define scast static_cast
#define rcast reinterpret_cast
#define dcast dynamic_cast
#define ccast const_cast
