#pragma once

#include "core.hpp"
#include "faktum/object.hpp"


class CM2Game;

class CM2_IMPORT CM2Automate : public FObject {

public:

	enum CM2_ASSUMED FLAG {
		Enabled		= 0x1,
		Benchmark	= 0x2,
		RunGame		= 0x4
	};


	CM2Automate();
	CM2Automate(const CM2Automate& other);

	~CM2Automate() override;

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	CM2Automate& operator=(const CM2Automate& other);

	void DisableRun();
	BOOL IsBenchmark();
	BOOL IsEnabled();
	BOOL IsRunGame();

	virtual void Init(CM2Game* game);
	virtual void Exit();
	virtual void Tick(float);
	virtual void DisplayFrame();

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticInitClass();
	static void __cdecl StaticUnregisterClass();


	FLAG automateFlags;
	CM2Game* game;

private:

	static FClass* __cdecl StaticConstructClassCM2Automate();
	static void __cdecl StaticInitClassCM2Automate();

	static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2Automate, 0x30);
