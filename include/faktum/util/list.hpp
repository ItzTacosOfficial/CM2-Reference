#pragma once

#include "faktum/api.hpp"
#include "faktum/core/memmanager.hpp"
#include "faktum/core/assert.hpp"



template<class T>
class FAK_CUSTOM FTList {

public:

	FAK_EXTENSION using Type = T;

	struct FAK_ASSUMED Node {

		Node* next;
		Node* previous;
		Type data;

	};
	FAK_SIZE_GUARD(Node, 0x8 + sizeof(Type));

	struct Iterator {

		FTList* list;
		Node* node;

	};
	FAK_SIZE_GUARD(Iterator, 0x8);

	struct FAK_ASSUMED NodeBlock {

		NodeBlock* previous;
		Node nodes[];

	};


	inline ~FTList() {

		NodeBlock* ptr = block;

		while (ptr) {

			NodeBlock* previous = ptr->previous;

			FtGetMemManager()->Free(ptr);
			ptr = previous;

		}

		block = nullptr;
		end = nullptr;
		back = nullptr;
		front = nullptr;
		length = 0;

	}


	Node* front;
	Node* back;
	size_t length;
	Node* end; // Next free node
	NodeBlock* block;
	size_t blockLength;

};
