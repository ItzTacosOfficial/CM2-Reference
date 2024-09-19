#pragma once

#include "faktum/api.hpp"
#include "faktum/util/archive.hpp"

#include <cstdio>



template<class T>
class FTArray;


class FFileSystem {

public:

	struct FindData {};

	enum STATUS {
		FILEOPENED = 1,
		COPYING
	};

	enum FAK_ASSUMED MODE {
		READ	= 0x1,
		WRITE	= 0x2,
	};

	using CopyCallbackT = unsigned int (__cdecl*)(long long sourceSize, long long unk, STATUS status, void* userData);


	FFileSystem();
	FFileSystem(const FFileSystem& other);

	FFileSystem& operator=(const FFileSystem& other);

	virtual FArchive* CreateFileArchive(const wchar_t* path, unsigned int mode, FTextDevice* textDevice) = 0;
	virtual int GetFileSize(const wchar_t* path) = 0;
	virtual int Delete(const wchar_t* path) = 0;
	virtual int Copy(const wchar_t* dest, const wchar_t* src, BOOL overwrite, CopyCallbackT callback, void* userData, int* unk) = 0;
	virtual FTArray<FindData> FindFiles(const wchar_t*) = 0;
	virtual int CreateDirectoryW(const wchar_t* path) = 0;
	virtual int RemoveDirectoryW(const wchar_t* path) = 0;

};
FAK_SIZE_GUARD(FFileSystem, 0x4);


class FFileSystemANSI : public FFileSystem {

public:

	class FAK_PARTIAL FileArchive : public FArchive {

	public:

		BOOL Close() override;
		unsigned int Read(void* dest, unsigned int size) override;
		unsigned int Write(const void* src, unsigned int size) override;
		void Flush() override;
		int Tell() override;
		void Seek(int pos) override;
		int Size() override;


		FILE* file;

	};
	FAK_SIZE_GUARD(FileArchive, 0xC);


	FFileSystemANSI();
	FFileSystemANSI(const FFileSystemANSI& other);

	FFileSystemANSI& operator=(const FFileSystemANSI& other);

	FArchive* CreateFileArchive(const wchar_t* path, unsigned int mode, FTextDevice*) override;
	int GetFileSize(const wchar_t* path) override;
	BOOL Delete(const wchar_t* path) override;
	BOOL Copy(const wchar_t* dest, const wchar_t* src, BOOL overwrite, CopyCallbackT callback, void* userData, int* unk) override;
	FTArray<FindData> FindFiles(const wchar_t*) override;
	BOOL CreateDirectoryW(const wchar_t* path) override;
	BOOL RemoveDirectoryW(const wchar_t* path) override;

};
FAK_SIZE_GUARD(FFileSystemANSI, 0x4);


FAK_API FFileSystem* FtGetFileSystem();
