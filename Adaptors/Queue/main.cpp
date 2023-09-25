#include <iostream>
#include "Queue.h"

int main(int argc, char const *argv[])
{
	Queue<int> queue;
	//std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;
	queue.push(1);
	std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;
	queue.push(2);
	std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;
	queue.push(3);
	std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;

	queue.pop();
	std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;
	queue.pop();
	std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;
	queue.pop();
	// std::cout << "Front: " << queue.front() << " Back: " << queue.back() << std::endl;


	return 0;
}
