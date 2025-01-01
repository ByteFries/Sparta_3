#pragma once
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class SimpleVector
{
public:
	SimpleVector(int size = 10) :data(nullptr), currentSize(0), currentCapacity(0) { reserve(size); }

	SimpleVector(const SimpleVector<T>& origin)
	{
		currentSize = origin.currentSize;
		currentCapacity = origin.currentCapacity;
		data = new T[currentCapacity];

		for (int i = 0; i < currentSize; i++)
		{
			data[i] = origin.data[i];
		}
	}

	~SimpleVector() { if (data) delete[] data; }

	template<typename Comp = std::less<T>>
	void sortData(Comp comp = Comp());

	void push_back(const T& value);
	void pop_back()
	{
		if (currentSize > 0) currentSize--;
	}

	void resize(unsigned int size);
	void reserve(unsigned int size);

	int size() { return currentSize; }
	int capacity() { return currentCapacity; }

	T& operator[](unsigned int index) 
	{ 
		if (index >= currentSize)  throw std::out_of_range("인덱스가 범위를 벗어남");
		return data[index]; 
	}

	SimpleVector<T>& operator=(const SimpleVector<T>& origin)
	{
		if (this == &origin) return; //자기 복사 방지

		currentSize = origin.currentSize;
		currentCapacity = origin.currentCapacity;

		delete[] data;
		data = new T[currentCapacity];

		for (int i = 0; i < currentSize; i++)
		{
			data[i] = origin.data[i];
		}
	}

private:
	T* data;
	int currentSize;
	int currentCapacity;
};

template<typename T>
template<typename Comp>
inline void SimpleVector<T>::sortData(Comp comp)
{
	sort(data, data + currentSize, comp);
}

template<typename T>
inline void SimpleVector<T>::push_back(const T& value)
{
	if (currentCapacity == 0) reserve(1);
	else if (currentSize == currentCapacity) reserve(currentCapacity * 2);

	data[currentSize++] = value;
}

template<typename T>
inline void SimpleVector<T>::resize(unsigned int size)
{
	if (size <= currentSize) return;
	if (currentCapacity < size) reserve(size);

	for (;currentSize < size; currentSize++)
	{
		data[currentSize] = T();
	}
}

template<typename T>
inline void SimpleVector<T>::reserve(unsigned int size)
{
	if (size <= currentCapacity) return;

	T* newData = new T[size];

	for (int i = 0; i < currentSize; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;

	currentCapacity = size;
}