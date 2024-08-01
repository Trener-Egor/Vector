#pragma once

#include <cstddef>
#include <initializer_list>
//namespace mv
//{
void test_print();



class Vector
{
public:	
	Vector();
	Vector(std::size_t size);				// *
	Vector(std::size_t size, int value);	// *
	Vector(std::initializer_list<int> list);		
	
	std::size_t size() const noexcept;
	std::size_t capacity() const noexcept;
	bool empty() const noexcept;
	std::size_t max_size() const noexcept;
	void reserve(std::size_t nev_cap);
	void shrink_to_feet();

	// copy
	Vector(const Vector& other);					
	Vector& operator=(const Vector& other);
	// move
	//Vector(Vector&& other);
	//Vector& operator=(Vector&& other);

private:
	int*        data_;
	std::size_t size_;
	std::size_t capacity_;
};



//}//namespace mv

