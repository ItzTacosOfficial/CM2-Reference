#pragma once

#include "core.hpp"
#include "vector.hpp"


template<class T>
class FTArray;
class FCapsule;
class FSphere;

class FAK_IMPORT FBox { // TODO Functions, verify members

public:

	FBox();
	FBox(const FBox& other);
	FBox(const FVector3& a, const FVector3& b);

	FBox& operator=(const FBox& other);

	BOOL Overlap(const FBox& box) const;
	unsigned int PushLines(FTArray<FVector3>& array) const;


	FVector3 a;
	FVector3 b;

};
FAK_SIZE_GUARD(FBox, 0x18);


FAK_IMPORT BOOL __cdecl FtBoxBoxOverlap(const FBox*, const FBox*, float);
FAK_IMPORT BOOL __cdecl FtBoxBoxOverlap(const FBox*, const FMatrix4*, const FBox*, const FMatrix4*, float);
FAK_IMPORT BOOL __cdecl FtBoxCapsuleOverlap(const FBox*, const FCapsule*, float);
FAK_IMPORT BOOL __cdecl FtBoxCapsuleOverlap(const FBox*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
FAK_IMPORT BOOL __cdecl FtBoxSphereOverlap(const FBox*, const FMatrix4*, const FSphere*, const FMatrix4*, float);
FAK_IMPORT BOOL __cdecl FtBoxSphereOverlap(const FBox*, const FSphere*, float);
