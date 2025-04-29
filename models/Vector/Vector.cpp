#include "Vector.h"
#include "../Employee/Employee.h"
#include "../Supplier/Supplier.h"

template <typename T>
Vector<T>::Vector() : data(nullptr), m_size(0), m_capacity(0) {}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

template <typename T> // Вот тут мы проходимся циклом
void Vector<T>::resize(int size){

    if (size >= m_capacity){
        m_capacity = size * 2;
    }

    T* newData = new T[m_capacity];
    for (int i = 0; i < m_size; i++){
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;

    m_size = size;
}

template <typename T>
void Vector<T>::push_back(const T& newData){
    if (m_size >= m_capacity){
        m_capacity *= 2;
    }
    data[m_size++] = newData;
}

template <typename T>
void Vector<T>::pop_back(){
     if (m_size > 0){
        m_size--;
     }
}

template <typename T> // Вот тут мы проходимся циклом
void Vector<T>::erase(int index){
    if (index < 0 or index > m_size){
        wcout << L"Неверный индекс для удаления!" << endl;
        return;
    }
    for (int i = index; i < m_size; i++){
        data[i] = data[i+1];
    }
    m_size--;
}

template <typename T>
bool Vector<T>::empty() const{
    return m_size == 0;
}

template <typename T>
int Vector<T>::size() const{
    return m_size;
}

template <typename T>
T* Vector<T>::begin(){
    return data;
}

template <typename T>
T* Vector<T>::end(){
    return data + m_size;
}

template <typename T>
void Vector<T>::printAll() const{
    for (int i = 0; i < m_size; i++){
        data[i].getRecord();
    }
}

template <typename T> 
T& Vector<T>::get(int index){ // Получаем запись по индексу, а дальше применяем к ней методы
    if (index < 0 or index > m_size){ // Изменение не нужно, тк я могу обращаться через гет и уже изменять
        wcout << L"Неверный индекс!" << endl;
    }
    
    return data[index];
}

template <typename T>
void Vector<T>::sortAscending(){
    sort(data, data + m_size);
}

template <typename T>
void Vector<T>::sortDescending(){
    sort(data, data + m_size, greater<T>());
}