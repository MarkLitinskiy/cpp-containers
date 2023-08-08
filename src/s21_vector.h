#include <iostream>

template <typename T>
class vector {
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::size_t size_type;

public:
vector();
vector(size_type n);
vector(std::initializer_list<value_type> const &items);
vector(const vector &v);
vector(vector &&v);
~vector();
vector operator=(vector &&v);
vector operator=(const vector &v);

reference at(size_type pos);
reference operator[](size_type pos);
reference operator[](size_type pos) const;
const_reference front();
const_reference back();
T* data();

iterator begin();
iterator end(); 
iterator begin() const;
iterator end() const; 

bool empty();
size_type size();
size_type max_size();
void reserve(size_type size);  // для чего передаётся size? получается массив урезать можно? А если size>array
size_type capacity();
void shrink_to_fit();

// void clear();
// iterator insert(iterator pos, const_reference value);
// void erase(iterator pos);
// void push_back(const_reference value);
// void pop_back();
// void swap(vector& other);

private:
value_type* array;
size_type container_size;  // размер массива (кол-во элементов в векторе)
size_type container_capacity;  // размер буффера
void allocate_mem(size_type size);
void delete_mem();
};