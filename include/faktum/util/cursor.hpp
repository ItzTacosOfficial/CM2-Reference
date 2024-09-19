#pragma once

#include "faktum/api.hpp"



class FCursor {

public:

	enum TYPE {
		TYPE_STANDARD = 1,
		TYPE_ANIMATED,
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
