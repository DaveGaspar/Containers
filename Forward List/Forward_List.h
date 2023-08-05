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
			if (head == nullptr){
				throw std::runtime_error("List is empty");
			}
			if (head->next == nullptr){
				return;
			}
			Node<T> *origin, *temp, *rev;
			origin = head;
			temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = nullptr;
			head = temp;
			rev = temp;
			while (rev != origin)
			{
				temp = origin;
				while (temp->next != rev)
				{
					temp = temp->next;
				}
				rev->next = temp;
				rev = temp;
			}
			origin->next = nullptr;
		}
		bool is_cycled(){
			if (head == nullptr){
				throw std::runtime_error("List is empty");
			}
			Node<T> *slow_ptr = head;
			Node<T> *fast_ptr = head;

			while(fast_ptr != nullptr && fast_ptr->next != nullptr){
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next->next;
				if (slow_ptr == fast_ptr){
					return true;
				}
			}
			return false;
		}
		T& n_from_back(int n){
			Node<T> *temp_1, *temp_2;
			temp_1 = head;
			temp_2 = head;
			int count = 0;
			while(temp_1->next != nullptr){
				if (count == n - 1){
					break;
				}
				temp_1 = temp_1->next;
				count++;
			}
			while (temp_1->next != nullptr)
			{
				temp_1 = temp_1->next;
				temp_2 = temp_2->next;
			}
			return temp_2->data;
		}
};