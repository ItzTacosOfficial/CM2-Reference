#pragma once

#include "faktum/api.hpp"


class FAK_API FCursor {

public:

	enum TYPE {
		STANDARD = 1,
		ANIMATED,
	};


	FCursor();

	~FCursor();

	FCursor& operator=(const FCursor& other);

	void Exit();
	void* GetHandle() const;
	BOOL Init(void* data, unsigned int size, TYPE type);
	BOOL Init(const wchar_t* path);


	HCURSOR handle;

};
FAK_SIZE_GUARD(FCursor, 0x4);
