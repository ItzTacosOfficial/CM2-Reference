#pragma once

#include "faktum/api.hpp"



class FRefCount {

public:

	FRefCount();
	FRefCount(const FRefCount& other);

	virtual ~FRefCount();

	void Release();
	void AddRef();


	int refCount;

};
FAK_SIZE_GUARD(FRefCount, 0x8);
