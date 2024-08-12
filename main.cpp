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
	int* pos1 = v1.insert(0, 5);
	
	if (pos1 != nullptr)
	{
		std::cout << "inserted:   " << v1[0] << " == " << *pos1 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}
	std::cout << "insert: (3, 5)\n"; 
	int* pos2 = v1.insert(3, 5);

	if (pos2 != nullptr)
	{
		std::cout << "inserted:   " << v1[3] << " == " << *pos2 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}
	std::cout << "insert: (size, 5)\n"; 
	int* pos3 = v1.insert(v1.size(), 5);

	if (pos3 != nullptr)
	{
		std::cout << "inserted:   " << v1[v1.size() - 1] << " == " << *pos3 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}
	std::cout << "insert: (-2, 5)\n"; 
	int* pos4 = v1.insert(-2, 5);

	if (pos4 != nullptr)
	{
		std::cout << "inserted:   " << v1[-2] << " == " << *pos4 << "\n"; 
	}
	else
	{
		std::cout << "not enserted\n";
	}

	std::cout << "front:       " << v1.front() << "\n";
	std::cout << "vector[0]:   " <<	v1[0]      << "\n";
	std::cout << "back:        " << v1.back()  << "\n";
	std::cout << "vector[-1]:  " <<	v1[v1.size() - 1]      << "\n";
	std::cout << "data:        " <<	v1.data()  << "\n";
	std::cout << "&vector[0]:  " <<	&v1[0]     << "\n";


	std::cout << "erase(0):  " << "\n";
	int* res1 = v1.erase(0);
	if (!res1) 
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";

	std::cout << "erase(size / 2): " << "\n";
	int* res2 = v1.erase(v1.size() / 2);
	if (!res2)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";

	std::cout << "erase(size - 1): " << "\n";
	int* res3 = v1.erase(v1.size() - 1);
	if (!res3)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";

	std::cout << "erase(size + 5): " << "\n";
	int* res4 = v1.erase(v1.size() + 5);
	if (!res4)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";



	std::cout << "erase(0, 3):  " << "\n";
	int* pos21 = v1.erase(0, 3);
	if (!pos21)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";

	std::cout << "erase(size / 2 , (size / 2) + 3): " << "\n";
	int* pos22 = v1.erase(v1.size() / 2, (v1.size() / 2) + 3);
	if (!pos22)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";

	std::cout << "erase(size - 1, size): " << "\n";
	int* pos23 = v1.erase(v1.size() - 1, v1.size());
	if (!pos23)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";

	std::cout << "erase(size + 5, 2): " << "\n";
	int* pos24 = v1.erase(v1.size() + 5, 2);
	if (!pos24)
	{
		std::cout << "end iterator\n";
	}
	std::cout << "vector:\n";
	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << "\n";
	return 0;
}
