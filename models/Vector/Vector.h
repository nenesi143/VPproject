#include <iostream>

template <typename T>
class Vector{
    private:
        T* data;
        template <typename T> m_size;
        template <typename T> m_capacity;

    public:
        Vector();
        ~Vector();
        void printAll() const;
        void sortAscending(); // Ascending - по возрастанию
        void sortDescending(); // Descending - по убыванию
        void push_back(const T& newData);
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