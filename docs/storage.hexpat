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

enum Version : u32 {
    V2 = 0x20000,
    V3 = 0x30000
} [[format("fmtVersion")]];

fn fmtVersion(auto n) {
    return (n == Version::V2) ? "V2" : "V3";
};

struct HeaderCommon {

    type::Magic<"FAST"> magic;
    Version version;

};

struct HeaderV3 : HeaderCommon {

    u32 unk8;
    u32 unkC;
    u32 objectsCount;
    BOOL zipObjects;
    u64 objectsOffset;
    u32 objNamesCount;
    BOOL zipNames;
    u64 objNamesOffset;
    u32 classNamesCount;
    u32 unk34;
    u64 classNamesOffset;

};

struct Name {

    u32 length;
    u32 unk4;
    char string[length];

} [[format("fmtName")]];

fn fmtName(auto n) {
    return n.string;
};

struct ObjectInfoV3 {

    u32 nameIndex;
    u32 classIndex;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u64 dataOffset;
    u64 dataSize;
    u32 language;

};

struct ObjectV3 {

    ObjectInfoV3 info;

    std::Array<u8, info.dataSize> data @ info.dataOffset;

    str class = classNames[info.classIndex].string;
    str name = objectNames[info.nameIndex].string;

} [[
    name(std::format("({}) {}", class, name))
]];

struct StorageName {

    u8 length;
    char name[length];

};


HeaderCommon headerCommon @ 0x0 [[hidden]];

std::assert(headerCommon.version == Version::V3, "Unsupported version");

HeaderV3 header @ 0x0;

std::string::SizedString<u8> storageName @ 0x40;

Name objectNames[header.objNamesCount] @ header.objNamesOffset;
Name classNames[header.classNamesCount] @ header.classNamesOffset;
ObjectV3 objects[header.objectsCount] @ header.objectsOffset [[inline]];

std::print("Faktum Storage {}", header.version);

std::print("[{}] Names", header.objNamesCount);

for (u32 i = 0, i < header.objNamesCount, i = i + 1) {
    std::print("- {}", objectNames[i]);
}

std::print("[{}] Classes", header.classNamesCount);

for (u32 j = 0, j < header.classNamesCount, j = j + 1) {
    std::print("- {}", classNames[j]);
}

std::print("[{}] Objects", header.objectsCount);

for (u32 k = 0, k < header.objectsCount, k = k + 1) {
    std::print("- ({}) {}", objects[k].class, objects[k].name);
}