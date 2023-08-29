#pragma once

#include "core.hpp"
#include <concepts>

class FTextDevice;

class FAK_IMPORT FMemManager { // TODO Critical section

public:

	FMemManager();
	FMemManager(const FMemManager& other);

	~FMemManager();

	FMemManager& operator=(const FMemManager& other);

	virtual void Init() = 0;
	virtual void Exit() = 0;
	virtual void* Alloc(unsigned int size, const wchar_t* reason) = 0;
	virtual void* Realloc(void* ptr, unsigned int size, const wchar_t* reason) = 0;
	virtual void Free(void* ptr) = 0;
	virtual void Copy(void* dest, const void* src, unsigned int size) = 0;
	virtual void Move(void* dest, const void* src, unsigned int size) = 0;
	virtual void Fill(void* dest, unsigned char value, unsigned int size) = 0;
	virtual BOOL Compare(const void* a, const void* b, unsigned int size) = 0;
	virtual void Dump(FTextDevice* textDevice, int) = 0;
	virtual unsigned long long GetAvailableOverallMemory() = 0;
	virtual unsigned long long GetAvailablePhysicalMemory() = 0;
	virtual unsigned long long GetAvailableVirtualMemory() = 0;
	virtual unsigned long long GetTotalOverallMemory() = 0;
	virtual unsigned long long GetTotalPhysicalMemory() = 0;
	virtual unsigned long long GetTotalVirtualMemory() = 0;


	BOOL deleteCriticalSection;
	CRITICAL_SECTION criticalSection;
	HANDLE handle;

};
FAK_SIZE_GUARD(FMemManager, 0x24);

class FAK_IMPORT FMemManagerWin32 : public FMemManager { // TODO Members

public:

	struct PoolInfoBase {}; // TODO Contents


	FMemManagerWin32();
	FMemManagerWin32(const FMemManagerWin32& other);

	virtual ~FMemManagerWin32();

	FMemManagerWin32& operator=(const FMemManagerWin32& other);

	void Init() override;
	void Exit() override;
	void* Alloc(unsigned int size, const wchar_t* reason) override;
	void* Realloc(void* ptr, unsigned int size, const wchar_t* reason) override;
	void Free(void* ptr) override;
	void Copy(void* dest, const void* src, unsigned int size) override;
	void Move(void* dest, const void* src, unsigned int size) override;
	void Fill(void* dest, unsigned char value, unsigned int size) override;
	BOOL Compare(const void* a, const void* b, unsigned int size) override;
	void Dump(FTextDevice* textDevice, int) override;
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

class FAK_IMPORT FMemManagerDebug : public FMemManager { // TODO Members, size, functions

public:

	struct DbgBlock {}; // TODO Contents


	FMemManagerDebug();
	FMemManagerDebug(const FMemManagerDebug& other);

	~FMemManagerDebug();

	FMemManagerDebug& operator=(const FMemManagerDebug& other);

	void Init() override;
	void Exit() override;
	void* Alloc(unsigned int size, const wchar_t* reason) override;
	void* Realloc(void* ptr, unsigned int size, const wchar_t* reason) override;
	void Free(void* ptr) override;
	void Copy(void* dest, const void* src, unsigned int size) override;
	void Move(void* dest, const void* src, unsigned int size) override;
	void Fill(void* dest, unsigned char value, unsigned int size) override;
	BOOL Compare(const void* a, const void* b, unsigned int size) override;
	void Dump(FTextDevice* textDevice, int) override;
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

class FAK_IMPORT FMemManagerANSI : public FMemManager { // TODO Members, size

public:

	FMemManagerANSI();
	FMemManagerANSI(const FMemManagerANSI& other);

	~FMemManagerANSI();

	FMemManagerANSI& operator=(const FMemManagerANSI& other);

	void Init() override;
	void Exit() override;
	void* Alloc(unsigned int size, const wchar_t* reason) override;
	void* Realloc(void* ptr, unsigned int size, const wchar_t* reason) override;
	void Free(void* ptr) override;
	void Copy(void* dest, const void* src, unsigned int size) override;
	void Move(void* dest, const void* src, unsigned int size) override;
	void Fill(void* dest, unsigned char value, unsigned int size) override;
	BOOL Compare(const void* a, const void* b, unsigned int size) override;
	void Dump(FTextDevice* textDevice, int) override;
	unsigned long long GetAvailableOverallMemory() override;
	unsigned long long GetAvailablePhysicalMemory() override;
	unsigned long long GetAvailableVirtualMemory() override;
	unsigned long long GetTotalOverallMemory() override;
	unsigned long long GetTotalPhysicalMemory() override;
	unsigned long long GetTotalVirtualMemory() override;

};
//FAK_SIZE_GUARD(FMemManagerANSI, );