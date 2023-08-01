#pragma once

#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(){
		this->next = nullptr;
	}
};

template <typename T>
class List{
	private:
		Node<T>* head;
	public:
		List(){
			head = nullptr;
		}
	public:
		void add(T value){
			Node<T>* node = new Node<T>;
            node->data = value;
            if(head == nullptr){
                head = node;
                return;
            }
            node->next = head;
            head = node;
		}
		void print(){
			if(head == nullptr){
                std::cout << "List is empty" << std::endl;
                return;
            }
            Node<T>* temp = head;
            while(temp != nullptr){
                std::cout << temp->data << "\t";
                temp = temp->next;
            }
		}
};