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
};

struct FObject {
    u32 language;
    u32 flags;
};


struct FMeshNormal {
    padding[4 * 4];
};

u32 _vertexIdx;
u32 _vertexCount;

struct FMeshVertex<auto Vertices, auto Normals, auto Tangents, auto PointSizes, auto Weights> {
    if (Vertices) {
        FVector3 pos;
    }
    if (Normals) {
        u32 normalsCount;
        u32;
        u32;
        u32;
        u32;
        std::print("count: {} [{}/{}]", normalsCount, _vertexIdx, _vertexCount);
        _vertexIdx = _vertexIdx + 1;
        if (normalsCount > 1) {
            FMeshNormal normal[normalsCount];
        }
    }
    if (Tangents) {
        
    }
    if (PointSizes) {
    
    }
    if (Weights) {
    
    }
};

struct FMesh : FObject {

    u32;
    BOOL supportVertices;
    BOOL supportNormals;
    BOOL supportTangentSpace;
    BOOL supportPointSizes;
    BOOL supportWeights;
    u32 vertexCount;
    
    _vertexCount = vertexCount;
    
    FMeshVertex<
        supportVertices, supportNormals, supportTangentSpace, supportPointSizes, supportWeights
    > vertices[vertexCount];
    
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


FBlob data @ 0x8 [[inline]];