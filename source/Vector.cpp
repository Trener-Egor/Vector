#include "Vector.hpp"

#include <iostream>
#include <stdexcept>

///namespace mv 
//{
void test_print()
{
	std::cout<<"b\n";
}



Vector::Vector()
{	
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

Vector::Vector(Vector&& other) 
{
	if (&other != this) 
	{	
		this->size_		= other.size_;
		this->capacity_ = other.capacity_;		
		this->data_     = other.data_;
		other.size_     = 0;
		other.capacity_ = 0;
		other.data_     = nullptr;
	}
}

Vector& Vector::operator=(Vector&& other)
{
	if (&other != this) 
	{
		this->size_ = other.size_;
		this->capacity_ = other.capacity_;
		this->data_ = other.data_;
		other.size_ = 0;
		other.capacity_ = 0;
		other.data_ = nullptr;
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
	return size_ == 0; 
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
	capacity_ = new_cap;
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
		capacity_ = size_;
		
	}
}

int&        Vector::front()          noexcept
{
	return data_[0];
}

const int&  Vector::front()    const noexcept
{
	return data_[0];
}

int&        Vector::back()           noexcept
{
	return data_[size_ - 1];
}

const int&  Vector::back()     const noexcept
{
	return data_[size_ - 1];
}

int*        Vector::data()			 noexcept
{
	return data_;
}

const int*  Vector::data()     const noexcept
{
	return data_;
}



int& Vector::at(std::size_t idx)
{
	if (idx >= size_) 
	{
		throw std::out_of_range("invaled index value");
	}
	return data_[idx];
}

const int& Vector::at(std::size_t idx) const 
{
	if (idx >= size_)
	{
		throw std::out_of_range("invaled index value");
	}
	return data_[idx];
}

int& Vector::operator[](std::size_t idx) noexcept
{
    return data_[idx];
}

const int& Vector::operator[](std::size_t idx) const noexcept 
{
    return data_[idx];
}

void Vector::push_back(int value) 
{
	if (capacity_ == size_) 
	{
		std::size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * VECTOR_SCALE;
		int* new_data = new int[new_cap];
		for (std::size_t i = 0; i < size_; ++i) 
		{
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
		capacity_ = new_cap;
	}
	data_[size_++] = value;
}

void Vector::pop_back() noexcept
{
	if (size_ != 0)
	{
		--size_;
	}
}


int* Vector::insert(std::size_t pos, int value)
{	
	if (pos > size_)
	{	
		return nullptr;
	}
	int* new_data = data_;

	if (size_ + 1 >=capacity_)
	{
		std:size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * VECTOR_SCALE;
		new_data = new int [new_cap];
		if (new_data == nullptr )
		{
			return nullptr;
		}
		capacity_ = new_cap;
	}
	for (std::size_t i = size_; i > pos; --i)
	{
		new_data[i] = data_[i - 1];
	}
	new_data[pos] = value;
	size_++;


	if (new_data != data_)
	{
		for (std::size_t i = 0; i < pos; ++i)
		{
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
	}
	return &(data_[pos]);
}

int* Vector::erase(std::size_t pos) 
{	
	if (pos < size_) 
	{
		for (std::size_t i = pos + 1; i < size_; i++) 
		{
			data_[i - 1] = data_[i];
		}
		size_--;

		if (pos != size_) 
		{
			return &(data_[pos]);
		}
	}
    return nullptr;
}

int* Vector::erase(std::size_t first, std::size_t last) 
{	
	if (last > first && first < size_)
	{	
		std::size_t r_elements = std::min(last,size_) - first;
		
		for (std::size_t j = 0; j < r_elements; j++)
		{	
			for (std::size_t i = first + 1; i < size_; i++)
			{
				data_[i - 1] = data_[i];
			}
			size_--;
		}

		if (first != size_)
		{
			return &(data_[first]);
		}
	}
    return nullptr;
}




//}//namespace mv

