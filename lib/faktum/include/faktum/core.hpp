#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#define FAK_IMPORT /*__declspec(dllimport)*/

#define FAK_SIZE_GUARD(class, value) static_assert(sizeof(class) == (value), "Size of class '"#class"' does not match expected value '"#value"'")


// These macros only work as annotation and have no effect on the program's behaviour

#define FAK_ASSUMED /* Type not existing in the exported symbols, assumed from decompilations */
