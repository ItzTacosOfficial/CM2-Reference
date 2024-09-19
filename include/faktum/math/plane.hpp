#pragma once

#include "faktum/api.hpp"



struct HALF;
class FVector3;
class FBox;
class FMatrix4;
class FLine;


class FPlane {

public:

	FPlane();
	FPlane(const FPlane& other);
	FPlane(const FVector3& a, const FVector3& b, const FVector3& c);
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
	BOOL Intersect(const FPlane& a, const FPlane& b, FVector3* out) const;
	BOOL Intersect(const FPlane& plane, FLine* out) const;
	BOOL Intersect(const FLine& line, float* out) const;
	BOOL Intersect(const FLine& line, FVector3* out) const;
	float IntersectionDistance(const FLine&);
	FVector3 IntersectionPoint(const FPlane&, const FPlane&);
	FVector3 IntersectionPoint(const FLine& line);
	FPlane& Normalize();
	FVector3 ProjectPoint(const FVector3& vec) const;
	FPlane Transform(const FMatrix4& mat) const;


	float a;
	float b;
	float c;
	float d;

};
FAK_SIZE_GUARD(FPlane, 0x10);


FAK_API FPlane* __stdcall FtPlaneFromPointNormal(FPlane*, const FVector3*, const FVector3*);
FAK_API FPlane* __stdcall FtPlaneFromPoints(FPlane* out, const FVector3* a, const FVector3* b, const FVector3* c);
FAK_API FVector3* __stdcall FtPlaneIntersectLine(FVector3* out, const FPlane* in, const FVector3* a, const FVector3* b);
FAK_API FLine* __stdcall FtPlaneIntersectPlane(FLine* out, const FPlane* a, const FPlane* b);
FAK_API FVector3* __stdcall FtPlaneIntersectPlanes(FVector3* out, const FPlane* a, const FPlane* b, const FPlane* c);
FAK_API FPlane* __stdcall FtPlaneNormalize(FPlane* out, const FPlane* in);
FAK_API FPlane* __stdcall FtPlaneTransform(FPlane* out, const FPlane* in, const FMatrix4* mat);
