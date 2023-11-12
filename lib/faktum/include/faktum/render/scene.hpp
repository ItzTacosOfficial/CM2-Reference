#pragma once

#include "faktum/api.hpp"


class FGraphicsDevice;
class FFrustum;
class FVector3;
class FMatrix4;
class FCamera;
class FEnvironment;

class FAK_API FScene {

public:

	enum TYPE {}; // TODO Contents


	FScene();
	FScene(const FScene& other);
	FScene(FGraphicsDevice* graphicsDevice, const FFrustum& frustum, const FVector3&, int);
	FScene(FGraphicsDevice* graphicsDevice, const FMatrix4&, const FMatrix4&);
	FScene(FGraphicsDevice* graphicsDevice, FCamera* camera);

	~FScene();

	FScene& operator=(const FScene& other);

	FScene* GetChild() const;
	FEnvironment* GetEnvironment() const;
	const FFrustum& GetFrustum() const;
	FGraphicsDevice* GetGraphicsDevice() const;
	float GetHeight() const;
	FScene* GetParent() const;
	const FMatrix4* GetProjectionMatrixInversePtr() const;
	const FMatrix4* GetProjectionMatrixPtr() const;
	FScene* GetSibling() const;
	TYPE GetType() const;
	const FMatrix4* GetViewMatrixInversePtr() const;
	const FMatrix4* GetViewMatrixPtr() const;
	const FMatrix4* GetViewProjectionMatrixInversePtr() const;
	const FMatrix4* GetViewProjectionMatrixPtr() const;
	float GetWidth() const;
	float GetZFar() const;
	float GetZNear() const;
	int GetZoneID() const;
	void Init(FGraphicsDevice* graphicsDevice, const FFrustum& frustum, const FVector3&, int);
	void Init(FGraphicsDevice* graphicsDevice, FCamera* camera);
	BOOL IsOrthogonal() const;
	void SetChild(FScene* child);
	void SetEnvironment(FEnvironment* environment);
	void SetFrustum(const FFrustum& frustum);
	void SetParent(FScene* parent);
	void SetSibling(FScene* sibling);
	void SetType(TYPE type);
	void SetZoneID(int zoneID);

};
//FAK_SIZE_GUARD(FScene, );
