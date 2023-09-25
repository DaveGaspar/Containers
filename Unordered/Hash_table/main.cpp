#include "Hash_table.h"

int main(){
	Vector<int> vec;
	for (int i = 0; i < 10; i++){
		vec.push_back(rand()%90 + 10);
	}

	std::cout << std::endl;
	vec.print();
	std::cout << std::endl;

	Hash_table ht;
	ht.Hash_function(vec);

	std::cout << std::endl;
	ht.print();
	std::cout << std::endl;

	return 0;
}