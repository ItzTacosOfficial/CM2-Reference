#pragma once

#include "faktum/api.hpp"
#include "faktum/util/array.hpp"
#include "vector.hpp"



class FCapsule {

public:

	FCapsule();
	FCapsule(const FCapsule& other);
	FCapsule(float, float);

	FCapsule& operator=(const FCapsule& other);

	unsigned int PushLines(FTArray<FVector3>& points, unsigned int) const;


	FVector3 unk0;
	float unkC;
	float unk10;

};
FAK_SIZE_GUARD(FCapsule, 0x14);


class FCapsuleNEW {

public:

	FCapsuleNEW();
	FCapsuleNEW(const FCapsuleNEW& other);
	FCapsuleNEW(const FVector3& unk0, const FVector3& unkC, float unk18);

	FCapsuleNEW& operator=(const FCapsuleNEW& other);


	FVector3 unk0;
	FVector3 unkC;
	float unk18;

};
FAK_SIZE_GUARD(FCapsuleNEW, 0x1C);


FAK_API BOOL FtCapsuleCapsuleOverlap(const FCapsule*, const FCapsule*, float);
FAK_API BOOL FtCapsuleCapsuleOverlap(const FCapsule*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
