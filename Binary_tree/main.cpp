#include "Binary_tree.h"

int main(){
	Binary_tree bt;
	bt.init();
	std::cout << "\nInorder: " << std::endl;
	bt.inorder();
	std::cout << "\nPreorder: " << std::endl;
	bt.preorder();
	std::cout << "\nPostorder: " << std::endl;
	bt.postorder();
	std::cout << "\nLevel by level order: " << std::endl;
	bt.level_order();
	return 0;
}