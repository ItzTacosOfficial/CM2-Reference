#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"



class FGraphicsDevice;
class FFont;
class FSize;
class FVector2;
class FRect;
class FBone;
class FMatrix4;
class FBoneCluster;
class FBox;
class FVector4;
class FColor;
class FVector3;
class FMesh;
class FSphere;


class FCanvas : public FObject {

public:

	class DrawTextCache {

    public:

    	enum TYPE {};


		DrawTextCache();
		DrawTextCache(DrawTextCache const& other);

		~DrawTextCache();

		DrawTextCache& operator=(DrawTextCache const& other);

		void Build(wchar_t const*, unsigned int, FFont*, FSize const&, unsigned int);
		void SetLineLength(unsigned int, unsigned int);
		int GetCharColumn(int);
		int GetCharIndex(int, int);
		int GetCharRow(int);
		void SetLinePixel(unsigned int, unsigned int);
		int GetCharacterIndex(FVector2 const&);
		FVector2 GetCharacterPosition(int);
		FRect GetCharacterRect(int);
		FFont* GetFont();
		unsigned int GetFormat();
		unsigned int GetLineBeginChar(unsigned int);
		int GetLineCount();
		unsigned int GetLineLength(unsigned int);
		unsigned int GetLinePixel(unsigned int);
		int GetSelectionIndex(int);
		wchar_t const* GetText() const;
		int GetTextIndex(int);
		int GetWordEnd(int);
		int GetWordStart(int);
		void Reset();
		void SetLineBeginChar(unsigned int, unsigned int);

		static int StaticCompareCharacters(void const*, void const*, void*);

    protected:

		void BuildMesh(FSize const&);
		TYPE GetCharType(wchar_t c) const;

    };



	FCanvas();
	FCanvas(FCanvas const& other);
	FCanvas(FGraphicsDevice* graphicsDevice);

	~FCanvas() override;

	FCanvas& operator=(FCanvas const&);

	using FObject::operator new;
	using FObject::operator delete;
	static void* __cdecl operator new(unsigned int, FObject*, FName const&, FName const&, unsigned int);

	void DrawBone(FBone*, FMatrix4, FMatrix4 const&);
	void DrawBoneCluster(FBoneCluster*, FMatrix4 const&);
	void DrawBox(FBox const&, FMatrix4 const&, FVector4 const&);
	void DrawGrid(FVector2 const&, unsigned int, unsigned int, unsigned int, unsigned int, FMatrix4 const&, FColor, FColor, FColor);
	void DrawLines(FVector3*, unsigned int, FMatrix4, FColor);
	void DrawMesh(FMesh*, FMatrix4 const&, FColor const&, int);
	void DrawSphere(FSphere const&, FMatrix4 const&, FVector4 const&, unsigned int);
	void DrawTextW(DrawTextCache*, FMatrix4 const&, FVector4 const&);
	void DrawTextW(wchar_t const*, unsigned int, FFont*, FRect const&, unsigned int, FVector4 const&);
	FGraphicsDevice* GetGraphicsDevice();
	unsigned int GetHeight() const;
	FFont* GetSmallBoldFont();
	FFont* GetSmallFont();

	unsigned int GetWidth() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


    unsigned int unk2C[14];

protected:

	static int StaticCompareCharacters(void const*, void const*, void*);

private:

	static FClass* StaticConstructClassFCanvas();
	static void StaticInitClassFCanvas();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FCanvas, 0x60);
