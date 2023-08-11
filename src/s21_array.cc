#include "s21_array.h"
#include <array>

using namespace s21;

// int main() {
//     array<int, 5> ar1;
//     array<int, 5> ar2 = {1, 2, 3, 4, 5};
//     ar1 = ar2;
//     std::cout << ar1.static_array[0] << std::endl;
//     std::cout << ar1.static_array[1] << std::endl;
//     std::cout << ar1.static_array[2] << std::endl;
//     std::cout << ar1.static_array[3] << std::endl;
//     std::cout << ar1.static_array[4] << std::endl;
// }

template <typename T, size_t N>
array<T, N>::array(){
    size_array = N;
    for(size_type i = 0; i < N; i++)
        static_array[i] = 0;
}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<T> const &items){
    if (items.size() > N)
        throw std::out_of_range("Значений больше, чем размер массива!");
    size_array = N;
    int count = 0;
		for (auto &element : items)
		{
			static_array[count] = element;
			++count;
		}
}

template <typename T, size_t N>
array<T, N>::array(const array &a){
    size_array = a.size_array;
    //std::memcpy(static_array, a.static_array, size_type * N);
    for (size_type i = 0; i < N; i++)
        static_array[i] = a.static_array[i];
}

template <typename T, size_t N>
array<T, N>::array(array &&a):size_array(0){
    for(size_type i = 0; i < N; i++)
        static_array[i] = 0;
    std::swap(static_array, a.static_array);
    std::swap(size_array, a.size_array);
}

template <typename T, size_t N>
array<T, N>::~array(){
    for(size_type i = 0; i < N; i++)
        static_array[i] = 0;
}

template <typename T, size_t N>
array<T, N> array<T, N>::operator=(array &&a){
    if (this != &a) {
        std::swap(static_array, a.static_array);
        std::swap(size_array, a.size_array);
    }
    return *this;
}

template <typename T, size_t N>
array<T, N> array<T, N>::operator=(const array &a){
    if (this != &a) {
        size_array = a.size_array;
        for (size_type i = 0; i < N; i++)
            static_array[i] = a.static_array[i];
    }
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos){
    if (pos >= N){
        throw std::out_of_range("Выход за пределы массива!");
    }
    return static_array[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) const{
    if (pos >= N || pos < 0){
        throw std::out_of_range("Выход за пределы массива!");
    }
    return static_array[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
    return static_array[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) const {
    return static_array[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
    return static_array[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
    return static_array[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data(){
    return static_array;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin(){
    return &static_array[0];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end(){
    return &static_array[N];
}

template <typename T, size_t N>
bool array<T, N>::empty() {
    if (N == 0)
        return true;
    else
        return false;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() {
    return N;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
    return N;
}

template <typename T, size_t N>
void array<T, N>::swap(array& other) {
    if (size_array != other.size_array)
        throw std::out_of_range("Массивы не равны");
    std::swap(static_array, other.static_array);
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value){
    for (int i = 0; i < size_array; i++) {
        static_array[i] = value;
    }
}
