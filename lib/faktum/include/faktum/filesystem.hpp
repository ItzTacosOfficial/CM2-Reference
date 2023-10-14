#pragma once

#include "core.hpp"
#include "archive.hpp"

#include <cstdio>


class FAK_IMPORT FFileSystem { // TODO Members, functions

public:

	struct FindData {}; // TODO Contents

	enum STATUS {}; // TODO Contents

	enum FAK_ASSUMED MODE {
		Read		= 0x1,
		Write		= 0x2,
	};


	FFileSystem();
	FFileSystem(const FFileSystem& other);

	FFileSystem& operator=(const FFileSystem& other);

	virtual FArchive* CreateFileArchive(const wchar_t* path, unsigned int mode, FTextDevice* textDevice) = 0;
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

	class FileArchive : public FArchive { // TODO Verify

	public:

		int Close() override;
		unsigned int Read(void*, unsigned int) override;
		unsigned int Write(const void*, unsigned int) override;
		void Flush() override;
		int Tell() override;
		void Seek(int pos) override;
		int Size() override;


		FILE* file;

	};


	FFileSystemANSI();
	FFileSystemANSI(const FFileSystemANSI& other);

	FFileSystemANSI& operator=(const FFileSystemANSI& other);

	FArchive* CreateFileArchive(const wchar_t* path, unsigned int mode, FTextDevice*) override;
	int GetFileSize(const wchar_t* path) override;
	BOOL Delete(const wchar_t* path) override;
	BOOL Copy(const wchar_t*, const wchar_t*, int, unsigned int (__cdecl*)(__int64, __int64, STATUS, void*), void*, int*) override;
	//FTArray<FFileSystem::FindData> FindFiles(const wchar_t*) override;
	BOOL CreateDirectoryW(const wchar_t* path) override;
	BOOL RemoveDirectoryW(const wchar_t* path) override;

};
FAK_SIZE_GUARD(FFileSystemANSI, 0x4);
