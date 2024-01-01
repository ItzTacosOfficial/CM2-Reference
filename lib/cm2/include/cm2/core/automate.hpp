#pragma once

#include "cm2/api.hpp"
#include "faktum/object.hpp"


class CM2Game;

class CM2Automate : public FObject {

public:

	enum CM2_ASSUMED FLAG {
		ENABLED		= 0x1,
		BENCHMARK	= 0x2,
		RUNGAME		= 0x4
	};


	CM2Automate();
	CM2Automate(const CM2Automate& other);

	~CM2Automate() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	CM2Automate& operator=(const CM2Automate& other);

	void DisableRun();
	BOOL IsBenchmark();
	BOOL IsEnabled();
	BOOL IsRunGame();

	virtual void Init(CM2Game* game);
	virtual void Exit();
	virtual void Tick(float);
	virtual void DisplayFrame();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	int flags;
	CM2Game* game;

private:

	static FClass* StaticConstructClassCM2Automate();
	static void StaticInitClassCM2Automate();

	static FClass* ms_pClass;

};
CM2_SIZE_GUARD(CM2Automate, 0x30);
