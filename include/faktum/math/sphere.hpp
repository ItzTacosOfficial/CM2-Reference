#pragma once

#include "faktum/api.hpp"
#include "vector.hpp"



template<class T>
class FTArray;
class FCapsule;


class FSphere {

public:

	FSphere();
	FSphere(const FSphere& other);
	FSphere(const FVector3&, const FVector3&, const FVector3&, const FVector3&);
	FSphere(const FVector3&, const FVector3&, const FVector3&);
	FSphere(const FVector3&, const FVector3&);
	FSphere(const FVector3& pos, float r);
	FSphere(const FVector3*, int);

	FSphere& operator=(const FSphere& other);

	BOOL Contains(const FSphere& sphere) const;
	BOOL Contains(const FVector3& vec) const;
	unsigned int PushLines(FTArray<FVector3>&, unsigned int) const;


	FVector3 pos;
	float r;

};
FAK_SIZE_GUARD(FSphere, 0x10);


FAK_API BOOL FtSphereCapsuleOverlap(const FSphere*, const FCapsule*, float);
FAK_API BOOL FtSphereCapsuleOverlap(const FSphere*, const FMatrix4*, const FCapsule*, const FMatrix4*, float);
FAK_API FSphere* __stdcall FtSphereFromPoints(FSphere*, const FVector3*, const FVector3*, const FVector3*, const FVector3*, int);
FAK_API FSphere* __stdcall FtSphereFromPoints(FSphere*, const FVector3*, const FVector3*, const FVector3*, int);
FAK_API FSphere* __stdcall FtSphereFromPoints(FSphere*, const FVector3*, const FVector3*, int);
FAK_API FSphere* __stdcall FtSphereMinimum(FSphere*, const FVector3*, int);
FAK_API BOOL FtSphereSphereOverlap(const FSphere*, const FSphere*, float);
FAK_API BOOL FtSphereSphereOverlap(const FSphere*, const FMatrix4*, const FSphere*, const FMatrix4*, float);
