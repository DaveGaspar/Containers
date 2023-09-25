#include <iostream>
#include "List.h"

int main(){
	List<int> list;

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.push_back(4);
	list.push_back(5);
	list.push_back(6);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.pop_back();

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.pop_front();

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;



	return 0;
}