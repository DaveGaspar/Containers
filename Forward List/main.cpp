#include <iostream>
#include "Forward_List.h"

int main(){
	Forward_List<int> list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);
	
	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	// list.reverse();

	// std::cout << std::endl;
	// list.print();
	// std::cout << std::endl;

	// list.pop_front();
	// list.pop_front();

	// std::cout << std::endl;
	// list.print();
	// std::cout << std::endl;

	// if (list.is_cycled()){
	// 	std::cout << "True" << std::endl;
	// }
	// else{
	// 	std::cout << "False" << std::endl;
	// }
	

	std::cout << list.n_from_back(5) << std::endl;


	return 0;
}