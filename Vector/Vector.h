#pragma once

#include <iostream>

template <typename T>
class Vector{

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
			throw std::out_of_range("Index out of range");
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
};