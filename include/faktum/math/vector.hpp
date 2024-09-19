#pragma once

#include "faktum/api.hpp"



struct HALF;
class FMatrix4;


class FVector2 {

public:

	FVector2();
	FVector2(const FVector2& other);
	FVector2(float x, float y);
	FVector2(const float* data);
	FVector2(const HALF*);

	FVector2& operator=(const FVector2& other);
	BOOL operator==(const FVector2& other) const;
	BOOL operator!=(const FVector2& other) const;
	float& operator[](unsigned int index);
	operator float*();
	operator const float*() const;
	FVector2 operator*(const FVector2& vec) const;
	FVector2 operator*(float value) const;
	FVector2 operator-(const FVector2& vec) const;
	FVector2 operator-() const;
	FVector2 operator+(const FVector2& vec) const;
	FVector2 operator+() const;
	FVector2 operator/(const FVector2& vec) const;
	FVector2 operator/(float value) const;
	float operator|(const FVector2& vec) const;
	FVector2& operator*=(float value);
	FVector2& operator+=(const FVector2& vec);
	FVector2& operator-=(const FVector2& vec);
	FVector2& operator/=(float value);

	BOOL IsZero() const;
	float Magnitude() const;
	float MagnitudeSquared() const;
	FVector2& Normalize();
	FVector2& NormalizeUnsafe();

	static FVector2 StaticRand(float);
	static FVector2 StaticRand();


	float x;
	float y;

};
FAK_SIZE_GUARD(FVector2, 0x8);


class FVector3 {

public:

	FVector3();
	FVector3(const FVector3& other);
	FVector3(float x, float y, float z);
	FVector3(const float* data);
	FVector3(const HALF*);

	FVector3& operator=(const FVector3& other);
	BOOL operator==(const FVector3& other) const;
	BOOL operator!=(const FVector3& other) const;
	float& operator[](int index);
	operator float*();
	operator const float*() const;
	FVector3 operator*(const FVector3& vec) const;
	FVector3 operator*(float value) const;
	FVector3 operator-(const FVector3& vec) const;
	FVector3 operator-() const;
	FVector3 operator+(const FVector3& vec) const;
	FVector3 operator+() const;
	FVector3 operator/(const FVector3& vec) const;
	FVector3 operator/(float value) const;
	FVector3 operator^(const FVector3& vec) const;
	float operator|(const FVector3& vec) const;
	FVector3& operator*=(float value);
	FVector3& operator+=(const FVector3& vec);
	FVector3& operator-=(const FVector3& vec);
	FVector3& operator/=(float value);
	FVector3& operator^=(const FVector3& vec);

	float Distance(const FVector3& vec) const;
	float DistanceSquared(const FVector3& vec) const;
	BOOL IsZero() const;
	float Magnitude() const;
	float MagnitudeSquared() const;
	FVector3& Normalize();
	FVector3& NormalizeUnsafe();

	static FVector3 StaticRand(float);
	static FVector3 StaticRand();


	float x;
	float y;
	float z;

};
FAK_SIZE_GUARD(FVector3, 0xC);


class FVector4 {

public:

	FVector4();
	FVector4(const FVector3& vec);
	FVector4(const FVector3& vec, float w);
	FVector4(float x, float y, float z, float w);
	FVector4(const float* data);
	FVector4(const HALF*);

	FVector4& operator=(const FVector4& other);
	BOOL operator==(const FVector4& other) const;
	BOOL operator!=(const FVector4& other) const;
	float& operator[](unsigned int index);
	operator float*();
	operator const float*() const;
	FVector4 operator*(const FVector4& vec) const;
	FVector4 operator*(float value) const;
	FVector4 operator-(const FVector4& vec) const;
	FVector4 operator-() const;
	FVector4 operator+(const FVector4& vec) const;
	FVector4 operator+() const;
	FVector4 operator/(const FVector4& vec) const;
	FVector4 operator/(float value) const;
	float operator|(const FVector4& vec) const;
	FVector4& operator*=(float value);
	FVector4& operator+=(const FVector4& vec);
	FVector4& operator-=(const FVector4& vec);
	FVector4& operator/=(float value);

	BOOL IsZero() const;
	float Magnitude() const;
	float MagnitudeSquared() const;
	FVector4& Normalize();
	FVector4& NormalizeUnsafe();


	float x;
	float y;
	float z;
	float w;

};
FAK_SIZE_GUARD(FVector4, 0x10);


FAK_API float FtDistanceTriPoint(const FVector3& a, const FVector3& b, const FVector3& c, const FVector3& point);
FAK_API BOOL FtIntersectTriTri(const FVector3& a0, const FVector3& b0, const FVector3& c0, const FVector3& a1, const FVector3& b1, const FVector3& c1);
FAK_API FVector2* __stdcall FtVec2Normalize(FVector2* out, const FVector2* in);
FAK_API FVector2* __stdcall FtVec2NormalizeUnsafe(FVector2* out, const FVector2* in);
FAK_API FVector4* __stdcall FtVec2Transform(FVector4* out, const FVector2* in, const FMatrix4* mat);
FAK_API FVector2* __stdcall FtVec2TransformCoord(FVector2* out, const FVector2* in, const FMatrix4* mat);
FAK_API FVector2* __stdcall FtVec2TransformNormal(FVector2* out, const FVector2* in, const FMatrix4* mat);
FAK_API FVector3* __stdcall FtVec3Normalize(FVector3* out, const FVector3* in);
FAK_API FVector3* __stdcall FtVec3NormalizeUnsafe(FVector3* out, const FVector3* in);
FAK_API FVector4* __stdcall FtVec3Transform(FVector4* out, const FVector3* in, const FMatrix4* mat);
FAK_API FVector3* __stdcall FtVec3TransformCoord(FVector3* out, const FVector3* in, const FMatrix4* mat);
FAK_API FVector3* __stdcall FtVec3TransformNormal(FVector3* out, const FVector3* in, const FMatrix4* mat);
FAK_API FVector4* __stdcall FtVec4Normalize(FVector4* out, const FVector4* in);
FAK_API FVector4* __stdcall FtVec4NormalizeUnsafe(FVector4* out, const FVector4* in);
FAK_API FVector4* __stdcall FtVec4Transform(FVector4* out, const FVector4* in, const FMatrix4* mat);

FAK_API float _FtVectorLineSegDist(const FVector3&, const FVector3&, const FVector3&, float);
