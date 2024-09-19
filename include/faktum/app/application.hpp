#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"



class FCanvas;
class FViewportManager;


class FApplication : public FObject {

public:

	enum FAK_ASSUMED FLAG {
		APP_INITIALIZED	= 0x1,
		APP_TICKING		= 0x2,
		APP_DRAWING		= 0x4,
		APP_UNK8		= 0x8,
	};


	FApplication();
	FApplication(const FApplication& other);

	~FApplication() override;

	FApplication& operator=(const FApplication& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

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


	int applicationFlags;
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

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FApplication, 0x50);
