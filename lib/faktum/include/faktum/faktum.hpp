#pragma once

#include "api.hpp"

#include "application.hpp"
#include "core.hpp"
#include "ext.hpp"
#include "math.hpp"
#include "object.hpp"
#include "properties.hpp"
#include "render.hpp"
#include "ui.hpp"
#include "util.hpp"


// TODO Order

class FCpuInfo;
class FTimer;

FAK_API float FtFRand();
FAK_API void FtQuickSort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*, void*), void*);

FAK_API long __stdcall _FtHandleException(PEXCEPTION_POINTERS info);
