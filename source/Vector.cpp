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



}//namespace mv

