#include "Vector.h"

template <typename T>
Vector<T>::Vector() : data(nullptr), m_size(0), m_capacity(0) {}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

template <typename T>
void Vector<T>::resize(){
    if (m_capacity == 0){
        m_capacity == 2;
    }
    m_capacity *= 2;
    T* newData = new T[m_capacity];
    for (int i = 0; i < m_size; i++){
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
}