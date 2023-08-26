#include "Vector.h"

int main()
{
	Vector<int> vec;
	/*
	vec.push_back(1);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(2);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(3);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(4);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(5);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	
	vec.pop_back();
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	
	vec.push_back(5);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(6);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(7);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.push_back(8);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.insert(0,3);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.pop_back();
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	vec.erase(3);
	vec.print();
	std::cout << "\n" << vec.capacity() << " " << vec.size() << std::endl;
	*/

	while(vec.size() != 10){
		vec.push_back(rand()%90+10);
	}

	vec.print();
	std::cout << std::endl;

	// for (Vector<int>::Iterator it = vec.begin(); it != vec.end(); it++){
	// 	std::cout << *it << "\t";
	// }
	// std::cout << std::endl;

	// for (auto it : vec){
	// 	std::cout << it << "\t";
	// }
	// std::cout << std::endl;

	std::cout << vec.at(11) << std::endl;

	return 0;
}
