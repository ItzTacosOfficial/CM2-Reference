#include <std/sys.pat>
#include <type/magic.pat>
#include <std/array.pat>
#include <std/string.pat>


enum BOOL : u32 {
    FALSE = 0,
    TRUE = 1,
} [[format("fmtBOOL")]];

fn fmtBOOL(auto n) {
    return (n == BOOL::FALSE) ? "FALSE" : "TRUE";
};


struct FVector3 {
    float x;
    float y;
    float z;
} [[single_color]];


struct FObject {
    u32 objLanguage;
    u32 objFlags;
};


struct FMeshNormalEntry {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct FMeshWeightEntry {
    u32 nameIndex;
    u32 a;
    u32 b;
};

struct FMeshVertex<auto Vertex, auto Normal, auto PointSize, auto Weight> {
    if (bool(Vertex)) {
        FVector3 vertex;
    }
    if (bool(Normal)) {
        u32 x10;
        FVector3 normal;
        u32 normalsCount;
        FMeshNormalEntry normals[normalsCount];
    }
    if (bool(PointSize)) {
        float pointSize;
    }
    if (bool(Weight)) {
        u32 weightsCount;
        FMeshWeightEntry weights[weightsCount];
    }
};

struct FMeshChannelEntry1 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct FMeshChannelEntry2 {
    u32 a;
    u32 b;
    u32 c;
};

struct FMeshChannel {
    u32 x0;
    u32 entriesCount_1;
    FMeshChannelEntry1 entries_1[entriesCount_1];
    u32 entriesCount_2;
    FMeshChannelEntry2 entries_2[entriesCount_2];
};

struct FMeshFace<auto Flag> {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
    if (bool(Flag)) {
        u32 a_e;
        u32 b_e;
        u32 c_e;
    }
};

struct FMesh : FObject {

    u32 flags;
    BOOL sVertices;
    BOOL sNormals;
    BOOL sTangentSpace;
    BOOL sPointSizes;
    BOOL sWeights;
    
    u32 vertexCount;
    FMeshVertex<sVertices, sNormals, sPointSizes, sWeights> vertices[vertexCount];
    
    u32 channelsCount;
    FMeshChannel channels[channelsCount];
    
    u32 facesCount;
    BOOL someBool;
    FMeshFace<someBool> faces[facesCount];
    
};


enum FSample_FORMAT : u32 {
    Raw = 2,
    Ogg = 3
};

struct FSample : FObject {
    u32;
    u32 frequency;
    u32;
    FSample_FORMAT format;
    u32 dataSize;
    u32 rawSize;
    u8 data[dataSize];
};


struct FText : FObject {
    u32 length;
    char16 string[length];
};


struct FBlob : FObject {
    u32 size;
    u8 data[size];
};


FMesh data @ 0x8 [[inline]];
