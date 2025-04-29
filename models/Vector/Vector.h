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

        void puch_back();
        void pop_back();
        void erase(template <typename T> index);
        bool empty() const;
        template <typename T> size() const;
        void resize();
        T* begin();
        T *end();
};