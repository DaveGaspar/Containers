#pragma once
#include <iostream>
#include <stack>
#include <queue>

struct Node{
	Node* left;
	Node* right;
	int data;
	Node(){
		left = nullptr;
		right = nullptr;
	}
};

class Binary_tree{
	private:
		Node* root;
	public:
		Binary_tree()
		{
			root = nullptr;
		}
	public:
		void init(){
			root = new Node;
			root->data = 1;

			root->left = new Node;
			root->left->data = 2;
		
			root->right = new Node;
			root->right->data = 3;

			root->left->left = new Node;
			root->left->left->data = 4;
			root->left->right = new Node;
			root->left->right->data = 5;

			// root->right->left = new Node;
			// root->right->left->data = 6;
			// root->right->right = new Node;
			// root->right->right->data = 7;

		}

		void inorder(){
			if (root == nullptr){
				return;
			}
			std::stack<Node*> st;
			Node* temp = root;
			while (temp != NULL || !st.empty()){
				while (temp != NULL) {
					st.push(temp);
					temp = temp->left;
				}
				temp = st.top();
				st.pop();
				std::cout << temp->data << "\t";
				temp = temp->right;
			}
		}

		void preorder(){
			if (root == nullptr){
				return;
			}
			std::stack<Node*> st;
			st.push(root);
			while (!st.empty()) {
				Node* temp = st.top();
				std::cout << temp->data << "\t";
				st.pop();
				if (temp->right){
					st.push(temp->right);
				}
				if (temp->left){
					st.push(temp->left);
				}
			}
		}

		void postorder(){
			if (root == nullptr){
				return;
			}
			std::stack<Node*> st;
			st.push(root);
			Node* temp_1 = nullptr;
			while (!st.empty()) {
				Node* temp_2 = st.top();
				if (temp_1 == nullptr || temp_1->left == temp_2 || temp_1->right == temp_2) {
					if (temp_2->left)
						st.push(temp_2->left);
					else if (temp_2->right)
						st.push(temp_2->right);
					else {
						st.pop();
						std::cout << temp_2->data << "\t";
					}
				}
		
				else if (temp_2->left == temp_1) {
					if (temp_2->right)
						st.push(temp_2->right);
					else {
						st.pop();
						std::cout << temp_2->data << "\t";
					}	
				}
				else if (temp_2->right == temp_1) {
					st.pop();
					std::cout << temp_2->data << "\t";
				}
				temp_1 = temp_2;
			}
		}
		void level_order(){
			if(root == nullptr){
				return;
			} 
			std::queue<Node*> m_q;
			m_q.push(root);
			while(m_q.empty() == false)
			{
				Node* node = m_q.front();
				std::cout<< node->data << "\t";
				m_q.pop();
				if(node->left != nullptr){
					m_q.push(node->left);
				}
				if(node->right != nullptr){
					m_q.push(node->right);
				}
			}
		}
};