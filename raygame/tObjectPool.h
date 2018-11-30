#pragma once
#include"tVector.h"
template<typename T>
class tObjectPool
{
public:
	size_t arrCapacity;

	tObjectPool();                       // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~tObjectPool();                      // destroys all objects

	T* pool;                            // all objects stored in the pool
	bool* free;                         // indicates whether an object is available

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
inline tObjectPool<T>::tObjectPool()
{
	arrCapacity = 5;
	new T[arrCapacity];
	free = true;
}

template<typename T>
inline tObjectPool<T>::tObjectPool(size_t initialCapacity)
{
	arrCapacity = initialCapacity;
	new T[initialCapacity];
	free = true;
}

template<typename T>
inline tObjectPool<T>::~tObjectPool()
{
	delete pool;
}

template<typename T>
inline T * tObjectPool<T>::retrieve()
{
	for (int i = 0; i < arrCapacity; i++) 
	{
		if (free[i]) 
		{ 
			free[i] = false; 
			return *pool[i];
		}
	}
	return NULL;
}

template<typename T>
inline void tObjectPool<T>::recycle(T * obj)
{
	for (int i = 0; i < arrCapacity; i++)
	{
		if (obj == pool[i]) 
		{ 
			free[i] = true; 
			break; 
		}
	}
}

template<typename T>
inline size_t tObjectPool<T>::capacity()
{
	return arrCapacity;
}
