#ifndef S21_CONTAINER_ARRAY_OOP
#define S21_CONTAINER_ARRAY_OOP

#include <iostream>
#include <cstring>

namespace s21 {
template <typename T, size_t N>
class array {
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::size_t size_type;

public:
    array();
    array(std::initializer_list<value_type> const &items);
    array(const array &a);
    array(array &&a);
    ~array();
    array operator=(array &&a);
    array operator=(const array &a);

    reference at(size_type pos);
    reference at(size_type pos) const;
    reference operator[](size_type pos);
    reference operator[](size_type pos) const;
    const_reference front();
    const_reference back();
    iterator data();

    iterator begin();
    iterator end();

    bool empty();
    size_type size();
    size_type max_size();

    void swap(array& other);
    void fill(const_reference value);

private:
    size_type size_array;
    value_type static_array[N];

};
}  // namespace s21

#endif  // S21_CONTAINER_ARRAY_OOP