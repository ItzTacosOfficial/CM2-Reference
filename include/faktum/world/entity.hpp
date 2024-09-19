#pragma once

#include "faktum/api.hpp"
#include "faktum/mutate/mutable.hpp"



class FJoint;
class FSurface;
class FParticleSystem;
class FShader;
class FSoundDevice;
class FGeometry;
class FLight;
class FMaterial;


class FEntity : public FMutable {

public:

	struct EditorData {

	};


	FEntity();
	FEntity(FEntity const& other);

	~FEntity() override;

	FEntity& operator=(FEntity const& other);

	static void* __cdecl operator new(size_t, FObject*, FName const&, FName const&, unsigned int);

	void Serialize(FArchive&) override;
	void PropertyChanged(FProperty*) override;
	virtual void Tick(float, FInputDevice*, unsigned int);
	virtual void SetPosition(FVector3 const&);
	virtual void Spawned();
	virtual void Destroyed();
	virtual void ChildRemoved(FEntity*);
	virtual void JointRemoved(FJoint*);
	virtual void Start();
	virtual void Stop();
	virtual void Pause();
	virtual void Resume();
	virtual void PreDraw();
	virtual void PostDraw();
	virtual void Connect(FEntity*);
	virtual void Disconnect(FEntity*);
	//virtual void Contact(FObject*, FPhysicsDevice::Contact const*);
	//virtual void ContactModify(FObject*, FPhysicsDevice::ContactModify*);
	//virtual void Trigger(FObject*, FPhysicsDevice::Trigger const*);
	//virtual void PostRender(FCanvas*);
	virtual int Intersect(FFrustum const&);
	virtual int Intersect(FRay const&, float*);
	virtual int NearestSnap(FRay const&, float*);
	virtual int GetVertexCount() const;
	virtual FVector3 GetVertex(int) const;
	virtual int IsVertexSelected(int) const;
	virtual int PickVertices(FFrustum const&, int);
	virtual int PickVertices(FRay const&, int);
	//virtual void SetVerticesPivot(FVector3 const&);
	//virtual void SetVerticesPosition(FVector3 const&);
	virtual int GetSurfaceCount() const;
	virtual FSurface* GetSurface(int);
	virtual int IsSurfaceSelected(int) const;
	virtual int PickSurfaces(FRay const&, int);
	virtual void SetGroup(unsigned int);

	FParticleSystem* GetParticleSystem() const;
	FVector3 const& GetPosition() const;
	FQuaternion const& GetRotation() const;
	FVector3 const& GetScale() const;
	FShader* GetShader() const;
	FSoundDevice* GetSoundDevice();
	int GetTouchingZoneCount();
	FMatrix4 const& GetTransform();
	int GetZoneID();
	int IsLightTouchingZone(int);
	int IsSelected() const;
	int IsTouchingZone(int);
	FVector3 const& GetLinearAcc() const;
	int MakeSound(FSample*);
	int Destroy(int);
	FVector3 const& GetAngularAcc() const;
	FVector3 const& GetAngularVel() const;
	FBox const& GetBoundingBox();
	FGeometry* GetCollisionGeometry();
	FVector4 GetColor() const;
	EditorData* GetEditorData();
	void Select(int);
	unsigned int GetEntityFlags() const;
	void SetAngularAcc(FVector3 const&);
	void SetAngularVel(FVector3 const&);
	void SetBoundingBox(FBox const&);
	void SetCollisionGeometry(FGeometry*);
	void SetColor(FVector4&);
	void SetEntityFlags(unsigned int);
	void SetEntityPhysicsFlags(unsigned int);
	unsigned int GetEntityPhysicsFlags() const;
	void SetLight(FLight*);
	void SetLinearAcc(FVector3 const&);
	unsigned int GetGroup() const;
	void SetMaterial(FMaterial*);
	void SetMesh(FMesh*);
	void SetOwner(FEntity*);
	void SetParent(FEntity*);
	void SetParticleSystem(FParticleSystem*);
	FLevel* GetLevel() const;
	void SetRotation(FQuaternion const&);
	void SetScale(FVector3 const&);
	void SetShader(FShader*);
	FLight* GetLight() const;
	FVector3 const& GetLinearVel() const;
	FEntity* Spawn(FClass*, FName, FEntity*, FVector3 const&, FQuaternion const&, int);
	void SetLinearVel(FVector3 const&);
	FMaterial* GetMaterial();
	FMesh* GetMesh() const;
	FEntity* GetOwner() const;
	FEntity* GetParent() const;

	static FClass* StaticGetClass();
	static float StaticGetContactVelocity(FEntity*, FEntity*, FVector3 const&, FVector3 const&);
	static void StaticInitClass();
	static void StaticUnregisterClass();

	static int EventIDContactModify;
	static int EventIDTrigger;
	static int EventIDContact;


	unsigned int unk38[75];

protected:

	virtual void UpdateTransform();
	virtual void UpdateBoundingBox();

	void LoadDefaultShader();

private:

	static FClass* StaticConstructClassFEntity();
	static void StaticInitClassFEntity();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FEntity, 0x164);
