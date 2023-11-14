#pragma once

#include "faktum/api.hpp"


struct HALF;
class FVector3;
class FQuaternion;

class FMatrix4 { // TODO HALF

public:

	FMatrix4();
	FMatrix4(const FMatrix4& other);
	FMatrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	FMatrix4(const float* data);
	FMatrix4(const HALF*);

	FMatrix4& operator=(const FMatrix4& other);
	BOOL operator==(const FMatrix4& other) const;
	BOOL operator!=(const FMatrix4& other) const;
	operator float*();
	operator const float*() const;
	FMatrix4 operator*(const FMatrix4& mat) const;
	FMatrix4 operator*(float value) const;
	FMatrix4 operator-(const FMatrix4& mat) const;
	FMatrix4 operator-() const;
	FMatrix4 operator+(const FMatrix4& mat) const;
	FMatrix4 operator+() const;
	FMatrix4 operator/(float value) const;
	float& operator()(unsigned int column, unsigned int row); // Multidimensional subscript
	float operator()(unsigned int column, unsigned int row) const; // Multidimensional subscript
	FMatrix4& operator*=(const FMatrix4& mat);
	FMatrix4& operator*=(float value);
	FMatrix4& operator+=(const FMatrix4& mat);
	FMatrix4& operator-=(const FMatrix4& mat);
	FMatrix4& operator/=(float value);

	FMatrix4& BlendParameter(const FMatrix4&, const FMatrix4&, float);
	float Determinant();
	FMatrix4& Exponential();
	FMatrix4& Identity();
	FMatrix4& Inverse();
	FMatrix4& Lerp(const FMatrix4& start, const FMatrix4& end, float factor);
	FMatrix4& Logarithm();
	void LookAt(const FVector3& position, const FVector3& target, const FVector3& up);
	float Norm();
	void Ortho(float, float, float, float);
	void PerspectiveFov(float, float, float, float);
	FMatrix4& Pow(int exponent);
	FMatrix4& RotationAxisAngle(const FVector3&, float);
	FMatrix4& RotationDirection(const FVector3&);
	FMatrix4& RotationQuaternion(const FQuaternion&);
	FMatrix4& RotationX(float value);
	FMatrix4& RotationY(float value);
	FMatrix4& RotationYawPitchRoll(const FVector3& vec);
	FMatrix4& RotationYawPitchRoll(float yaw, float pitch, float roll);
	FMatrix4& RotationZ(float value);
	FMatrix4& Scaling(const FVector3& vec);
	FMatrix4& Scaling(float x, float y, float z);
	FMatrix4& SquareRoot();
	FMatrix4& Transformation(const FVector3&, const FVector3&, const FVector3&, const FVector3&);
	FMatrix4& Translation(const FVector3& vec);
	FMatrix4& Translation(float x, float y, float z);
	FMatrix4& Transpose();
	FMatrix4& Zero();

	FAK_API static const FMatrix4 IDENTITY;


	float m[4][4];

};
FAK_SIZE_GUARD(FMatrix4, 0x40);


FAK_API float __stdcall FtMatrixDeterminant(const FMatrix4*);
FAK_API FMatrix4* __stdcall FtMatrixInverse(FMatrix4*, float*, const FMatrix4*);
FAK_API FMatrix4* __stdcall FtMatrixMultiply(FMatrix4*, const FMatrix4*, const FMatrix4*);
FAK_API FMatrix4* __stdcall FtMatrixMultiplyTranspose(FMatrix4*, const FMatrix4*, const FMatrix4*);
FAK_API FMatrix4* __stdcall FtMatrixRotationAxis(FMatrix4*, const FVector3*, float);
FAK_API FMatrix4* __stdcall FtMatrixRotationQuaternion(FMatrix4*, const FQuaternion*);
FAK_API FMatrix4* __stdcall FtMatrixRotationX(FMatrix4*, float);
FAK_API FMatrix4* __stdcall FtMatrixRotationY(FMatrix4*, float);
FAK_API FMatrix4* __stdcall FtMatrixRotationYawPitchRoll(FMatrix4*, float, float, float);
FAK_API FMatrix4* __stdcall FtMatrixRotationZ(FMatrix4*, float);
FAK_API FMatrix4* __stdcall FtMatrixScaling(FMatrix4*, float, float, float);
FAK_API FMatrix4* __stdcall FtMatrixTranslation(FMatrix4*, float, float, float);
FAK_API FMatrix4* __stdcall FtMatrixTranspose(FMatrix4*, const FMatrix4*);
