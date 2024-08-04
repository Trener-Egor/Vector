

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


	return 0;
}
