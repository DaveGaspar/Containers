#pragma once

#include <iostream>

// template <typename Vector>
// class InputIterator{

// public:
// 	using ValueType = typename Vector::ValueType;
// 	using PointerType = ValueType*;
// 	using ReferenceType = ValueType&;
// private:
// 	PointerType m_ptr;
// public:
// 	InputIterator(PointerType ptr): m_ptr(ptr){
// 	}
// 	InputIterator(const InputIterator& obj): m_ptr(obj.m_ptr){
// 	}
// 	InputIterator& operator=(const InputIterator& obj){
// 		if (this != &obj){
// 			this->m_ptr = obj.m_ptr;
// 		}
// 		return *this;
// 	}
// 	InputIterator& operator++(){
// 		m_ptr++;
// 		return *this;
// 	}
// 	InputIterator operator++(int){
// 		InputIterator iterator = *this;
// 		++(*this);
// 		return iterator;
// 	}
// 	PointerType operator->(){
// 		return m_ptr;
// 	}
// 	ReferenceType operator*(){
// 		return *m_ptr;
// 	}
// 	bool operator==(const InputIterator& obj){
// 		return m_ptr == obj.m_ptr;
// 	}
// 	bool operator!=(const InputIterator& obj){
// 		return !(*this == obj);
// 	}
// };

class MyException:public std::exception{
private:
	const char * m_c;
public:
	MyException() = delete;
	MyException(const char * c) : m_c(c){

	}
	~MyException() override = default;
public:
	const char * what() const noexcept override{
		return m_c;
	}
};

template <typename Vector>
class VectorIterator{

public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
private:
	PointerType m_ptr;
public:
	VectorIterator(PointerType ptr): m_ptr(ptr){
	}
	VectorIterator& operator++(){
		m_ptr++;
		return *this;
	}
	VectorIterator operator++(int){
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}
	VectorIterator& operator--(){
		m_ptr--;
		return *this;
	}
	VectorIterator operator--(int){
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}
	ReferenceType operator[](int i){
		return m_ptr[i];
	}
	PointerType operator->(){
		return m_ptr;
	}
	ReferenceType operator*(){
		return *m_ptr;
	}
	bool operator==(const VectorIterator& obj){
		return m_ptr == obj.m_ptr;
	}
	bool operator!=(const VectorIterator& obj){
		return !(*this == obj);
	}
};

template <typename T>
class Vector{

public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T>>;
private:
	T* m_arr = nullptr;
	int m_size;
	int m_capacity;

public:
	Vector(){
		m_arr = new T[1];
		m_capacity = 1;
		m_size = 0;
	}
	~Vector(){
		delete[] m_arr;
		m_arr = nullptr;
		m_size = 0;
		m_capacity = 0;
	}

public:
	int size(){
		return m_size;
	}

	int capacity(){
		return m_capacity;
	}

	T& operator [](int i){
		return m_arr[i];
	}

	T& at(int i){
		if (i < 0 || i > m_size){
			throw MyException("Index is out of range");
		}
		return m_arr[i];
	}

	void push_back(const T& value){
		if (m_capacity == m_size){
			T* temp = new T[2 * m_capacity];
            for (int i = 0; i < m_capacity; i++) {
                temp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_capacity *= 2;
            m_arr = temp;
        }
        m_arr[m_size++] = value;
	}

	void insert(const T& value, int index){
		if (m_capacity == m_size){
			T* temp = new T[2 * m_capacity];
            for (int i = 0; i < m_capacity; i++) {
                temp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_capacity *= 2;
            m_arr = temp;
        }
		int new_size = 0;
		T* temp = new T[m_capacity];
		for (int i = 0; i < m_size; i++){
			if (i == index){
				temp[new_size++] = value;
			}
			temp[new_size++] = m_arr[i];
		}
		m_size++;
		delete[] m_arr;
		m_arr = temp;
	}

	void pop_back(){
		T* temp = new T[m_capacity];
		for (int i = 0; i < m_size-1; i++){
			temp[i] = m_arr[i];
		}
		m_size--;
		delete[] m_arr;
		m_arr = temp;
	}

	void erase(int index){
		int new_size = 0;
		T* temp = new T[m_capacity];
		for (int i = 0; i < m_size; i++){
			if (i == index){
				continue;
			}
			temp[new_size++] = m_arr[i];
		}
		m_size--;
		delete[] m_arr;
		m_arr = temp;
	}

	void print(){
		for (int i = 0; i < m_size; i++){
			std::cout << m_arr[i] << "\t";
		}
	}

	Iterator begin(){
		return Iterator(m_arr);
	}

	Iterator end(){
		return Iterator(m_arr + m_size);
	}
};