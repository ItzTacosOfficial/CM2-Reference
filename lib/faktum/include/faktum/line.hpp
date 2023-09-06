#pragma once

#include "core.hpp"
#include "vector.hpp"


class FRay;

class FAK_IMPORT FLine {

public:

	FLine();
	FLine(const FLine& other);
	FLine(const FVector3& a, const FVector3& b);

	FLine& operator=(const FLine& other);

	float Distance(const FLine& line) const;
	float Distance(const FVector3& vec) const;
	FVector3 GetPoint(float t) const;
	BOOL Intersect(const FLine& line, float*);


	FVector3 a;
	FVector3 b;

};
FAK_SIZE_GUARD(FLine, 0x18);

class FAK_IMPORT FLineSeg {

	FLineSeg();
	FLineSeg(const FLineSeg& other);
	FLineSeg(const FVector3& a, const FVector3& b);

	FLineSeg& operator=(const FLineSeg& other);

	FVector3 GetEndPoint() const;
	FVector3 GetStartPoint() const;
	BOOL Intersect(const FRay&, float*, float, float);
	float Magnitude() const;
	float MagnitudeSquared() const;


	FVector3 a;
	FVector3 b;

};
FAK_SIZE_GUARD(FLineSeg, 0x18);
