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


class FBox;
class FCapsule;
class FSphere;
class FCpuInfo;
class FFileSystem;
class FTimer;
class FQuaternion;
class FPlane;
class FLine;
class FStruct;
class FProfileDevice;

int __cdecl FtAssertBreak(int condition, const wchar_t* mainText, const wchar_t* subText, int*);
void __cdecl FtAttachLibrary(FLibrary*);
unsigned long __cdecl FtChecksumCRC32(void*, unsigned int);
int __cdecl FtChecksumMD5A(char*, int, void*, unsigned int);
FString __cdecl FtChecksumMD5W(void*, unsigned int);
int __cdecl FtChecksumMD5W(wchar_t*, int, void*, unsigned int);
int __cdecl FtChecksumMD5W(wchar_t*, int, const wchar_t*);
void __cdecl FtChecksumMD5W(unsigned char* const, void*, unsigned int);
void __cdecl FtClipboardCopy(const wchar_t*);
FString __cdecl FtClipboardPaste();
void __cdecl FtDetachLibrary(FLibrary*);
float __cdecl FtDistanceTriPoint(const FVector3&, const FVector3&, const FVector3&, const FVector3&);
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
char* __cdecl FtIToStrA(int, char*, int);
wchar_t* __cdecl FtIToStrW(int, wchar_t*, int);
void __cdecl FtInit(const wchar_t* args, FMemManager* memManager, FTextDevice* textDevice, FFileSystem* fileSystem, FConfig* config);
void __cdecl FtQuickSort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*, void*), void*);
FStruct* __cdecl FtRegisterStruct(const char*, unsigned int);
void __cdecl FtResetProfile();
void __cdecl FtSetProfileDevice(FProfileDevice*);
unsigned int __cdecl FtStrAnsiToGeneric(wchar_t*, const char*, unsigned int);
unsigned int __cdecl FtStrAnsiToWide(wchar_t*, const char*, unsigned int);
unsigned int __cdecl FtStrGenericToAnsi(char*, const wchar_t*, unsigned int);
unsigned int __cdecl FtStrGenericToWide(wchar_t*, const wchar_t*, unsigned int);
unsigned int __cdecl FtStrHash(const char*);
unsigned int __cdecl FtStrHash(const wchar_t*);
int __cdecl FtStrICmpA(const char*, const char*);
int __cdecl FtStrICmpW(const wchar_t*, const wchar_t*);
int __cdecl FtStrNICmpA(const char*, const char*, unsigned int);
int __cdecl FtStrNICmpW(const wchar_t*, const wchar_t*, unsigned int);
unsigned int __cdecl FtStrPrintFCVA(const char*, char*);
unsigned int __cdecl FtStrPrintFCVW(const wchar_t*, char*);
const char* __cdecl FtStrRChrA(const char*, int, int);
const wchar_t* __cdecl FtStrRChrW(const wchar_t*, int, int);
const char* __cdecl FtStrRStrA(const char*, const char*, unsigned int);
const wchar_t* __cdecl FtStrRStrW(const wchar_t*, const wchar_t*, unsigned int);
float __cdecl FtStrToFA(const char*);
float __cdecl FtStrToFW(const wchar_t*);
int __cdecl FtStrToIA(const char*);
int __cdecl FtStrToIA(const char*, int);
int __cdecl FtStrToIW(const wchar_t*);
int __cdecl FtStrToIW(const wchar_t*, int);
unsigned int __cdecl FtStrToUIA(const char*, int);
unsigned int __cdecl FtStrToUIW(const wchar_t*, int);
unsigned int __cdecl FtStrWideToAnsi(char*, const wchar_t*, unsigned int);
unsigned int __cdecl FtStrWideToGeneric(wchar_t*, const wchar_t*, unsigned int);
char* __cdecl FtUIToStrA(unsigned int, char*, int);
wchar_t* __cdecl FtUIToStrW(unsigned int, wchar_t*, int);

long __stdcall _FtHandleException(EXCEPTION_POINTERS);
float __cdecl _FtVectorLineSegDist(const FVector3&, const FVector3&, const FVector3&, float);
void __cdecl _FtXToStr(unsigned int, char*, unsigned int, int);
