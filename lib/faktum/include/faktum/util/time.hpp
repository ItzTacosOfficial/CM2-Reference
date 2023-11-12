#pragma once

#include "faktum/api.hpp"


class FString;

class FAK_API FTime {

public:

	struct DateTime {

		int sec;
		int min;
		int hour;
		int mday;
		int mon;
		int year;
		int wday;
		int yday;

	};
	FAK_SIZE_GUARD(DateTime, 0x20);


	FTime(const time_t& value);
	FTime(int, int, int, int);
	FTime(float);
	FTime();

	FTime& operator=(const FTime& other);
	FTime& operator=(const time_t& value);
	operator const time_t&() const;
	FTime operator-(const FTime& other) const;
	FTime operator-(const time_t& value) const;
	FTime operator+(const FTime& other) const;
	FTime operator+(const time_t& value) const;

	FString Format(const wchar_t* str) const;
	FString FormatGMT(const wchar_t* str) const;
	DateTime GetDateTime() const;
	DateTime GetDateTimeGMT() const;
	float Seconds() const;
	void SetDateTime(const DateTime& time) const;
	void SetDateTimeGMT(const DateTime& time) const;


	time_t value;

};
FAK_SIZE_GUARD(FTime, 0x8);
