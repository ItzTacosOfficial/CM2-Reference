#pragma once

#include "core.hpp"
#include "vector.hpp"


class FAK_IMPORT FCapsule { // TODO Functions, verify members

public:

	FCapsule();
	FCapsule(const FCapsule& other);
	FCapsule(float, float);

	FCapsule& operator=(const FCapsule& other);

	//unsigned int PushLines(class FTArray<class FVector3> &,unsigned int) const;


	FVector3 unk0;
	float unkC;
	float unk10;

};
FAK_SIZE_GUARD(FCapsule, 0x14);

class FAK_IMPORT FCapsuleNEW { // TODO Verify members

public:

	FCapsuleNEW();
	FCapsuleNEW(const FCapsuleNEW& other);
	FCapsuleNEW(const FVector3&, const FVector3&, float);

	FCapsuleNEW& operator=(const FCapsuleNEW& other);


	FVector3 unk0;
	FVector3 unkC;
	float unk18;

};
FAK_SIZE_GUARD(FCapsuleNEW, 0x1C);


FAK_IMPORT BOOL __cdecl FtCapsuleCapsuleOverlap(const FCapsule*, const FCapsule*, float);
FAK_IMPORT BOOL __cdecl FtCapsuleCapsuleOverlap(const FCapsule*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
