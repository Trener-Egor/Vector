#include "Vector.hpp"

#include <iostream>

namespace mv 
{
void test_print()
{
	std::cout<<"b\n";
}



Vector::Vector()
{
	data_     = nullptr;
	size_     = 0;
	capacity_ = 0;
}


Vector::Vector(std::size_t size)
{
	data_ = new int[size];
	if (!data_)
	{
		return;
	}
	size_     = size;
	capacity_ = size;
}


Vector::Vector(std::size_t size, int value)
{
	data_ = new int[size];
	if (!data_)
	{
		return;
	}
	size_     = size;
	capacity_ = size;

	for (std::size_t i = 0; i < size; ++i)
	{
		data_[i] = value;						// * memset
	}

}

Vector::Vector(std::initializer_list<int> list)
{
	//vector vec{1,3,4,5}; 
	data_ = new int[list.size()];
	if (data_)
	{
		return;
	}
	std::size_t i = 0;

	for (auto v : list)							// * tamplate type & ?
	{
		data_[i++] = v;}
}


Vector::Vector(const Vector& other)
{
	if (this != &other)
	{
		data_ = new int[other.size_];			// * size()
		
		for (std::size_t i = 0; i < other.size_ ; ++i)
		{
			this->data_[i] = other.data_[i];
		}
		size_      = other.size_;
		capacity_ = other.capacity_;
	}
}

Vector& Vector::operator= (const Vector& other)
{
	if (this != &other)
	{
		data_ = new int[other.size_];


		for (std::size_t i = 0; i < other.size_; ++i)
		{
			this->data_[i] = other.data_[i];	
		}
		size_     = other.size_;
		capacity_ = other.capacity_;
	}
	return *this;
}

std::size_t Vector::size() const noexcept
{
	return size_;
}

std::size_t Vector::capacity() const noexcept
{
	return capacity_;
}

bool Vector::empty() const noexcept
{
	return size == 0; 
}

std::size_t Vector::max_size() const noexcept
{
	return 1;
}

void Vector::reserve(std::size_t new_cap)
{
	if (new_cap <= capacity_)
	{
		return;
	}
	int* new_data = new int [new_cap];
	//TODO
	for (std::size_t i = 0; i < size_; ++i)
	{
		new_data[i] = data_[i]; 
	}
	delete[] data_;
	data_ = new_data;
	capacity = new_cap;
}

void Vector::shrink_to_feet()
{
	std::size_t unused = capacity_ - size_;
	if (static_cast<float>(unused) / capacity_ > 0.25)
	{
		int* new_data = new int [size_];
		//TODO
		for (std::size_t i = 0; i < size_; ++i)
		{
			new_data[i] = data_[i]; 
		}
		delete[] data_;
		data_ = new_data;
		capacity = size_;
		
	}
}
}//namespace mv

