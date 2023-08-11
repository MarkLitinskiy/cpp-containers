#include "s21_vector.h"

using namespace s21;

template <typename T>
vector<T>::vector():container_size(0), container_capacity(0){
    array = nullptr;
}

template <typename T>
vector<T>::vector(size_type n) {
    allocate_mem(n);
}

template <typename T>
vector<T>::vector(std::initializer_list<T> const &items) noexcept:vector(
    static_cast<size_type>(items.size())){
        int count = 0;
        for (auto element : items) {
            array [count] = element;
            ++count;
        }
}

template <typename T>
vector<T>::~vector(){
    delete_mem();
}

template <typename T>
vector<T>::vector(const vector &v){
    allocate_mem(v.container_capacity);
    for (size_type i = 0; i < container_size; ++i)
        array[i] = v.array[i];
}

template <typename T>
vector<T>::vector(vector &&v) noexcept: container_size(0), container_capacity(0), array(nullptr){
    std::swap(container_size, v.container_size);
    std::swap(container_capacity, v.container_capacity);
    std::swap(array, v.array);
}

template <typename T>
vector<T> vector<T>::operator=(vector &&v){
    if (this != &v) {
    delete_mem();
    std::swap(container_size, v.container_size);
    std::swap(container_capacity, v.container_capacity);
    std::swap(array, v.array);
    }
    return *this;
}

template <typename T>
vector<T> vector<T>::operator=(const vector &v){
    if (this != &v) {
    delete_mem();
    allocate_mem(v.container_capacity);
    for (size_type i = 0; i < container_size; ++i)
        array[i] = v.array[i];
    }
    return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
    if(pos > container_size - 1)
        throw std::out_of_range("Выход за пределы вектора!");
    return array[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) noexcept{
    return array[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const noexcept{
    return array[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const noexcept{
    return array[container_size - 1];
}

template <typename T>
T* vector<T>::data() noexcept{
    return array;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() noexcept{
    return array;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() noexcept{
    return &array[container_size];
}

template <typename T>
bool vector<T>::empty() const noexcept{
    if (container_size == 0)
        return true;
    else 
        return false;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const noexcept{
    return container_size;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size(){
    std::allocator <T> max;
    return static_cast<size_type>(max.max_size());
}

template <typename T>
void vector<T>::reserve(size_type size) {
    if (size > max_size())
        throw std::out_of_range("Заданный буфер больше возможного размера!");
    if (size > container_capacity) {
    container_capacity = size;
    reserve_memory();
    }
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const noexcept{
    return container_capacity;
}

template <typename T>
void vector<T>::shrink_to_fit() {
    if (container_capacity > container_size) {
        container_capacity = container_size;
        reserve_memory();
    }
}

template <typename T>
void vector<T>::clear() noexcept {
    container_size = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos, const_reference value) {
    if(container_size >= container_capacity)
        container_capacity *= 2;
    T* temp = new T[container_capacity];
    T* result = nullptr;
    for (size_type i = 0, j = 0; i <= container_size; ++i, ++j) {
        if (pos == &array[i]) {
            temp[i] = value;
            j--;
            result = &temp[i];
        } else {
            temp[i] = array[j];
        }
    }
    delete[] array;
    array = temp;
    container_size++;
    return result;
}

template <typename T>
void vector<T>::erase(iterator pos) {
    T* temp = new T[container_capacity];
    for (size_type i = 0, j = 0; i < container_size; ++i, ++j) {
        if (pos != &array[i]) {
            temp[j] = array[i];
         } else {
              j--;
         }
   }
    delete[] array;
    array = temp;
    container_size--;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
    if (container_capacity > container_size)
        array[container_size] = value;
    else {
    container_capacity *= 2;
    reserve_memory();
    array[container_size] = value;
    }
    container_size++;
}

template <typename T>
void vector<T>::pop_back() noexcept {
    if(!empty())
    container_size--;
}

template <typename T>
void vector<T>::swap(vector& other) noexcept {
    std::swap(container_size, other.container_size);
    std::swap(container_capacity, other.container_capacity);
    std::swap(array, other.array);
}


template <typename T>
void vector<T>::allocate_mem(size_type container_size) {
    array = new T[container_size]{};
    this->container_size = container_size;
    container_capacity = container_size;
}

template <typename T>
void vector<T>::delete_mem() {
    if(array != nullptr)
        delete[] array;
    container_size = 0;
    container_capacity = 0;
}

/// @brief Изменение размера буфера/размера вектора через временный массив
/// @param size новый размер вектора
template <typename T>
void vector<T>::reserve_memory() {
    T* array_rev = new T[container_capacity]; 
    for (size_type i = 0; i < container_size; ++i)
        array_rev[i] = array[i];
    delete[] array;
    array = array_rev;
}