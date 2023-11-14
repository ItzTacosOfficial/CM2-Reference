#pragma once

#include "faktum/api.hpp"
#include "faktum/core/memmanager.hpp"
#include "faktum/core/assert.hpp"


template<class T>
class FAK_CUSTOM FTArray {

public:

	FAK_EXTENSION using Type = T;

	FAK_EXTENSION static constexpr size_t TypeSize = sizeof(T);


	inline FTArray(size_t bufferLength = 0, size_t allocationStep = 8) : length(0), bufferLength(bufferLength), allocationStep(allocationStep), buffer() {
		Reserve(bufferLength);
	}

	inline FTArray(const FTArray& other) : buffer(), length(other.length), bufferLength(other.bufferLength), allocationStep(other.allocationStep) {

		AllocateBuffer(bufferLength);

		FtGetMemManager()->Copy(buffer, other.buffer, length * TypeSize);

	}

	inline ~FTArray() {

		if (buffer) {
			FtGetMemManager()->Free(buffer);
		}

	}


	inline T& operator[](size_t index) {
		return GetAt(index);
	}

	inline const T& operator[](size_t index) const {
		return GetAt(index);
	}


	inline size_t GetLength() const {
		return length;
	}

	inline size_t GetBufferLength() const {
		return bufferLength;
	}

	inline size_t GetAllocationStep() const {
		return allocationStep;
	}

	inline T* GetBuffer() const {
		return buffer;
	}

	inline BOOL IsEmpty() const {
		return length == 0;
	}

	inline T& GetAt(size_t index) {

		FAK_ASSERT(index < length, L"Subscript out of range");

		return buffer[index];

	}

	inline const T& GetAt(size_t index) const {

		FAK_ASSERT(index < length, L"Subscript out of range");

		return buffer[index];

	}

	inline void Reserve(size_t size) {
		AllocateBuffer(size);
	}

	inline void PushBack(const T& value) {

		if (length + 1 > bufferLength) {
			AllocateBuffer(length + allocationStep);
		}

		buffer[length++] = value;

	}


	size_t length;
	size_t bufferLength;
	size_t allocationStep;
	T* buffer;

private:

	inline void AllocateBuffer(size_t size) {

		if (size < bufferLength) {
			return;
		}

		if (buffer) {
			buffer = static_cast<T*>(FtGetMemManager()->Realloc(buffer, size * TypeSize, L"FTArray::buffer"));
		} else {
			buffer = static_cast<T*>(FtGetMemManager()->Alloc(size * TypeSize, L"FTArray::buffer"));
		}

		bufferLength = size;

	}

};
