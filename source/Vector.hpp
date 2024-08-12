#pragma once

#include <cstddef>
#include <initializer_list>
//namespace mv
//{
void test_print();




class Vector
{
#define VECTOR_SCALE 1.5

public:	
	Vector();
	Vector(std::size_t size);
	Vector(std::size_t size, int value);
	Vector(std::initializer_list<int> list);
	
	Vector(const Vector& other);					
	Vector& operator=(const Vector& other);
	
	Vector(Vector&& other);
	Vector& operator=(Vector&& other);
	
	//[[nodiscard]] 
    std::size_t size()     const noexcept;
    std::size_t capacity() const noexcept;
    bool        empty()    const noexcept;     
    std::size_t max_size() const noexcept;
    void        reserve(std::size_t new_cap);
    void        shrink_to_feet();
	
	int&        front()          noexcept;
	const int&  front()    const noexcept;
	int&        back()           noexcept;
	const int&  back()     const noexcept;
	int*        data()			 noexcept;
	const int*  data()     const noexcept;

	int&        at(std::size_t idx);
	const int&  at(std::size_t idx) 		const;
	int&		operator[](std::size_t idx) 	  noexcept;
	const int&  operator[](std::size_t idx) const noexcept;

	void        push_back(int value);
	void        pop_back() 						  noexcept;
	int*        insert(std::size_t pos, int value);
	int*        erase(std::size_t pos);
    int*        erase(std::size_t first, std::size_t last);

private:
	int*        data_;
	std::size_t size_;
	std::size_t capacity_;
};

//}//namespace mv
