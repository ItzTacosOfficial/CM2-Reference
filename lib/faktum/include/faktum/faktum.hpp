#pragma once

#include "api.hpp"

#include "application.hpp"
#include "core.hpp"
#include "math.hpp"
#include "object.hpp"
#include "render.hpp"
#include "ui.hpp"


// TODO Order

class FCpuInfo;
class FTimer;

float FtFRand();
void FtQuickSort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*, void*), void*);

long __stdcall _FtHandleException(PEXCEPTION_POINTERS info);
