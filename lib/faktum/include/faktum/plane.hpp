#pragma once

#include "core.hpp"


struct HALF;
class FVector3;
class FBox;
class FMatrix4;
class FLine;

class FAK_IMPORT FPlane {

public:

	FPlane();
	FPlane(const FPlane& other);
	FPlane(const FVector3&, const FVector3&, const FVector3&);
	FPlane(const FVector3&, const FVector3&);
	FPlane(const FVector3&);
	FPlane(const FVector3&, float);
	FPlane(float a, float b, float c, float d);
	FPlane(const float* data);
	FPlane(const HALF*);
	
	FPlane& operator=(const FPlane& other);
	BOOL operator==(const FPlane& other) const;
	BOOL operator!=(const FPlane& other) const;
	operator float*();
	operator const float*() const;
	FPlane operator*(float value) const;
	FPlane operator-() const;
	FPlane operator+() const;
	FPlane operator/(float value) const;
	FPlane& operator*=(float value);
	FPlane& operator/=(float value);

	BOOL CullBox(const FBox& box, const FMatrix4&) const;
	float Distance(const FVector3& vec) const;
	FPlane Flip() const;
	BOOL Intersect(const FPlane&, const FPlane&, FVector3*) const;
	BOOL Intersect(const FPlane&, FLine*) const;
	BOOL Intersect(const FLine&, float*) const;
	BOOL Intersect(const FLine&, FVector3*) const;
	float IntersectionDistance(const FLine&);
	FVector3 IntersectionPoint(const FPlane&, const FPlane&);
	FVector3 IntersectionPoint(const FLine&);
	FPlane& Normalize();
	FVector3 ProjectPoint(const FVector3&) const;
	FPlane Transform(const FMatrix4&) const;


	float a;
	float b;
	float c;
	float d;

};
FAK_SIZE_GUARD(FPlane, 0x10);


FAK_IMPORT FPlane* __stdcall FtPlaneFromPointNormal(FPlane*, const FVector3*, const FVector3*);
FAK_IMPORT FPlane* __stdcall FtPlaneFromPoints(FPlane*, const FVector3*, const FVector3*, const FVector3*);
FAK_IMPORT FVector3* __stdcall FtPlaneIntersectLine(FVector3*, const FPlane*, const FVector3*, const FVector3*);
FAK_IMPORT FLine* __stdcall FtPlaneIntersectPlane(FLine*, const FPlane*, const FPlane*);
FAK_IMPORT FVector3* __stdcall FtPlaneIntersectPlanes(FVector3*, const FPlane*, const FPlane*, const FPlane*);
FAK_IMPORT FPlane* __stdcall FtPlaneNormalize(FPlane*, const FPlane*);
FAK_IMPORT FPlane* __stdcall FtPlaneTransform(FPlane*, const FPlane*, const FMatrix4*);
