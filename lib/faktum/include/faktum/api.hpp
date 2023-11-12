#pragma once

#include "win32.hpp"


#define FAK_API __declspec(dllimport)

#define FAK_SIZE_GUARD(type, value) static_assert(sizeof(type) == (value), "Size of type '" #type "' does not match expected '" #value "'")


#define _FAK_ANNOTATE(x) /* Annotation */


// Definition left either partial or no traces in the original binary and existence was assumed
#define FAK_ASSUMED _FAK_ANNOTATE(ASSUMED)

// Definition was most likely not present in the original library yet useful for the end user
#define FAK_EXTENSION _FAK_ANNOTATE(EXTENSION)
