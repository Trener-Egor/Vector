

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "./source/Vector.hpp"


int main()
{	
	using namespace mv;
	std::cout << "a\n";
	mv::test_print();
	
	mv::Vector v1(15,8);
	std::cout<< v1.size() << ' ' << v1.capacity() <<"\n";

	return 0;
}
