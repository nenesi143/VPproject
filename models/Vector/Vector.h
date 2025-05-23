#include <iostream>

template <typename T>
class Vector{
    private:
        T* data;
        int m_size;
        int m_capacity;

    public:
        Vector();
        ~Vector();
        void printAll() const;
        void sortAscending(); // Ascending - по возрастанию
        void sortDescending(); // Descending - по убыванию
        void push_back(const T& newData);
        void filterByAge();
        void pop_back();
        void erase(int index);
        bool empty() const;
        int size() const;
        void resize(int size);
        T* begin();
        T *end();
        T& get(int index);
        T& set(int index);
};