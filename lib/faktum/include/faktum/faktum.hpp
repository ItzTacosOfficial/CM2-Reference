#pragma once

#include "core.hpp"

#include "application.hpp"
#include "archive.hpp"
#include "box.hpp"
#include "canvas.hpp"
#include "canvaspanel.hpp"
#include "capsule.hpp"
#include "checksum.hpp"
#include "class.hpp"
#include "codec.hpp"
#include "config.hpp"
#include "cursor.hpp"
#include "editor.hpp"
#include "export.hpp"
#include "field.hpp"
#include "filesystem.hpp"
#include "game.hpp"
#include "import.hpp"
#include "library.hpp"
#include "line.hpp"
#include "matrix4.hpp"
#include "memmanager.hpp"
#include "mutable.hpp"
#include "mutex.hpp"
#include "name.hpp"
#include "object.hpp"
#include "panel.hpp"
#include "plane.hpp"
#include "profiledevice.hpp"
#include "profilesample.hpp"
#include "quaternion.hpp"
#include "ray.hpp"
#include "rect.hpp"
#include "refcount.hpp"
#include "sample.hpp"
#include "scene.hpp"
#include "sphere.hpp"
#include "storage.hpp"
#include "string.hpp"
#include "struct.hpp"
#include "text.hpp"
#include "textdevice.hpp"
#include "thread.hpp"
#include "uielement.hpp"
#include "vector.hpp"


class FCpuInfo;
class FTimer;

BOOL __cdecl FtAssertBreak(BOOL condition, const wchar_t* mainText, const wchar_t* subText, BOOL* abort);
void __cdecl FtClipboardCopy(const wchar_t*);
FString __cdecl FtClipboardPaste();
void __cdecl FtExit();
float __cdecl FtFRand();
const wchar_t* __cdecl FtGetCommandLine();
FConfig* __cdecl FtGetConfig();
FCpuInfo* __cdecl FtGetCpuInfo();
FFileSystem* __cdecl FtGetFileSystem();
FMemManager* __cdecl FtGetMemManager();
const wchar_t* __cdecl FtGetOSInfoString();
FTextDevice* __cdecl FtGetTextDevice();
FTextDevice* __cdecl FtGetTextDeviceNull();
FTimer* __cdecl FtGetTimer();
void __cdecl FtInit(const wchar_t* args, FMemManager* memManager, FTextDevice* textDevice, FFileSystem* fileSystem, FConfig* config);
void __cdecl FtQuickSort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*, void*), void*);

long __stdcall _FtHandleException(EXCEPTION_POINTERS);
