#pragma once

// Includes


// Forward declarations

class /* Attributes */ FLevel : /* Bases */ {

public:

	FLevel(FLevel const&);
	FLevel(FClass*);

	virtual ~FLevel();

	FLevel& operator=(FLevel const&);

	static void* __cdecl operator new(unsigned int, FObject*, FName const&, FName const&, unsigned int);

	virtual int MoveEntity();
	virtual FObject* Clone(FName const&, FName const&, FObject*, int);
	virtual FEntity* CloneEntity(FEntity*, FName);
	virtual int DestroyEntity(FEntity*, int);
	virtual int PickEntities(FFrustum const&, FTArray<FEntity*>&, int);
	virtual FEntity* PickEntity(FRay const&, float*, int);
	virtual int PickSurfaces(FRay const&, int);
	virtual int PickVertices(FFrustum const&, int);
	virtual int PickVertices(FRay const&, int);
	virtual void PostLoad();
	virtual void Serialize(FArchive&);
	virtual SnapInfo SnapEntity(FRay const&);
	virtual int SnapEntity(FEntity*, unsigned int, FEntity*, unsigned int);
	virtual FEntity* SpawnEntity(FEntity*, FEntity*, FVector3 const&, FQuaternion const&, int);
	virtual FEntity* SpawnEntity(FClass*, FName, FEntity*, FVector3 const&, FQuaternion const&, int);
	virtual void Tick(float, FInputDevice*, unsigned int);

	FGame* GetGame() const;
	unsigned int GetLevelFlags() const;
	FNavigationPointCache* GetNavigationPointCache();
	FWorld* GetWorld() const;
	int IsEditor();
	int IsPaused();
	void Modify(wchar_t const*);
	void Pause();
	FPhysicsDevice* GetPhysicsDevice() const;
	void AddParticleSystem(FParticleSystem*);
	void Backup(FMemArchive*);
	Iterator Begin(FClass*, unsigned int);
	void Build(unsigned int, int (__cdecl*)(float, wchar_t const*, void*), void*);
	void CleanupDestroyedEntities();
	void PostTick(float);
	void PreTick(float);
	int Redo(int);
	void RemoveParticleSystem(FParticleSystem*);
	void Restore(FMemArchive*);
	void Resume();
	void ClearHistory();
	void SetGame(FGame*);
	void SetLevelFlags(unsigned int);
	void Empty();
	void EnableEditor(int);
	Iterator End(FClass*, unsigned int);
	FEntity* Find(FName const&);
	void Start();
	void Stop();
	FCamera* GetCamera() const;
	int Undo(int);

	static void __cdecl StaticUnregisterClass();
	static void __cdecl StaticConstructor(void*);
	static FClass* __cdecl StaticGetClass();

private:

	static void __cdecl StaticInitClassFLevel();
	static FClass* __cdecl StaticConstructClassFLevel();

	static FClass* ms_pClass;

};
_SIZE_GUARD(FLevel, /* Size */);
