#include "Stack.h"

int main(){
	Stack<int> stack;
	//std::cout << stack.top() << std::endl;	
	stack.push(1);
	std::cout << stack.top() << std::endl;	
	stack.push(2);
	std::cout << stack.top() << std::endl;
	stack.push(3);
	std::cout << stack.top() << std::endl;
	stack.push(4);
	std::cout << stack.top() << std::endl;	
}