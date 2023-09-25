#pragma once

#include <iostream>
#include "..\Vector\Vector.h"
#include "..\Forward List\Forward_List.h"

// template <typename T>
// class Stack:private Vector<T>{
// 	public:
// 		void push(T value){
// 			this->push_back(value);
// 		}
// 		void pop(){
// 			this->pop_back();
// 		}
// 		T& top(){
// 			return (this->at(this->size()-1));
// 		}
// };

template <typename T>
class Stack:private Forward_List<T>{
	public:
		void push(T value){
			this->push_front(value);
		}
		void pop(){
			this->pop_front();
		}
		T& top(){
			return this->front();
		}
};