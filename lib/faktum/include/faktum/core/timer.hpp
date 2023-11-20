#pragma once

#include "faktum/api.hpp"
#include "faktum/util/time.hpp"
#include "faktum/util/mutex.hpp"


class FTimer {

public:

	FAK_NEWNAME virtual void StartTimer() = 0;
	FAK_NEWNAME virtual unsigned long GetFrequency() = 0;
	FAK_NEWNAME virtual void StopTimer(FTime* time) = 0;
	FAK_NEWNAME virtual void GetTime(FTime* time) = 0;
	FAK_NEWNAME virtual void Sleep(const FTime& time) = 0;

};
FAK_SIZE_GUARD(FTimer, 0x4);

class FTimerWin32 : public FTimer {

public:

	FAK_NEWNAME void StartTimer() override;
	FAK_NEWNAME unsigned long GetFrequency() override;
	FAK_NEWNAME void StopTimer(FTime* time) override;
	FAK_NEWNAME void GetTime(FTime* time) override;
	FAK_NEWNAME void Sleep(const FTime& time) override;


	BOOL counterSupported;
	FTime time;
	LARGE_INTEGER frequency;
	FMutex mutex;

};
FAK_SIZE_GUARD(FTimerWin32, 0x38);


FAK_API FTimer* FtGetTimer();
