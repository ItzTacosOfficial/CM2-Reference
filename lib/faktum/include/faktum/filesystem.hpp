#pragma once

#include "core.hpp"


class FArchive;

class FAK_IMPORT FFileSystem { // TODO Members, functions

public:

	struct FindData {}; // TODO Contents

	enum STATUS {}; // TODO Contents


	FFileSystem();
	FFileSystem(const FFileSystem& other);

	FFileSystem& __thiscall operator=(const FFileSystem& other);

	virtual FArchive* CreateFileArchive(const wchar_t*, unsigned int, FTextDevice* textDevice) = 0;
	virtual int GetFileSize(const wchar_t* path) = 0;
	virtual int Delete(const wchar_t* path) = 0;
	virtual int Copy(const wchar_t*, const wchar_t*, int, unsigned int (__cdecl*)(__int64, __int64, STATUS, void*), void*, int*) = 0;
	//virtual FTArray<FindData> FindFiles(const wchar_t*) = 0;
	virtual int CreateDirectoryW(const wchar_t* path) = 0;
	virtual int RemoveDirectoryW(const wchar_t* path) = 0;

};
FAK_SIZE_GUARD(FFileSystem, 0x4);

class FAK_IMPORT FFileSystemANSI : public FFileSystem {

public:

	FFileSystemANSI();
	FFileSystemANSI(const FFileSystemANSI& other);

	FFileSystemANSI& operator=(const FFileSystemANSI& other);

	FArchive* CreateFileArchive(const wchar_t*, unsigned int, FTextDevice*) override;
	int GetFileSize(const wchar_t*) override;
	int Delete(const wchar_t*) override;
	int Copy(const wchar_t*, const wchar_t*, int, unsigned int (__cdecl*)(__int64, __int64, STATUS, void*), void*, int*) override;
	//FTArray<FFileSystem::FindData> FindFiles(const wchar_t*) override;
	int CreateDirectoryW(const wchar_t*) override;
	int RemoveDirectoryW(const wchar_t*) override;

};
FAK_SIZE_GUARD(FFileSystemANSI, 0x4);
