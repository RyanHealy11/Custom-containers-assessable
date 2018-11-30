#pragma once



template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();
	tVector(size_t usercap);            // initializes the vector's default values
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template<typename T>
inline tVector<T>::tVector()
{
	arrSize = 0;
	arrCapacity = 0;
	reserve(arrCapacity);
}


template<typename T>
inline tVector<T>::tVector(size_t usercap)
{
	arrSize = 0;
	reserve(arrCapacity);
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete[] arr;
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	if (!(newCapacity > arrCapacity)) { return; }
	T *temp = new T[newCapacity];
	
	for (size_t i = 0; i < arrSize; i++) 
	{
		temp[i] = arr[i];
	}
	arrCapacity = newCapacity;
	delete[] arr;
	arr = temp;
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity)
	{
		if (arrCapacity == 0) { reserve(1); }
		else { reserve(arrCapacity * GROWTH_FACTOR); }
	}
	
	arr[arrSize] = value;
	arrSize++;

}

template<typename T>
inline void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	return arr[index];
	// TODO: insert return statement here
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return arrCapacity;
}
