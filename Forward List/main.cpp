#include <iostream>
#include "Forward_List.h"

int main(){
	Forward_List<int> list;

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.push_front(4);
	list.push_front(5);
	list.push_front(6);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;
	
	list.pop_front();
	list.pop_front();
	list.pop_front();

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.pop_front();
	list.pop_front();
	list.pop_front();

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	list.pop_front();
	list.pop_front();
	list.pop_front();

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;
	
	
	
	return 0;
}