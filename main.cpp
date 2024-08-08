

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "./source/Vector.hpp"


int main()
{	
	// tests
	Vector v1(15,8);
	std::cout << "size:     (15) " << v1.size()      << "\n";
	std::cout << "capacity: (15) " << v1.capacity()  << "\n";
	std::cout << "empty: (false) " << std::boolalpha 
		                           << v1.empty()     << "\n";
	std::cout << "reserve:  (10) " <<  "\n";
	v1.reserve(10);
	std::cout << "size:     (15) " << v1.size()      << "\n";
	std::cout << "capacity: (15) " << v1.capacity()  << "\n";

	std::cout << "reserve:  (20) " << "\n";
	v1.reserve(20);
	std::cout << "size:     (15) " << v1.size()      << "\n";
	std::cout << "capacity: (20) " << v1.capacity()  << "\n";
	

	for (int i = 0; i < 6; ++i) 
	{	
		int e = rand() % 100;
		std::cout << "push_back:  (" << e << ")\n";
		v1.push_back(e);
		std::cout << "size:     (15) "   << v1.size() << "\n";
		std::cout << "capacity: (20) "   << v1.capacity() << "\n";

		std::cout << "vector:\n";
		for (std::size_t j = 0; j < v1.size(); ++j) 
		{
			std::cout << v1[j] << ' ';
		}
		std::cout << "\n";
	}
	std::cout << "insert: (0, 5)\n"; 
	int* res1 = v1.insert(0, 5);
	
	if (res1 != nullptr)
	{
		std::cout << "inserted:   " << v1[0] << " == " << *res1 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}


	std::cout << "insert: (3, 5)\n"; 
	int* res2 = v1.insert(3, 5);

	if (res2 != nullptr)
	{
		std::cout << "inserted:   " << v1[3] << " == " << *res2 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}
	std::cout << "insert: (size, 5)\n"; 
	int* res3 = v1.insert(v1.size(), 5);

	if (res3 != nullptr)
	{
		std::cout << "inserted:   " << v1[v1.size() - 1] << " == " << *res3 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}
	std::cout << "insert: (-2, 5)\n"; 
	int* res4 = v1.insert(-2, 5);

	if (res4 != nullptr)
	{
		std::cout << "inserted:   " << v1[-2] << " == " << *res4 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}
	
	return 0;
}
