#include <iostream>
#include "s21_vector.h"

int main(){
vector<int> vector_standart;
vector<int> vector_param(3);
vector<int> vector_list{1, 2, 3};
std::cout << "Второй элемент vector_param: " << vector_param[1] << std::endl;
std::cout << "Элементы vector_list: " << vector_list[0] << vector_list[1] << vector_list[2] << std::endl;
vector<int> vector_copy(vector_list);
std::cout << "Элементы vector_copy: " << vector_copy[0] << vector_copy[1] << vector_copy[2] << std::endl;
vector<int> vector_move = vector_list;
std::cout << "Элементы vector_move: " << vector_move[0] << vector_move[1] << vector_move[2] << std::endl;
std::cout << "vector_move.at(0): " << vector_move.at(0) << std::endl;
std::cout << "vector_move.front(): " << vector_move.front() << std::endl;
std::cout << "vector_move.back(): " << vector_move.back() << std::endl;
std::cout << "vector_move.at(-4): " << vector_move.at(2) << std::endl;

return 0;
}

template <typename value_type>
vector<value_type>::vector() : container_size(0), container_capacity(0) {
array = nullptr;
std::cout << "Произошёл стандартный конструктор" << std::endl;
}

template <typename value_type>
vector<value_type>::vector(size_type n) {
    allocate_mem(n);
    std::cout << "Произошёл конструктор с параметром" << std::endl;
}
template <typename value_type>
vector<value_type>::vector(std::initializer_list<value_type> const &items):vector(
    static_cast<container_size_type>(items.container_size())){
        int count = 0;
        for (auto element : items) {
            array [count] = element;
            ++count; 
        }
        std::cout << "Произошёл конструктор с заданным списком элементов (-1 деструктор)" << std::endl;
}

template <typename value_type>
vector<value_type>::~vector(){
    delete_mem();
    std::cout << "Произошёл стандартный деструктор" << std::endl;
}

template <typename value_type>
vector<value_type>::vector(const vector &v){
    allocate_mem(v.container_size);
    for (container_size_type i = 0; i < container_size; i++)
        array[i] = v.array[i];
    std::cout << "Произошёл конструктор копирования" << std::endl;
}

template <typename value_type>
vector<value_type>::vector(vector &&v):container_size{0}, array{nullptr} {
    std::swap(container_size, v.container_size);
    std::swap(array, v.array);
    std::cout << "Произошёл конструктор перемещения" << std::endl;
}

template <typename value_type>
vector<value_type> vector<value_type>::operator=(vector &&v){
    if (this != &v) {
    delete_mem();
    std::swap(container_size, v.container_size);
    std::swap(array, v.array);
    }
    std::cout << "Произошёл оператор присваивания перемещением" << std::endl;
    return *this;
}

template <typename value_type>
vector<value_type> vector<value_type>::operator=(const vector &v){
    if (this != &v) {
    delete_mem();
    allocate_mem(v.container_size);
    for (container_size_type i = 0; i < container_size; i++)
        array[i] = v.array[i];
    }
    std::cout << "Произошёл оператор присваивания копированием" << std::endl;
    return *this;
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
    if(pos > container_size - 1)
        throw std::out_of_range("Выход за пределы вектора!");
    return array[pos];
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::operator[](size_type pos) {
    return array[pos];
}

template <typename value_type>
typename vector<value_type>::reference vector<value_type>::operator[](size_type pos) const {
    return array[pos];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::front() {
    return array[0];
}

template <typename value_type>
typename vector<value_type>::const_reference vector<value_type>::back() {
    return array[container_size - 1];
}

template <typename value_type>
value_type* vector<value_type>::data(){
    return array;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
    return array;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
    return array[container_size] + 1;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::begin() const {
    return array;
}

template <typename value_type>
typename vector<value_type>::iterator vector<value_type>::end() const {
    return array[container_size] + 1;
}

template <typename value_type>
bool vector<value_type>::empty() {
    if (container_size != 0 && array != nullptr)
        return true;
    else 
        return false;
}

template <typename value_type>
vector<value_type>::size_type vector<value_type>::size() {
    return container_size;
}

template <typename value_type>
vector<value_type>::size_type vector<value_type>::max_size() {
    return std::numeric_limits<value_type>::max();
}

template <typename value_type>
void vector<value_type>::reserve(size_type container_size) {
    value_type array_rev* = new value_type[container_size]{}; 
    for (int i = 0, j = container_size-1; i < container_size; i++, j--)
        array_rev[i] = array[j]
    delete[] array;
    array = array_rev;
}

template <typename value_type>
vector<value_type>::size_type vector<value_type>::capacity(){
    return container_capacity;
}

template <typename value_type>
void vector<value_type>::shrink_to_fit() {
    if (container_capacity > conteiner_size) {
        value_type temp* = new value_type[conteiner_size];
        for (int i = 0, i < container_size; i++)
        temp[i] = array[i]
        delete[] array;
        array = temp;
    }
}


template <typename value_type>
void vector<value_type>::allocate_mem(size_type container_size) {
    array = new value_type[container_size]{};
    this->container_size = container_size;
    container_capacity = container_size;
}

template <typename value_type>
void vector<value_type>::delete_mem() {
    if(array != nullptr)
        delete[] array;
    container_size = 0;
    container_capacity = 0;
}