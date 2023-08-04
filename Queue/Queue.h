#pragma once

#include "../List/List.h"

template <typename T>
class Queue:private List<T>{
	public:
		void push(T value){
			this->push_back(value);
		}
		void pop(){
			this->pop_front();
		}
		T& front(){
			return this->List<T>::front();
		}
		T& back(){
			return this->List<T>::back();
		}
};