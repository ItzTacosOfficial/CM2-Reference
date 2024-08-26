#pragma once

#include "faktum/api.hpp"
#include "resource.hpp"
#include "faktum/math/box.hpp"
#include "faktum/math/sphere.hpp"
#include "faktum/util/array.hpp"
#include "faktum/math/matrix4.hpp"


class FMatrix4;
class FVector3;
class FVector4;
class FSpline;
class FBezierSurface;
class FPolyLine;
class FFrustum;
class FRay;
class FMorphAnimation;
class FBoneCluster;

class FMesh : public FResource {

public:

	enum CHANNEL;

	struct Tri {

		unsigned int indices[3];

	};
	FAK_SIZE_GUARD(Tri, 0xC);

	struct FAK_ASSUMED Tag {

		FName name;
		FMatrix4 transform;

	};
	FAK_SIZE_GUARD(Tag, 0x44);

	struct FAK_ASSUMED Channel {

		CHANNEL type;
		int vertexCount;
		int maxVertexCount;
		FVector4* vertices;
		int triCount;
		int maxTriCount;
		Tri* tris;

	};
	FAK_SIZE_GUARD(Channel, 0x1C);

	struct FAK_ASSUMED Tangent {

		FVector3 tangent;
		int unkC;
		FVector3 binormal;
		int unk1C;

	};
	FAK_SIZE_GUARD(Tangent, 0x20);

	struct Edge {

		int unk0[8];

	};
	FAK_SIZE_GUARD(Edge, 0x20);

	struct Face {

		unsigned int indices[3];
		int* unkC;
		int unk10;

	};
	FAK_SIZE_GUARD(Face, 0x14);

	struct NVertex {

		int entriesCount;
		FVector3 vector;
		int unk10;
		FVector4* entries;

	};
	FAK_SIZE_GUARD(NVertex, 0x18);

	struct FAK_ASSUMED WeightEntry {

		FName name;
		int unk4;
		int unk8;

	};
	FAK_SIZE_GUARD(WeightEntry, 0xC);

	struct Weight {

		int entriesCount;
		WeightEntry* entries;

	};
	FAK_SIZE_GUARD(Weight, 0x8);

	struct MorphTarget {};

	enum FAK_ASSUMED FLAG {
		FLAG_RENDER_DATA		= 0x20000,
		FLAG_BOUNDING_BOX		= 0x40000,
		FLAG_BOUNDING_SPHERE	= 0x80000
	};

	enum CHANNEL {
		CHANNEL_UV			= 0x1,
		CHANNEL_NORMAL		= 0x10000,
		CHANNEL_TANGENT 	= 0x20000,
		CHANNEL_BINORMAL	= 0x40000
	};


	FMesh();
	FMesh(const FMesh& other);

	~FMesh() override;

	FMesh& operator=(const FMesh& other);
	FMesh operator-(const FMesh& other);
	FMesh operator+(const FMesh& other);
	FMesh operator/(const FMesh& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Serialize(FArchive& archive) override;

	void AddTag(char* name, const FMatrix4& transform);
	float AngleBetweenFaces(int a, int b) const;
	FVector3 AverageNormal(int index); // Verify
	BOOL Blend(FMesh* mesh, int, int, float factor);
	void BuildEdgeData();
	void BuildNormals();
	void BuildRenderData();
	BOOL BuildTangentSpace(int channel);
	void Exit();
	FVector3 FaceCenter(int index) const;
	FVector3 FaceNormal(int index, BOOL normalize) const;
	int FindEdge(int a, int b); // Verify
	FVector3& GetBiNormal(int index);
	const FBox& GetBoundingBox();
	const FSphere& GetBoundingSphere();
	int GetChannelCount() const;
	int GetChannelFaceCount(int channel) const;
	Tri* GetChannelFacePtr(int channel, int index);
	CHANNEL GetChannelType(int channel) const;
	FVector4& GetChannelVertex(int channel, int index);
	int GetChannelVertexCount(int channel) const;
	FVector4* GetChannelVertexPtr(int channel, int index);
	int GetEdgeCount() const;
	Edge* GetEdgePtr(int index);
	int GetFaceCount() const;
	Face* GetFacePtr(int index);
	int GetMaxChannelFaceCount(int channel) const;
	int GetMaxChannelVertexCount(int channel) const;
	int GetMaxFaceCount() const;
	int GetMaxVertexCount() const;
	unsigned int GetMeshFlags();
	FMesh* GetMorphTarget(int index) const;
	int GetMorphTargetCount() const;
	FVector3& GetNormal(int index, unsigned int);
	NVertex* GetNormalPtr(int index);
	FVector3& GetRBiNormal(int index);
	int GetRIndexCount() const;
	unsigned int* GetRIndexPtr() const;
	FVector3& GetRNormal(int index);
	FVector3& GetRTangent(int index);
	FVector4& GetRTexCoord(int, int);
	int GetRTexCoordCount() const;
	FVector3& GetRVertex(int index);
	int GetRVertexCount() const;
	int GetRVertexIndex(int index);
	FVector3* GetRVertexPtr(int index);
	int GetTagCount();
	const FName& GetTagName(int index);
	const FMatrix4& GetTagTransform(int index);
	FVector3& GetTangent(int index);
	FVector3& GetVertex(int index);
	int GetVertexCount() const;
	FVector3* GetVertexPtr(int index);
	Weight* GetVertexWeightPtr(int index) const;
	BOOL HasNormals() const;
	BOOL HasPointSizes() const;
	BOOL HasTangentSpace() const;
	BOOL HasWeights() const;
	void Init(FSpline&, unsigned int, float, const FVector3&);
	void Init(FBezierSurface*, unsigned int, unsigned int);
	void InitCone(float, float, unsigned int);
	void InitCylinder(float, float, unsigned int);
	void InitExtrusion(const FVector3*, unsigned int, FPolyLine&);
	void InitExtrusion(const FVector3*, unsigned int, FSpline&, unsigned int);
	void InitPlane(float, float, unsigned int, unsigned int, int);
	void InitQuad(float, float);
	void InitSphere(float, unsigned int, unsigned int);
	void InitSprites(unsigned int);
	BOOL Intersect(const FMatrix4&, const FFrustum&);
	BOOL Intersect(const FMatrix4&, const FRay&, float*);
	BOOL Morph(FMesh*, MorphTarget*, int);
	BOOL Morph(FMesh*, FMorphAnimation*);
	int NearestTag(const FMatrix4&, const FRay&, float*);
	FVector3 RandomEdgePoint() const;
	FVector3 RandomSurfacePoint() const;
	FVector3 RandomVolumePoint() const;
	int AddMorphTarget(const FName& name);
	void SetBiNormal(int index, const FVector3& vector);
	void SetBoneCount(int count, BOOL setMax);
	void SetBoneName(int index, const FName& name); // Defunct
	void SetChannelCount(int count);
	void SetChannelFaceCount(int channel, int count, BOOL setMax);
	void SetChannelType(int channel, CHANNEL type);
	void SetChannelVertex(int channel, int index, const FVector4& vector);
	void SetChannelVertexCount(int channel, int count, BOOL setMax);
	void SetFaceCount(int count, BOOL setMax);
	void SetMaxBoneCount(int count);
	void SetMaxChannelFaceCount(int channel, int count);
	void SetMaxChannelVertexCount(int channel, int count);
	void SetMaxFaceCount(int count);
	void SetMaxVertexCount(int count);
	void SetMeshFlags(unsigned int flags);
	void SetNormal(int index, const FVector3& vector);
	void SetTangent(int index, const FVector3& vector);
	void SetVertex(int index, const FVector3& vector);
	void SetVertexCount(int count, BOOL setMax);
	void SetVertexWeightCount(int index, int count);
	BOOL Skin(FMesh*, const FBoneCluster*, const FBoneCluster*);
	void SupportNormals(BOOL value);
	void SupportPointSizes(BOOL value);
	void SupportTangentSpace(BOOL value);
	void SupportWeights(BOOL value);

	static void StaticUnregisterClass();
	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticInitClass();


	int meshFlags;
	int vertexCount;
	FVector3* vertices;
	NVertex* normals;
	Tangent* tangents;
	float* pointSizes;
	Weight* weights;
	int channelCount;
	Channel* channels;
	int faceCount;
	Face* faces;
	Tri* tris;
	int tagsCount;
	Tag* tags;
	int boneCount;
	FTArray<FMesh*> morphTargets;
	int maxVertexCount;
	int maxFaceCount;
	int maxBoneCount;
	int edgesCount;
	Edge* edges;
	FBox boundingBox;
	FSphere boundingSphere;
	int unkB8;
	int unkBC;
	int unkC0;
	int unkC4;
	int unkC8;
	int unkCC;
	int unkD0;
	int unkD4;
	int* renderData;

private:

	static void StaticInitClassFMesh();
	static FClass* StaticConstructClassFMesh();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FMesh, 0xE0);
