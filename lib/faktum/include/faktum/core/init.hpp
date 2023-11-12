#pragma once

#include "faktum/api.hpp"


class FMemManager;
class FTextDevice;
class FFileSystem;
class FConfig;
class FTimer;

FAK_API void FtInit(const wchar_t* args, FMemManager* memManager, FTextDevice* textDevice, FFileSystem* fileSystem, FConfig* config);
FAK_API void FtExit();

FAK_API const wchar_t* FtGetCommandLine();
FAK_API const wchar_t* FtGetOSInfoString();
FAK_API FTimer* FtGetTimer(); // TODO FTimer
