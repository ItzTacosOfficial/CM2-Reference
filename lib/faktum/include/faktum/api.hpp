#pragma once

#include "win32.hpp"


#define FAK_API __declspec(dllimport)

#define FAK_SIZE_GUARD(type, value) static_assert(sizeof(type) == (value), "Size of type '" #type "' does not match expected '" #value "'")


#define _FAK_ANNOTATE(x) /* Annotation */

#define FAK_EXTENSION	_FAK_ANNOTATE(extension)	// Extension to the library
#define FAK_NEWNAME		_FAK_ANNOTATE(newname)		// Custom name (e.g. pure virtuals)
#define FAK_CUSTOM		_FAK_ANNOTATE(custom)		// Custom implementation (e.g. templated classes)
#define FAK_ASSUMED		_FAK_ANNOTATE(assumed)		// Not present in symbols, assumed from decompilations
