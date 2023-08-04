#pragma once

template<typename T>
struct Node{
	T data;
	Node* next;
	Node* previous;
	Node(){
		this->next = nullptr;
		this->previous = nullptr;
	}
};

template<typename T>
class List{
	private:
		Node<T>* head;
		Node<T>* tail;
	public:
		List(){
			head = nullptr;
			tail = nullptr;
		}
	public:
		void push_front(T value){
			Node<T>* node = new Node<T>;
            node->data = value;
            if(head == nullptr){
                head = node;
                tail = node;
                return;
            }
            node->next = head;
            head->previous = node;
			head = node;
		}
		void push_back(T value){
			Node<T>* node = new Node<T>;
            node->data = value;
            if(head == nullptr){
                head = node;
                tail = node;
                return;
            }
            node->previous = tail;
            tail->next = node;
			tail = node;
		}
		void pop_front(){
			if (head == nullptr || tail == nullptr){
				return;
			}
			if (head->next == nullptr || tail->previous == nullptr){
				head = nullptr;
				tail = nullptr;
				return;
			}
			Node<T>* temp = head;
			head = head->next;
			head->previous = nullptr;
			delete temp;
		}
		void pop_back(){
			if (head == nullptr || tail == nullptr){
				return;
			}
			if (head->next == nullptr || tail->previous == nullptr){
				head = nullptr;
				tail = nullptr;
				return;
			}
			Node<T>* temp = tail;
			tail = tail->previous;
			tail->next = nullptr;
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
		T& back(){
			if (head == nullptr){
				throw std::runtime_error("List is empty");
			}
			return tail->data;
		}
};