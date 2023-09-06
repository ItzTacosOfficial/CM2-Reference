#pragma once

#include "core.hpp"


struct HALF;
class FVector3;
class FMatrix4;

class FAK_IMPORT FQuaternion {

public:

	FQuaternion();
	FQuaternion(float x, float y, float z, float w);
	FQuaternion(const float* data);
	FQuaternion(const HALF*);

	FQuaternion& operator=(const FQuaternion& other);
	BOOL operator==(const FQuaternion& other) const;
	BOOL operator!=(const FQuaternion& other) const;
	operator float*();
	operator const float*() const;
	FQuaternion operator*(const FQuaternion& quat) const;
	FQuaternion operator*(float value) const;
	FQuaternion operator-(const FQuaternion& quat) const;
	FQuaternion operator-() const;
	FQuaternion operator+(const FQuaternion& quat) const;
	FQuaternion operator+() const;
	FQuaternion operator/(float value) const;
	float operator|(const FQuaternion& quat) const;
	FQuaternion& operator*=(const FQuaternion& quat);
	FQuaternion& operator*=(float value);
	FQuaternion& operator+=(const FQuaternion& quat);
	FQuaternion& operator-=(const FQuaternion& quat);
	FQuaternion& operator/=(float value);

	FQuaternion& Conjugate();
	FQuaternion& Inverse();
	float Magnitude();
	float MagnitudeSquared();
	FQuaternion& Normalize();
	FQuaternion& RotationAxisAngle(const FVector3& axis, float angle);
	FQuaternion& RotationMatrix(const FMatrix4& mat);
	FQuaternion& RotationYawPitchRoll(float yaw, float pitch, float roll);
	void ToAxisAngle(FVector3* axis, float* angle);
	FVector3 ToYawPitchRoll() const;


	float x;
	float y;
	float z;
	float w;

};
FAK_SIZE_GUARD(FQuaternion, 0x10);


FAK_IMPORT FQuaternion* __stdcall FtQuaternionInverse(FQuaternion*, const FQuaternion*);
FAK_IMPORT FQuaternion* __stdcall FtQuaternionMultiply(FQuaternion*, const FQuaternion*, const FQuaternion*);
FAK_IMPORT FQuaternion* __stdcall FtQuaternionNormalize(FQuaternion*, const FQuaternion*);
FAK_IMPORT FQuaternion* __stdcall FtQuaternionRotationAxis(FQuaternion*, const FVector3*, float);
FAK_IMPORT FQuaternion* __stdcall FtQuaternionRotationMatrix(FQuaternion*, const FMatrix4*);
FAK_IMPORT FQuaternion* __stdcall FtQuaternionRotationYawPitchRoll(FQuaternion*, float, float, float);
FAK_IMPORT FQuaternion* __stdcall FtQuaternionSlerp(FQuaternion*, FQuaternion*, FQuaternion*, float);
FAK_IMPORT void __stdcall FtQuaternionToAxisAngle(const FQuaternion*, FVector3*, float*);
