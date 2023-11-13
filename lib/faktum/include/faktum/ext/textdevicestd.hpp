#pragma once

#include "faktum/api.hpp"
#include "faktum/core/textdevice.hpp"


class FAK_EXTENSION FETextDeviceSTD : public FTextDevice {

public:

	inline FETextDeviceSTD() = default;


	FMutex pipeMutex;

protected:

	void Serialize(FORMAT format, const wchar_t* text) override {

		if (!stdout) {
			return;
		}

		const wchar_t* prefix = L"";

		switch(format) {
			case FMT_CRITICAL:
				prefix = L"[Critical] ";
				break;
			case FMT_ERROR:
				prefix = L"[Error] ";
				break;
			case FMT_WARNING:
				prefix = L"[Warning] ";
				break;
			case FMT_INIT:
				prefix = L"[Init] ";
				break;
			case FMT_EXIT:
				prefix = L"[Exit] ";
				break;
			case FMT_DEV:
				prefix = L"[Dev] ";
			default:
				break;
		}

		pipeMutex.Enter();

		fputws(prefix, stdout);
		fputws(text, stdout);
		fflush(stdout);

		pipeMutex.Leave();

	}

};
