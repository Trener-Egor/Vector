#pragma once

#include <cstddef>

namespace mv
{
void test_print();



class Vector
{
public:	
	Vector();
	Vector(std::size_t size);				// *
	Vector(std::size_t size, int value);	// *
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



}//namespace mv

