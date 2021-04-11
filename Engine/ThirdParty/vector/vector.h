#pragma once
#include <cstddef> // std::size_t


// Copy and swap idiom
// See: https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
// 1. Create local copy, using the copy constructor
// 2. Swap old with new data
// 3. Destruct local (temporary) copy, which takes the old data with it

template <typename T>
class Vector
{
public:

	// Default constructor
	Vector() {}

	// Constructor with given size
	explicit Vector(std::size_t size)
	{
		resize(size);
	}

	// Constructor with size and default value
	Vector(std::size_t size, const T& val)
	{
		resize(size, val);
	}


	// Copy constructor
	Vector(const Vector<T>& other) : m_size(other.m_size), m_capacity(other.m_capacity)
	{
		// Allocate memory for new vector
		m_data = reinterpret_cast<T*>(new char[m_capacity * sizeof(T)]);
		// Copy data to new vector
		std::copy(other.m_data, other.m_data + m_size, m_data);
	}

	// Move contructor
	// Construct with default constructor and swap data with it
	Vector(Vector<T>&& other) : Vector()
	{
		swap(*this, other);
	}

	// Destructor
	~Vector()
	{
		// Call deconstructor for all elements
		for (std::size_t i = 0; i < m_size; i++)
			m_data[i].~T();
		// To delete memory, first convert it back to the type used for allocating the memory
		delete[] reinterpret_cast<char*>(m_data);
	}

	// Copy assignment
	// "other" not as reference -> copies and allocates data with copy constructor
	Vector<T>& operator=(Vector<T> other)
	{
		swap(*this, other);
		return *this;
	}

	T operator[](int i) const { return m_data[i]; }
	T& operator[](int i) { return m_data[i]; }



	/// <summary>
	/// Adds an element at the end of the internal array. If size exceeds current capacity, array will be extended by ~50%.
	/// </summary>
	/// <param name="element">- The element to be inserted.</param>
	void push_back(const T& element)
	{
		// If adding exceeds capacity, grow
		if ((m_size + 1) > m_capacity)
			reserve(m_size * 1.5 + 1);

		// Construct element at memory position 'm_data + m_size'
		new(m_data + m_size) T(element);
		m_size++;
	}

	/// <summary>
	/// Erases elements between 'from' (inclusive) and 'to' (exclusive). Will reallocate memory and close the gap.
	/// </summary>
	void erase(std::size_t from, std::size_t to)
	{
		// Call deconstructor for elements
		for (std::size_t i = from; i < to; i++)
			m_data[i].~T();

		T* temp = reinterpret_cast<T*>(new char[m_capacity * sizeof(T)]);

		// Move everything before range to temp
		std::move(m_data, m_data + from, temp);

		// Save old data
		T* oldData = m_data;
		std::size_t oldSize = m_size;

		// Swap data
		m_data = temp;
		m_size = from;

		// Move everything after range
		for (std::size_t i = to; i < oldSize; i++)
			push_back(oldData[i]);

		// Delete and free up old memory
		delete[] reinterpret_cast<char*>(oldData);
	}

	/// <summary>
	/// Erases one element at the given index. Will reallocate memory and close the gap.
	/// </summary>
	/// <param name="index">- Index of the element to be removed.</param>
	void erase(std::size_t index)
	{
		erase(index, index + 1);
	}

	/// <summary>
	/// Erases the element at the given index by swapping it with the last element.
	/// This will alter the order but does not require the reallocation of all elements after the index.
	/// </summary>
	/// <param name="index">- Index of the element to be removed.</param>
	void erase_by_swap(std::size_t index)
	{
		// Call deconstructor for element 
		m_data[index].~T();
		--m_size;

		// If no elements remaining, don't swap
		if (m_size < 1)
			return;

		// If last element erased, don't swap
		if (index == m_size)
			return;

		// Swap elements
		T temp = m_data[index];
		m_data[index] = m_data[m_size];
		m_data[m_size] = temp;

	}

	/// <summary>
	/// Allocates new memory and moves all elements to it. If given capacity is smaller than current capacity, this does nothing.
	/// Ensures that the capacity can hold the provided amount of elements.
	/// </summary>
	/// <param name="capacity">- The new capacity of the vector (number of elements that fit).</param>
	void reserve(std::size_t capacity)
	{
		// Skip if smaller than current capacity
		if (capacity < m_capacity)
			return;

		// Increase allocated memory
		m_capacity = capacity;
		T* temp = reinterpret_cast<T*>(new char[m_capacity * sizeof(T)]);
		// Move data to new memory
		if (m_data != nullptr) {
			std::move(m_data, m_data + m_size, temp);
			// Delete and free up old allocated memory
			delete[] reinterpret_cast<char*>(m_data);
		}
		m_data = temp;
	}

	/// <summary>
	/// Alters the SIZE of the vector. If bigger, it adds copies of the given element. If smaller, erases the last elements.
	/// </summary>
	/// <param name="size">- The new size of the vector.</param>
	/// <param name="val">- The element that will be copied.</param>
	void resize(std::size_t size, const T& val)
	{
		// If bigger than current capacity, reserve more
		// Prevents "push_back" to reserve multiple times
		if (size > m_capacity)
			reserve(size);

		// If bigger than current size, add elements with given value
		if (size > m_size)
		{
			std::size_t dif = size - m_size;
			for (std::size_t i = 0; i < dif; i++)
				push_back(val);
		}
		else if (size < m_size)
		{
			// If smaller than current size, remove (and destroy) elements at the end
			erase(size, m_size);
		}
	}

	/// <summary>
	/// Alters the SIZE of the vector. If bigger, it adds default values of the type. If smaller, erases the last elements.
	/// </summary>
	/// <param name="size">- The new size of the vector.</param>
	void resize(std::size_t size)
	{
		resize(size, T());
	}

	/// <summary>
	/// Returns the reference of the element at the given index.
	/// </summary>
	inline T& at(std::size_t index) { return m_data[index]; }

	/// <summary>
	/// Returns the number of elements inside the vector.
	/// </summary>
	inline std::size_t size() const { return m_size; }

	/// <summary>
	/// Returns the possible number of element with the current memory allocation.
	/// Anything exceeding this number will cause a reallocation of more memory.
	/// </summary>
	inline std::size_t capacity() const { return m_capacity; }

	/// <summary>
	/// Returns the pointer to the internal array.
	/// </summary>
	/// <returns></returns>
	inline T* as_array() const { return m_data; }

private:
	// Data/elements.
	T* m_data = nullptr;
	// Number of elements inside the vector.
	std::size_t m_size = 0;
	// Memory size, expressed in terms of elements (how many elements fit in the current allocated memory).
	std::size_t m_capacity = 0;

	/// <summary>
	/// Swaps the data between the given vectors using 'std::swap'.
	/// </summary>
	static void swap(Vector<T>& first, Vector<T>& second)
	{
		std::swap(first.m_data, second.m_data);
		std::swap(first.m_capacity, second.m_capacity);
		std::swap(first.m_size, second.m_size);
	}
};
