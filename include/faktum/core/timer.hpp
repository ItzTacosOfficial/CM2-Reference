#pragma once

#include "faktum/api.hpp"
#include "faktum/util/time.hpp"
#include "faktum/util/mutex.hpp"



class FAK_PARTIAL FTimer {

public:

	virtual void StartTimer() = 0;
	virtual unsigned long GetFrequency() = 0;
	virtual void StopTimer(FTime& time) = 0;
	virtual void GetTime(FTime& time) = 0;
	virtual void Sleep(const FTime& time) = 0;

};
FAK_SIZE_GUARD(FTimer, 0x4);


class FAK_PARTIAL FTimerWin32 : public FTimer {

public:

	void StartTimer() override;
	unsigned long GetFrequency() override;
	void StopTimer(FTime& time) override;
	void GetTime(FTime& time) override;
	void Sleep(const FTime& time) override;


	BOOL counterSupported;
	FTime time;
	LARGE_INTEGER frequency;
	FMutex mutex;

};
FAK_SIZE_GUARD(FTimerWin32, 0x38);


FAK_API FTimer* FtGetTimer();
