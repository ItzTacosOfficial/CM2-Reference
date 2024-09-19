#pragma once

// Includes


// Forward declarations

class /* Attributes */ FWorld : /* Bases */ {

public:

	FWorld(FWorld const&);
	FWorld();

	virtual ~FWorld();

	FWorld& operator=(FWorld const&);

	static void* __cdecl operator new(unsigned int, FObject*, FName const&, FName const&, unsigned int);

	virtual void Build(unsigned int, int (__cdecl*)(float, wchar_t const*, void*), void*);
	virtual FPolygon* FindPolygon(unsigned int);
	virtual FMesh* GetCollisionMesh() const;
	virtual void Update(FCamera*);
	virtual FVector3 GetNodeCenter(int);
	virtual int GetNodeCount() const;
	virtual int GetNodeID(FVector3 const&);
	virtual FPolygon* GetPolygon(unsigned int);
	virtual unsigned int GetPolygonCount();
	virtual Primitive const* GetPrimitive(int, unsigned int);
	virtual unsigned int GetPrimitiveCount(int);
	virtual void GetSelectedPolygons(FTArray<FPolygon*>&);
	virtual Zone const* GetStartZone();
	virtual FSurface* GetSurface(int) const;
	virtual int GetSurfaceCount() const;
	virtual FMesh* GetSurfaceSelectionMesh();
	virtual unsigned int GetVisibleFaceCount() const;
	virtual int GetZoneCount() const;
	virtual int GetZoneID(FVector3 const&);
	virtual int GetZones(FBox const&, FMatrix4 const&, FTArray<int>&, int);
	virtual int IsPath(FVector3 const&, FVector3 const&);
	virtual int IsZoneVisible(int) const;
	virtual void PickPolygon(FRay const&, unsigned int);
	virtual FSurface* PickSurface(FRay const&);
	virtual void SelectAllSurfaces(int);
	virtual void SelectSurface(FSurface*, int);
	virtual int SetDirtyZone(int);
	virtual void SetSurfaceShader(FSurface*, FShader*);

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

protected:

	FLevel* GetLevel() const;

private:

	static void __cdecl StaticInitClassFWorld();
	static FClass* __cdecl StaticConstructClassFWorld();

	static FClass* ms_pClass;

};
_SIZE_GUARD(FWorld, /* Size */);
