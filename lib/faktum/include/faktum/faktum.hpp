#pragma once

#include "core.hpp"

#include "application.hpp"
#include "archive.hpp"
#include "box.hpp"
#include "canvas.hpp"
#include "canvaspanel.hpp"
#include "capsule.hpp"
#include "class.hpp"
#include "codec.hpp"
#include "config.hpp"
#include "cursor.hpp"
#include "editor.hpp"
#include "field.hpp"
#include "filesystem.hpp"
#include "game.hpp"
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
class FProfileDevice;

int __cdecl FtAssertBreak(int condition, const wchar_t* mainText, const wchar_t* subText, int*);
unsigned long __cdecl FtChecksumCRC32(void*, unsigned int);
int __cdecl FtChecksumMD5A(char*, int, void*, unsigned int);
FString __cdecl FtChecksumMD5W(void*, unsigned int);
int __cdecl FtChecksumMD5W(wchar_t*, int, void*, unsigned int);
int __cdecl FtChecksumMD5W(wchar_t*, int, const wchar_t*);
void __cdecl FtChecksumMD5W(unsigned char* const, void*, unsigned int);
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
FStruct* __cdecl FtRegisterStruct(const char*, unsigned int);
void __cdecl FtResetProfile();
void __cdecl FtSetProfileDevice(FProfileDevice*);

long __stdcall _FtHandleException(EXCEPTION_POINTERS);
float __cdecl _FtVectorLineSegDist(const FVector3&, const FVector3&, const FVector3&, float);
