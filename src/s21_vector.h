#ifndef S21_CONTAINER_VECTOR_OOP
#define S21_CONTAINER_VECTOR_OOP

#include <iostream>
#include <limits>
#include <algorithm>

namespace s21 {
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
vector(std::initializer_list<value_type> const &items) noexcept;
vector(const vector &v);
vector(vector &&v) noexcept;

~vector();
vector operator=(vector &&v);
vector operator=(const vector &v);

reference at(size_type pos);
reference operator[](size_type pos) noexcept;
const_reference front() const noexcept;
const_reference back() const noexcept;
T* data() noexcept;

iterator begin() noexcept;
iterator end() noexcept; 

bool empty() const noexcept;
size_type size() const noexcept;
size_type max_size();
void reserve(size_type size);
size_type capacity() const noexcept;
void shrink_to_fit();

void clear() noexcept;
iterator insert(iterator pos, const_reference value);
void erase(iterator pos);
void push_back(const_reference value);
void pop_back() noexcept;
void swap(vector& other) noexcept;

private:
value_type* array;
size_type container_size;  // размер массива (кол-во элементов в векторе)
size_type container_capacity;  // размер буффера

void allocate_mem(size_type size);
void delete_mem();
void reserve_memory();
};
}  // namespace s21
#endif  // S21_CONTAINER_VECTOR_OOP