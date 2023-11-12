#pragma once

#include "core.hpp"

#include "application.hpp"
#include "archive.hpp"
#include "array.hpp"
#include "blob.hpp"
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
#include "event.hpp"
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
#include "size.hpp"
#include "sphere.hpp"
#include "storage.hpp"
#include "string.hpp"
#include "struct.hpp"
#include "text.hpp"
#include "textdevice.hpp"
#include "thread.hpp"
#include "time.hpp"
#include "uielement.hpp"
#include "vector.hpp"


class FCpuInfo;
class FTimer;

void FtClipboardCopy(const wchar_t*);
FString FtClipboardPaste();
float FtFRand();
void FtQuickSort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*, void*), void*);

long __stdcall _FtHandleException(PEXCEPTION_POINTERS info);
