#pragma once

#include "faktum/api.hpp"
#include "vector.hpp"



class FRay {

public:

	FRay();
	FRay(const FRay& other);
	FRay(const FVector3& a, const FVector3& b);

	FRay& operator=(const FRay& other);

	float Distance(const FVector3& vec) const;
	FVector3 GetOrigin() const;


	FVector3 origin;
	FVector3 target;

};
FAK_SIZE_GUARD(FRay, 0x18);
