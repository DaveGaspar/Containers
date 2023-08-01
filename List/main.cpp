#include <iostream>
#include "List.h"

int main(){
	List<int> list;

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.add(1);
	list.add(2);
	list.add(3);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.add(4);
	list.add(5);
	list.add(6);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;
	return 0;
}