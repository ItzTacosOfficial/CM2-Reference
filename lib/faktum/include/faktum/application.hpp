#pragma once

#include "core.hpp"
#include "object.hpp"


class FCanvas;
class FViewportManager;

class FAK_IMPORT FApplication : public FObject { // TODO Members

public:

	enum FAK_ASSUMED FLAG {
		Initialized	= 0x1,
		Ticking		= 0x2,
		Drawing		= 0x4,
		Unk8		= 0x8,
	};


	FApplication();
	FApplication(const FApplication& other);

	~FApplication() override;

	FApplication& operator=(const FApplication& other);

	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void ClearApplicationFlags(unsigned int mask);
	float GetFrameRateAverage() const;
	BOOL IsDrawing() const;
	BOOL IsRunning() const;
	BOOL IsTicking() const;
	void Quit(int exitCode);
	int Run();
	void SetFrameRateMaximum(float frameRate);

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	FLAG applicationFlags;
	FViewportManager* viewportManager;
	int unk2C;
	float maxFrameRate;
	int unk30[5];
	int exitCode;

protected:

	virtual BOOL Init();
	virtual void Exit();
	virtual void PreTick(float);
	virtual void PostTick(float);
	virtual void Tick(float, unsigned int);
	virtual void Render(FCanvas* canvas);

private:

	static FClass* StaticConstructClassFApplication();
	static void StaticInitClassFApplication();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FApplication, 0x50);
