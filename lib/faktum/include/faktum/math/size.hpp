#pragma once

#include "faktum/api.hpp"


class FVector2;

class FAK_API FSize {

public:

	FSize(float width, float height);
	FSize();

	FSize& operator=(const FSize& other);
	BOOL operator==(const FSize& other) const;
	BOOL operator!=(const FSize& other) const;
	operator FVector2() const;
	FSize operator-(const FSize& other) const;
	FSize operator+(const FSize& other) const;
	FSize operator+=(const FSize& other);
	FSize operator-=(const FSize& other);

	float Area() const;
	BOOL IsZero() const;


	float width;
	float height;

};
FAK_SIZE_GUARD(FSize, 0x8);
