#pragma once

#include "faktum/api.hpp"
#include "faktum/util/mutex.hpp"
#include "assert.hpp"

#include <new>


class FTextDevice;

class FMemManager { // TODO Critical section

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

class FMemManagerWin32 : public FMemManager { // TODO Members

public:

	struct PoolInfoBase {}; // TODO Contents


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

class FMemManagerDebug : public FMemManager { // TODO Members, size, functions

public:

	struct DbgBlock {}; // TODO Contents


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

private:

	//FTLink<DbgBlock>* FindDbgBlock(const void*);
	//int IsValidDbgBlock(FTLink<DbgBlock>*);

};
//FAK_SIZE_GUARD(FMemManagerDebug, );

class FMemManagerANSI : public FMemManager { // TODO Members, size

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
//FAK_SIZE_GUARD(FMemManagerANSI, );


FAK_API FMemManager* FtGetMemManager();


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
