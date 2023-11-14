#pragma once

#include "faktum/api.hpp"
#include "faktum/util/array.hpp"


class FCpuInfo {

public:

	struct CPUInfo {

		enum FAK_ASSUMED FLAG {
			VME			= 0x1,
			MMX			= 0x2,
			SSE			= 0x4,
			SSE2		= 0x8,
			SSE3		= 0x10,
			AMD3DNOW	= 0x20,
			AMD3DNOWEXT	= 0x40,
			ALTIVEC		= 0x80
		};

		int vendorID;
		int flags;
		float clockSpeed;
		wchar_t vendor[12];
		wchar_t name[48];
		unsigned int type;
		unsigned int family;
		unsigned int model;
		unsigned int revision;
		unsigned int cacheSizeLevel1;
		unsigned int cacheSizeLevel2;
		unsigned int cacheSizeLevel3;

	};
	FAK_SIZE_GUARD(CPUInfo, 0xA0);


	FCpuInfo();
	FCpuInfo(const FCpuInfo& other);

	virtual ~FCpuInfo();

	FCpuInfo& operator=(const FCpuInfo& other);

	int GetCPUCount() const;
	unsigned int GetCacheSize1stLevel(int cpuID) const;
	unsigned int GetCacheSize2ndLevel(int cpuID) const;
	unsigned int GetCacheSize3rdLevel(int cpuID) const;
	float GetClockSpeed(int cpuID) const;
	unsigned int GetFamily(int cpuID) const;
	BOOL GetInfo();
	unsigned int GetModel(int cpuID) const;
	const wchar_t* GetName(int cpuID) const;
	const wchar_t* GetVendor(int cpuID) const;
	BOOL Has3DNow(int cpuID) const;
	BOOL Has3DNowExt(int cpuID) const;
	BOOL HasAltivec(int cpuID) const;
	BOOL HasMMX(int cpuID) const;
	BOOL HasSSE2(int cpuID) const;
	BOOL HasSSE3(int cpuID) const;
	BOOL HasSSE(int cpuID) const;


	BOOL infoRead;
	FTArray<CPUInfo> infos;

protected:

	static char* GetCPUName(CPUInfo* info);
	static void GetCacheDescription(CPUInfo* info);
	static unsigned long GetInfo(void* param);
	static float GetMHZ();
	static unsigned long long GetRDTSC();
	static BOOL HasCPUID();
	static BOOL ReadRegsiters(unsigned long mode, unsigned int* eax, unsigned int* ebx, unsigned int* ecx, unsigned int* edx);

};
FAK_SIZE_GUARD(FCpuInfo, 0x18);


FAK_API FCpuInfo* FtGetCpuInfo();
