

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

	std::cout << "reserve:  (20) "  "\n";
	v1.reserve(20);
	std::cout << "size:     (15) " << v1.size()      << "\n";
	std::cout << "capacity: (20) " << v1.capacity()  << "\n";

	return 0;
}
