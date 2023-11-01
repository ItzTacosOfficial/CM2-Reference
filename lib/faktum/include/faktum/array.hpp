#pragma once

#include "core.hpp"
#include "memmanager.hpp"


template<class T>
class FTArray {

public:

	FAK_EXTENSION using Type = T;

	FAK_EXTENSION static constexpr size_t TypeSize = sizeof(T);


	FAK_ASSUMED inline FTArray() : length(0), bufferLength(0), allocationStep(8), buffer() {}

	FAK_ASSUMED inline FTArray(size_t bufferLength, size_t allocationStep = 8) : length(0), bufferLength(bufferLength), allocationStep(allocationStep), buffer() {
		Reserve(bufferLength);
	}

	FAK_ASSUMED inline FTArray(const FTArray& other) : buffer(), length(other.length), bufferLength(other.bufferLength), allocationStep(other.allocationStep) {

		AllocateBuffer(bufferLength);

		FtGetMemManager()->Copy(buffer, other.buffer, length * TypeSize);

	}

	FAK_ASSUMED inline ~FTArray() {

		if (buffer) {
			FtGetMemManager()->Free(buffer);
		}

	}


	FAK_ASSUMED inline T& operator[](size_t index) {
		return GetAt(index);
	}

	FAK_ASSUMED inline const T& operator[](size_t index) const {
		return GetAt(index);
	}


	FAK_ASSUMED inline size_t GetLength() const {
		return length;
	}

	FAK_ASSUMED inline size_t GetBufferLength() const {
		return bufferLength;
	}

	FAK_ASSUMED inline size_t GetAllocationStep() const {
		return allocationStep;
	}

	FAK_ASSUMED inline T* GetBuffer() const {
		return buffer;
	}

	FAK_ASSUMED inline BOOL IsEmpty() const {
		return length == 0;
	}

	FAK_ASSUMED inline T& GetAt(size_t index) {

		FAK_ASSERT(index < length, L"Subscript out of range");

		return buffer[index];

	}

	FAK_ASSUMED inline const T& GetAt(size_t index) const {

		FAK_ASSERT(index < length, L"Subscript out of range");

		return buffer[index];

	}

	FAK_ASSUMED inline void Reserve(size_t size) {
		AllocateBuffer(size);
	}

	FAK_ASSUMED inline void PushBack(const T& value) {

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

	FAK_ASSUMED inline void AllocateBuffer(size_t size) {

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
