#pragma once

template<typename  T>
class Array
{
	T* data;
	size_t size;
public:
	Array(size_t size) : data(new T[size]), size(size){}

	Array(const Array<T>& other) : Array(other.size)
	{
		for(int i = 0;i < other.size;i++)
		{
			this->data[i] = other.data[i];
		}
	}

	Array<T>& operator=(Array<T> copy)
	{
		
		std::swap(this->data,copy.data);
		std::swap(this->size,copy.size);
		return *this;
	}

	T& operator[](size_t index) const
	{
		return data[index];
	}

	size_t getSize() const
	{
		return this->size;
	}

	T* begin()
	{
		return this->data;
	}

	T* end()
	{
		return this->data + this->size;
	}

	~Array()
	{
		delete[] this->data;
		this->data = nullptr;
	}
};