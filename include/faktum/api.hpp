#pragma once

#include "win32.hpp"


#if !defined(_M_IX86) && !defined(_X86_) && !defined(i386) && !defined(__i386) && !defined(__i386__)
	#error "Faktum is 32-bit only!"
#endif


#define FAK_API __declspec(dllimport)

#define FAK_SIZE_GUARD(type, value) static_assert(sizeof(type) == (value), "Size of type '" #type "' does not match expected '" #value "'")


#define _FAK_ANNOTATE(x) /* Annotation */

#define FAK_EXTENSION	_FAK_ANNOTATE(extension)	// Extension to the library
#define FAK_CUSTOM		_FAK_ANNOTATE(custom)		// Custom (inaccurate) well-behaving implementation
#define FAK_ASSUMED		_FAK_ANNOTATE(assumed)		// Not present in symbols but assumed from decompilations/hints
#define FAK_PARTIAL		_FAK_ANNOTATE(partial)		// Partial presence in symbols
#define FAK_COMPLETE	_FAK_ANNOTATE(complete)		// Fully reverse engineered


#define scast static_cast
#define rcast reinterpret_cast
#define dcast dynamic_cast
#define ccast const_cast
