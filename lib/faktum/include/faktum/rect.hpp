#pragma once

#include "core.hpp"
#include "vector.hpp"


class FAK_IMPORT FRect {

public:

	FRect();
	FRect(const FVector2& a, const FVector2& b);
	FRect(float x0, float y0, float x1, float y1);
	
	FRect& operator=(const FRect& other);
	FRect operator+=(const FVector2&);
	FRect operator-=(const FVector2&);

	float Area() const;
	FVector2 BottomLeft() const;
	FVector2 BottomRight() const;
	FVector2 Center() const;
	FRect Clip(const FRect& rect);
	void Deflate(const FRect& rect);
	void Deflate(float x0, float y0, float x1, float y1);
	float Height() const;
	void Inflate(const FRect& rect);
	void Inflate(float x0, float y0, float x1, float y1);
	BOOL Intersection(const FRect& rect) const;
	BOOL IsZero() const;
	void MoveTo(const FVector2& vec);
	void MoveTo(float x, float y);
	void Normalize();
	void Offset(const FVector2& vec);
	void Offset(float x, float y);
	BOOL PointInRect(const FVector2& vec) const;
	FSize Size() const;
	FVector2 TopLeft() const;
	FVector2 TopRight() const;
	float Width() const;


	FVector2 a;
	FVector2 b;

};
FAK_SIZE_GUARD(FRect, 0x10);
