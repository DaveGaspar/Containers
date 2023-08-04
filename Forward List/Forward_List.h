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
class Forward_List{
	private:
		Node<T>* head;
	public:
		Forward_List(){
			head = nullptr;
		}
	public:
		void push_front(T value){
			Node<T>* node = new Node<T>;
            node->data = value;
            if(head == nullptr){
                head = node;
                return;
            }
            node->next = head;
            head = node;
		}
		void pop_front(){
			if (head == nullptr){
				return;
			}
			Node<T>* temp = head;
			head = head->next;
			delete temp;
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
		T& front(){
			if (head == nullptr){
				throw std::runtime_error("List is empty");
			}
			return head->data;
		}
		void reverse(){
			
		}
};