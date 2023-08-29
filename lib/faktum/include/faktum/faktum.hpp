#pragma once

#include "core.hpp"

#include "application.hpp"
#include "archive.hpp"
#include "canvas.hpp"
#include "canvaspanel.hpp"
#include "class.hpp"
#include "codec.hpp"
#include "config.hpp"
#include "cursor.hpp"
#include "editor.hpp"
#include "field.hpp"
#include "filesystem.hpp"
#include "game.hpp"
#include "library.hpp"
#include "matrix4.hpp"
#include "memmanager.hpp"
#include "mutable.hpp"
#include "mutex.hpp"
#include "name.hpp"
#include "object.hpp"
#include "panel.hpp"
#include "rect.hpp"
#include "refcount.hpp"
#include "sample.hpp"
#include "scene.hpp"
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
int __cdecl FtBoxBoxOverlap(const FBox*, const FBox*, float);
int __cdecl FtBoxBoxOverlap(const FBox*, const FMatrix4*, const FBox*, const FMatrix4*, float);
int __cdecl FtBoxCapsuleOverlap(const FBox*, const FCapsule*, float);
int __cdecl FtBoxCapsuleOverlap(const FBox*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
int __cdecl FtBoxSphereOverlap(const FBox*, const FMatrix4*, const FSphere*, const FMatrix4*, float);
int __cdecl FtBoxSphereOverlap(const FBox*, const FSphere*, float);
int __cdecl FtCapsuleCapsuleOverlap(const FCapsule*, const FCapsule*, float);
int __cdecl FtCapsuleCapsuleOverlap(const FCapsule*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
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
int __cdecl FtIntersectTriTri(const FVector3&, const FVector3&, const FVector3&, const FVector3&, const FVector3&, const FVector3&);
float __stdcall FtMatrixDeterminant(const FMatrix4*);
FMatrix4* __stdcall FtMatrixInverse(FMatrix4*, float*, const FMatrix4*);
FMatrix4* __stdcall FtMatrixMultiply(FMatrix4*, const FMatrix4*, const FMatrix4*);
FMatrix4* __stdcall FtMatrixMultiplyTranspose(FMatrix4*, const FMatrix4*, const FMatrix4*);
FMatrix4* __stdcall FtMatrixRotationAxis(FMatrix4*, const FVector3*, float);
FMatrix4* __stdcall FtMatrixRotationQuaternion(FMatrix4*, const FQuaternion*);
FMatrix4* __stdcall FtMatrixRotationX(FMatrix4*, float);
FMatrix4* __stdcall FtMatrixRotationY(FMatrix4*, float);
FMatrix4* __stdcall FtMatrixRotationYawPitchRoll(FMatrix4*, float, float, float);
FMatrix4* __stdcall FtMatrixRotationZ(FMatrix4*, float);
FMatrix4* __stdcall FtMatrixScaling(FMatrix4*, float, float, float);
FMatrix4* __stdcall FtMatrixTranslation(FMatrix4*, float, float, float);
FMatrix4* __stdcall FtMatrixTranspose(FMatrix4*, const FMatrix4*);
FPlane* __stdcall FtPlaneFromPointNormal(FPlane*, const FVector3*, const FVector3*);
FPlane* __stdcall FtPlaneFromPoints(FPlane*, const FVector3*, const FVector3*, const FVector3*);
FVector3* __stdcall FtPlaneIntersectLine(FVector3*, const FPlane*, const FVector3*, const FVector3*);
FLine* __stdcall FtPlaneIntersectPlane(FLine*, const FPlane*, const FPlane*);
FVector3* __stdcall FtPlaneIntersectPlanes(FVector3*, const FPlane*, const FPlane*, const FPlane*);
FPlane* __stdcall FtPlaneNormalize(FPlane*, const FPlane*);
FPlane* __stdcall FtPlaneTransform(FPlane*, const FPlane*, const FMatrix4*);
FQuaternion* __stdcall FtQuaternionInverse(FQuaternion*, const FQuaternion*);
FQuaternion* __stdcall FtQuaternionMultiply(FQuaternion*, const FQuaternion*, const FQuaternion*);
FQuaternion* __stdcall FtQuaternionNormalize(FQuaternion*, const FQuaternion*);
FQuaternion* __stdcall FtQuaternionRotationAxis(FQuaternion*, const FVector3*, float);
FQuaternion* __stdcall FtQuaternionRotationMatrix(FQuaternion*, const FMatrix4*);
FQuaternion* __stdcall FtQuaternionRotationYawPitchRoll(FQuaternion*, float, float, float);
FQuaternion* __stdcall FtQuaternionSlerp(FQuaternion*, FQuaternion*, FQuaternion*, float);
void __stdcall FtQuaternionToAxisAngle(const FQuaternion*, FVector3*, float*);
void __cdecl FtQuickSort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*, void*), void*);
FStruct* __cdecl FtRegisterStruct(const char*, unsigned int);
void __cdecl FtResetProfile();
void __cdecl FtSetProfileDevice(FProfileDevice*);
int __cdecl FtSphereCapsuleOverlap(const FSphere*, const FCapsule*, float);
int __cdecl FtSphereCapsuleOverlap(const FSphere*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
FSphere* __stdcall FtSphereFromPoints(FSphere*, const FVector3*, const FVector3*, const FVector3*, const FVector3*, int);
FSphere* __stdcall FtSphereFromPoints(FSphere*, const FVector3*, const FVector3*, const FVector3*, int);
FSphere* __stdcall FtSphereFromPoints(FSphere*, const FVector3*, const FVector3*, int);
FSphere* __stdcall FtSphereMinimum(FSphere*, const FVector3*, int);
int __cdecl FtSphereSphereOverlap(const FSphere*, const FSphere*, float);
int __cdecl FtSphereSphereOverlap(const FSphere*, const FMatrix4*, const FSphere*, const FMatrix4*, float);
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
FVector2* __stdcall FtVec2Normalize(FVector2*, const FVector2*);
FVector2* __stdcall FtVec2NormalizeUnsafe(FVector2*, const FVector2*);
FVector4* __stdcall FtVec2Transform(FVector4*, const FVector2*, const FMatrix4*);
FVector2* __stdcall FtVec2TransformCoord(FVector2*, const FVector2*, const FMatrix4*);
FVector2* __stdcall FtVec2TransformNormal(FVector2*, const FVector2*, const FMatrix4*);
FVector3* __stdcall FtVec3Normalize(FVector3*, const FVector3*);
FVector3* __stdcall FtVec3NormalizeUnsafe(FVector3*, const FVector3*);
FVector4* __stdcall FtVec3Transform(FVector4*, const FVector3*, const FMatrix4*);
FVector3* __stdcall FtVec3TransformCoord(FVector3*, const FVector3*, const FMatrix4*);
FVector3* __stdcall FtVec3TransformNormal(FVector3*, const FVector3*, const FMatrix4*);
FVector4* __stdcall FtVec4Normalize(FVector4*, const FVector4*);
FVector4* __stdcall FtVec4NormalizeUnsafe(FVector4*, const FVector4*);
FVector4* __stdcall FtVec4Transform(FVector4*, const FVector4*, const FMatrix4*);

long __stdcall _FtHandleException(EXCEPTION_POINTERS);
float __cdecl _FtVectorLineSegDist(const FVector3&, const FVector3&, const FVector3&, float);
void __cdecl _FtXToStr(unsigned int, char*, unsigned int, int);
