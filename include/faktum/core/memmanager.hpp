#pragma once

#include "faktum/api.hpp"
#include "faktum/util/mutex.hpp"
#include "assert.hpp"

#include <new>



class FTextDevice;


class FMemManager {

public:

	FMemManager();
	FMemManager(const FMemManager& other);

	~FMemManager();

	FMemManager& operator=(const FMemManager& other);

	virtual void Init() = 0;
	virtual void Exit() = 0;
	virtual void* Alloc(size_t size, const wchar_t* tag) = 0;
	virtual void* Realloc(void* ptr, size_t size, const wchar_t* tag) = 0;
	virtual void Free(void* ptr) = 0;
	virtual void Copy(void* dest, const void* src, size_t size) = 0;
	virtual void Move(void* dest, const void* src, size_t size) = 0;
	virtual void Fill(void* dest, unsigned char value, size_t size) = 0;
	virtual BOOL Compare(const void* a, const void* b, size_t size) = 0;
	virtual void Dump(FTextDevice* textDevice, BOOL dumpData) = 0;
	virtual unsigned long long GetAvailableOverallMemory() = 0;
	virtual unsigned long long GetAvailablePhysicalMemory() = 0;
	virtual unsigned long long GetAvailableVirtualMemory() = 0;
	virtual unsigned long long GetTotalOverallMemory() = 0;
	virtual unsigned long long GetTotalPhysicalMemory() = 0;
	virtual unsigned long long GetTotalVirtualMemory() = 0;


	FMutex mutex;

};
FAK_SIZE_GUARD(FMemManager, 0x24);


class FMemManagerWin32 : public FMemManager {

public:

	struct PoolInfoBase {};


	FMemManagerWin32();
	FMemManagerWin32(const FMemManagerWin32& other);

	virtual ~FMemManagerWin32();

	FMemManagerWin32& operator=(const FMemManagerWin32& other);

	void Init() override;
	void Exit() override;
	void* Alloc(size_t size, const wchar_t* tag) override;
	void* Realloc(void* ptr, size_t size, const wchar_t* tag) override;
	void Free(void* ptr) override;
	void Copy(void* dest, const void* src, size_t size) override;
	void Move(void* dest, const void* src, size_t size) override;
	void Fill(void* dest, unsigned char value, size_t size) override;
	BOOL Compare(const void* a, const void* b, size_t size) override;
	void Dump(FTextDevice* textDevice, BOOL dumpData) override;
	unsigned long long GetAvailableOverallMemory() override;
	unsigned long long GetAvailablePhysicalMemory() override;
	unsigned long long GetAvailableVirtualMemory() override;
	unsigned long long GetTotalOverallMemory() override;
	unsigned long long GetTotalPhysicalMemory() override;
	unsigned long long GetTotalVirtualMemory() override;


	unsigned char unk24[0x20664];

protected:

	//FTLink<PoolInfoBase>* CreateIndirect();

};
FAK_SIZE_GUARD(FMemManagerWin32, 0x20688);


class FMemManagerDebug : public FMemManager {

public:

	struct DbgBlock {};


	FMemManagerDebug();
	FMemManagerDebug(const FMemManagerDebug& other);

	~FMemManagerDebug();

	FMemManagerDebug& operator=(const FMemManagerDebug& other);

	void Init() override;
	void Exit() override;
	void* Alloc(size_t size, const wchar_t* tag) override;
	void* Realloc(void* ptr, size_t size, const wchar_t* tag) override;
	void Free(void* ptr) override;
	void Copy(void* dest, const void* src, size_t size) override;
	void Move(void* dest, const void* src, size_t size) override;
	void Fill(void* dest, unsigned char value, size_t size) override;
	BOOL Compare(const void* a, const void* b, size_t size) override;
	void Dump(FTextDevice* textDevice, BOOL dumpData) override;
	unsigned long long GetAvailableOverallMemory() override;
	unsigned long long GetAvailablePhysicalMemory() override;
	unsigned long long GetAvailableVirtualMemory() override;
	unsigned long long GetTotalOverallMemory() override;
	unsigned long long GetTotalPhysicalMemory() override;
	unsigned long long GetTotalVirtualMemory() override;

	void CheckMemory();
	void SetDebugBlock(unsigned int);


	unsigned int unk24[3];

private:

	//FTLink<DbgBlock>* FindDbgBlock(const void*);
	//int IsValidDbgBlock(FTLink<DbgBlock>*);

};
FAK_SIZE_GUARD(FMemManagerDebug, 0x30);


class FMemManagerANSI : public FMemManager {

public:

	FMemManagerANSI();
	FMemManagerANSI(const FMemManagerANSI& other);

	~FMemManagerANSI();

	FMemManagerANSI& operator=(const FMemManagerANSI& other);

	void Init() override;
	void Exit() override;
	void* Alloc(size_t size, const wchar_t* tag) override;
	void* Realloc(void* ptr, size_t size, const wchar_t* tag) override;
	void Free(void* ptr) override;
	void Copy(void* dest, const void* src, size_t size) override;
	void Move(void* dest, const void* src, size_t size) override;
	void Fill(void* dest, unsigned char value, size_t size) override;
	BOOL Compare(const void* a, const void* b, size_t size) override;
	void Dump(FTextDevice* textDevice, BOOL dumpData) override;
	unsigned long long GetAvailableOverallMemory() override;
	unsigned long long GetAvailablePhysicalMemory() override;
	unsigned long long GetAvailableVirtualMemory() override;
	unsigned long long GetTotalOverallMemory() override;
	unsigned long long GetTotalPhysicalMemory() override;
	unsigned long long GetTotalVirtualMemory() override;

};
FAK_SIZE_GUARD(FMemManagerANSI, 0x24);


FAK_API FMemManager* FtGetMemManager();


#define FtAlloc(size, tag)			FAK_ASSUMED FtGetMemManager()->Alloc(size, tag)
#define FtRealloc(ptr, size, tag)	FAK_ASSUMED FtGetMemManager()->Realloc(ptr, size, tag)
#define FtFree(ptr)					FAK_ASSUMED FtGetMemManager()->Free(ptr)
#define FtCopy(dest, src, size)		FAK_ASSUMED FtGetMemManager()->Copy(dest, src, size)
#define FtMove(dest, src, size)		FAK_ASSUMED FtGetMemManager()->Move(dest, src, size)
#define FtFill(dest, value, size)	FAK_ASSUMED FtGetMemManager()->Fill(dest, value, size)
#define FtZero(dest, size)			FAK_ASSUMED FtFill(dest, 0, size)


/*FAK_ASSUMED void* operator new(size_t size) {

	void* ptr = nullptr;

	if (FtGetMemManager() != nullptr) {
		ptr = FtGetMemManager()->Alloc(size, L"new");
	} else FAK_EXTENSION {
		ptr = std::malloc(size);
	}

	if (!ptr) FAK_EXTENSION {
		throw std::bad_alloc();
	}

	return ptr;

}

FAK_ASSUMED void* operator new[](size_t size) {
	return operator new(size);
}

FAK_ASSUMED void operator delete(void* ptr) noexcept {

	if (FtGetMemManager() != nullptr) {
		FtGetMemManager()->Free(ptr);
	} else FAK_EXTENSION {
		std::free(ptr);
	}

}

FAK_ASSUMED void operator delete(void* ptr, size_t size) noexcept {
	operator delete(ptr);
}

FAK_ASSUMED void operator delete[](void* ptr) noexcept {
	operator delete(ptr);
}

FAK_ASSUMED void operator delete[](void* ptr, size_t size) noexcept {
	operator delete(ptr);
}*/
