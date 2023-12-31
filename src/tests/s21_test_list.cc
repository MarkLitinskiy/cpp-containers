#include <list>

#include "../s21_containers.h"
#include "gtest/gtest.h"

using namespace s21;

// ------- List Functions -------

TEST(List_Functions, default_constructor) {
  list<int> test_list;
  EXPECT_EQ(test_list.size(), 0);
}

TEST(List_Functions, parameterized_constructor) {
  list<int> test_list(100);
  EXPECT_EQ(test_list.size(), 100);

  // пустой список
  list<int> null_list(8);
  EXPECT_EQ(null_list.size(), 8);
}

TEST(List_Functions, initializer_list_constructor) {
  list<int> test_list{3, 2, 1};
  std::list<int> std_list{3, 2, 1};

  list<int>::iterator it;
  std::list<int>::iterator std_it;

  for (it = test_list.begin(), std_it = std_list.begin();
       it != test_list.end(), std_it != std_list.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  EXPECT_EQ(test_list.front(), std_list.front());
  EXPECT_EQ(test_list.back(), std_list.back());
  EXPECT_EQ(test_list.size(), std_list.size());

  // пустой список
  list<int> null_list{};
  std::list<int> null_std_list{};
  EXPECT_EQ(test_list.front(), std_list.front());
  EXPECT_EQ(test_list.back(), std_list.back());
  EXPECT_EQ(test_list.size(), std_list.size());
}

TEST(List_Functions, copy_constructor) {
  const list<int> copy_list{3, 2, 1};
  list<int> test_list = copy_list;

  const std::list<int> copy_std_list{3, 2, 1};
  std::list<int> std_list = copy_std_list;

  list<int>::iterator it;
  std::list<int>::iterator std_it;

  for (it = test_list.begin(), std_it = std_list.begin();
       it != test_list.end(), std_it != std_list.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  EXPECT_EQ(test_list.front(), std_list.front());
  EXPECT_EQ(test_list.back(), std_list.back());
  EXPECT_EQ(test_list.size(), std_list.size());

  // // копирование пустого списка
  list<int> null_list;
  std::list<int> null_std_list;
  list<int> test_list_2 = null_list;
  std::list<int> std_list_2 = null_std_list;

  // std::cout << null_std_list.size() << std::endl;

  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
  EXPECT_EQ(test_list_2.size(), std_list_2.size());
}

TEST(List_Functions, move_constructor) {
  list<int> moving_list{3, 2, 1};
  list<int> test_list = std::move(moving_list);

  std::list<int> moving_std_list{3, 2, 1};
  std::list<int> std_list = std::move(moving_std_list);

  list<int>::iterator it;
  std::list<int>::iterator std_it;

  for (it = test_list.begin(), std_it = std_list.begin();
       it != test_list.end(), std_it != std_list.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  EXPECT_EQ(test_list.front(), std_list.front());
  EXPECT_EQ(test_list.back(), std_list.back());
  EXPECT_EQ(test_list.size(), std_list.size());

  EXPECT_EQ(moving_list.front(), moving_std_list.front());
  EXPECT_EQ(moving_list.back(), moving_std_list.back());
  EXPECT_EQ(moving_list.size(), moving_std_list.size());

  // перемещение пустого списка
  list<int> null_list;
  list<int> test_list_2 = std::move(null_list);
  std::list<int> null_std_list;
  std::list<int> std_list_2 = std::move(null_std_list);

  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
  EXPECT_EQ(test_list_2.size(), std_list_2.size());
}

TEST(List_Functions, assignment_operator_overload) {
  list<int> test_list;
  test_list = {2};
  test_list.pop_back();

  test_list = {3, 2, 1};
  std::list<int> std_list = {3, 2, 1};

  list<int> test_list_2 = {5, 4, 3, 2, 1};
  test_list_2 = std::move(test_list);
  std::list<int> std_list_2 = {5, 4, 3, 2, 1};
  std_list_2 = std::move(std_list);

  list<int>::iterator it;
  std::list<int>::iterator std_it;

  for (it = test_list_2.begin(), std_it = std_list_2.begin();
       it != test_list_2.end(), std_it != std_list_2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
  EXPECT_EQ(test_list_2.size(), std_list_2.size());
}

// ------- List Element access -------

TEST(List_Elemets_access, front_back) {
  list<int> test_list = {3, 2, 1};
  std::list<int> std_list = {3, 2, 1};
  EXPECT_EQ(test_list.front(), std_list.front());
  EXPECT_EQ(test_list.back(), std_list.back());

  // пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
}

// // ------- List Iterators -------

TEST(List_Iterators, begin_end) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  EXPECT_EQ(*test_list.begin(), *std_list.begin());
  EXPECT_EQ(*--test_list.end(), *--std_list.end());

  // пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  EXPECT_EQ(*test_list_2.begin(), *std_list_2.begin());
  EXPECT_EQ(*test_list_2.end(), *std_list_2.end());

  // один элемент
  list<int> test_list_3 = {10};
  std::list<int> std_list_3 = {10};
  EXPECT_EQ(*test_list_3.begin(), *std_list_3.begin());
  EXPECT_EQ(*--test_list_3.end(), *--std_list_3.end());
}

TEST(List_Iterators, increment) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  std::list<int>::iterator std_it;

  for (it = test_list.begin(), std_it = std_list.begin();
       it != test_list.end(), std_it != std_list.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  ++it;

  // пустой список
  list<int> list_2;
  it = list_2.begin();
  ++it;
  it = list_2.end();
  ++it;
}

TEST(List_Iterators, decrement) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  std::list<int>::iterator std_it;

  for (it = test_list.end(), std_it = std_list.end();
       it != test_list.begin(), std_it != std_list.begin();) {
    EXPECT_EQ(*(--it), *(--std_it));
  }

  --it;

  // пустой список
  list<int> list_2;
  it = list_2.begin();
  --it;
  it = list_2.end();
  --it;
}

// // ------- List Capacity -------

TEST(List_Capacity, empty) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  EXPECT_EQ(test_list.empty(), std_list.empty());

  // пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  EXPECT_EQ(test_list_2.empty(), std_list_2.empty());
}

// // ------- List Modifiers -------

TEST(List_Modifiers, clear) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  test_list.clear();
  std_list.clear();
  EXPECT_EQ(test_list.empty(), std_list.empty());

  // пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  test_list_2.clear();
  std_list_2.clear();
  EXPECT_EQ(test_list_2.empty(), std_list_2.empty());
}

TEST(List_Modifiers, insert) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int>::iterator std_it;

  // вставка в середину списка
  it = test_list.begin();
  ++it;
  test_list.insert(it, 3500);

  std_it = std_list.begin();
  ++std_it;
  std_list.insert(std_it, 3500);

  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // вставка в начало списка
  it = test_list.begin();
  test_list.insert(it, 1234);

  std_it = std_list.begin();
  std_list.insert(std_it, 1234);

  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // вставка в конец списка
  it = test_list.end();
  test_list.insert(it, 4567);

  std_it = std_list.end();
  std_list.insert(std_it, 4567);

  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  // вставка в пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  it = test_list_2.end();
  std_it = std_list_2.end();
  it = test_list_2.insert(it, 34534);
  std_it = std_list_2.insert(std_it, 34534);

  EXPECT_EQ(*it, *std_it);
}

TEST(List_Modifiers, erase) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int>::iterator std_it;

  // удаление элемента из середины списка
  it = test_list.begin();
  ++it;
  ++it;
  test_list.erase(it);

  std_it = std_list.begin();
  ++std_it;
  ++std_it;
  std_list.erase(std_it);

  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // из начала
  it = test_list.begin();
  test_list.erase(it);

  std_it = std_list.begin();
  std_list.erase(std_it);

  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  it = test_list.end();
  --it;
  test_list.erase(it);

  std_it = std_list.end();
  --std_it;
  std_list.erase(std_it);

  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // из пустого списка
  list<int> test_list_2;
  std::list<int> std_list_2;

  it = test_list_2.begin();
  test_list_2.erase(it);
}

TEST(List_Modifiers, push_back) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int>::iterator std_it;

  test_list.push_back(100);
  std_list.push_back(100);
  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // вставка в пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  test_list_2.push_back(100);
  std_list_2.push_back(100);
  EXPECT_EQ(*test_list_2.begin(), *std_list_2.begin());
  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
}

TEST(List_Modifiers, pop_back) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int>::iterator std_it;

  test_list.pop_back();
  std_list.pop_back();
  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // удаление из пустого списка. Стандартный падает, наш - нет.
  list<int> test_list_2;
  std::list<int> std_list_2;
  test_list_2.pop_back();
  EXPECT_EQ(*test_list_2.begin(), *std_list_2.begin());
  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
}

TEST(List_Modifiers, push_front) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int>::iterator std_it;

  test_list.push_front(100);
  std_list.push_front(100);
  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // вставка в пустой список
  list<int> test_list_2;
  std::list<int> std_list_2;
  test_list_2.push_front(100);
  std_list_2.push_front(100);
  EXPECT_EQ(*test_list_2.begin(), *std_list_2.begin());
  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
}

TEST(List_Modifiers, pop_front) {
  list<int> test_list = {5, 4, 3, 2, 1, 0};
  std::list<int> std_list = {5, 4, 3, 2, 1, 0};
  list<int>::iterator it;
  std::list<int>::iterator std_it;

  test_list.pop_front();
  std_list.pop_front();
  for (it = test_list.begin(), std_it = std_list.begin(); it != test_list.end();
       ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // удаление из пустого списка.
  list<int> test_list_2;
  std::list<int> std_list_2;
  test_list_2.pop_front();
  EXPECT_EQ(*test_list_2.begin(), *std_list_2.begin());
  EXPECT_EQ(test_list_2.front(), std_list_2.front());
  EXPECT_EQ(test_list_2.back(), std_list_2.back());
}

TEST(List_Modifiers, swap) {
  list<int> l1 = {3, 2, 1};
  list<int> l2 = {7, 6, 5, 4};
  l1.swap(l2);

  std::list<int> std_l1 = {3, 2, 1};
  std::list<int> std_l2 = {7, 6, 5, 4};
  std_l1.swap(std_l2);

  list<int>::iterator it;
  std::list<int>::iterator std_it;
  for (it = l1.begin(), std_it = std_l1.begin(); it != l1.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  for (it = l2.begin(), std_it = std_l2.begin(); it != l2.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // пустой список
  list<int> l3;
  std::list<int> std_l3;
  l3.swap(l2);
  std_l3.swap(std_l2);

  for (it = l2.begin(), std_it = std_l2.begin(); it != l2.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // и обратно
  l3.swap(l2);
  std_l3.swap(std_l2);

  for (it = l2.begin(), std_it = std_l2.begin(); it != l2.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // два пустых списка
  list<int> l4;
  std::list<int> std_l4;
  l4.swap(l3);
  std_l4.swap(std_l3);
  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  for (it = l4.begin(), std_it = std_l4.begin(); it != l4.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // своп с самим собой
  l1.swap(l1);
  std_l1.swap(std_l1);
}

TEST(List_Modifiers, unique) {
  list<int> l1 = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2,
                  2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1};
  l1.unique();

  std::list<int> std_l1 = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2,
                           2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1};
  std_l1.unique();

  list<int>::iterator it;
  std::list<int>::iterator std_it;
  for (it = l1.begin(), std_it = std_l1.begin(); it != l1.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // пустой список
  list<int> l2;
  std::list<int> std_l2;
  l2.unique();
  std_l2.unique();

  for (it = l2.begin(), std_it = std_l2.begin(); it != l2.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // список из одного элемента
  list<int> l3;
  std::list<int> std_l3;
  l3.unique();
  std_l3.unique();

  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);
}

TEST(List_Modifiers, reverse) {
  list<int> l1 = {6, 5, 4, 3, 2, 1, 0};
  l1.reverse();

  std::list<int> std_l1 = {6, 5, 4, 3, 2, 1, 0};
  std_l1.reverse();

  list<int>::iterator it;
  std::list<int>::iterator std_it;
  for (it = l1.begin(), std_it = std_l1.begin(); it != l1.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // пустой список
  list<int> l2;
  std::list<int> std_l2;
  l2.reverse();
  std_l2.reverse();

  for (it = l2.begin(), std_it = std_l2.begin(); it != l2.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // список из одного элемента
  list<int> l3;
  std::list<int> std_l3;
  l3.reverse();
  std_l3.reverse();

  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);
}

TEST(List_Modifiers, merge) {
  list<int> l1 = {6, 5, 4, 3, 2, 1, 0};
  list<int> l2 = {-1, -2, -3, -7, -8, -9};

  std::list<int> std_l1 = {6, 5, 4, 3, 2, 1, 0};
  std::list<int> std_l2 = {-1, -2, -3, -7, -8, -9};

  l1.merge(l2);
  std_l1.merge(std_l2);

  list<int>::iterator it;
  std::list<int>::iterator std_it;

  for (it = l1.begin(), std_it = std_l1.begin(); it != l1.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  EXPECT_EQ(l2.front(), std_l2.front());

  // пустой список
  list<int> l3;
  std::list<int> std_l3;
  l3.merge(l1);
  std_l3.merge(std_l1);

  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // и наоборот
  l3.merge(l1);
  std_l3.merge(std_l1);

  for (it = l3.begin(), std_it = std_l3.begin(); it != l3.end();
       ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }
  // список из одного элемента
  list<int> l4 = {1};
  std::list<int> std_l4 = {1};
  l4.merge(l3);
  std_l4.merge(std_l3);

  for (it = l4.begin(), std_it = std_l4.begin(); it != l4.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // слияние с самим собой
  l4.merge(l4);
  std_l4.merge(std_l4);
}

TEST(List_Modifiers, sort) {
  list<int> l1 = {5, 4, 3, 2, 1, 0, 1};
  std::list<int> std_l1 = {5, 4, 3, 2, 1, 0, 1};

  l1.sort();
  std_l1.sort();

  list<int>::iterator it;
  std::list<int>::iterator std_it;
  for (it = l1.begin(), std_it = std_l1.begin(); it != l1.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // пустой список
  list<int> l2;
  l2.sort();

  // список из одного элемента
  list<int> l3 = {1};
  l3.sort();
}

TEST(List_Modifiers, splice) {
  // вставка в конец списка
  list<int> l0 = {8, 5, 6, 7};
  list<int> l1 = {5, 4, 3, 2, 1, 0};

  std::list<int> std_l0 = {8, 5, 6, 7};
  std::list<int> std_l1 = {5, 4, 3, 2, 1, 0};

  l0.splice(l0.end(), l1);
  std_l0.splice(std_l0.end(), std_l1);

  list<int>::iterator it;
  std::list<int>::iterator std_it;
  for (it = l0.begin(), std_it = std_l0.begin(); it != l0.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // вставка в начало списка
  l0 = {8, 5, 6, 7};
  l1 = {5, 4, 3, 2, 1, 0};

  std_l0 = {8, 5, 6, 7};
  std_l1 = {5, 4, 3, 2, 1, 0};

  l0.splice(l0.begin(), l1);
  std_l0.splice(std_l0.begin(), std_l1);

  for (it = l0.begin(), std_it = std_l0.begin(); it != l0.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // вставка в середину списка
  l0 = {8, 5, 6, 7};
  l1 = {5, 4, 3, 2, 1, 0};

  std_l0 = {8, 5, 6, 7};
  std_l1 = {5, 4, 3, 2, 1, 0};

  list<int>::iterator cit = l0.begin();
  std::list<int>::iterator std_cit = std_l0.begin();

  ++cit;
  ++cit;
  ++std_cit;
  ++std_cit;

  l0.splice(cit, l1);
  std_l0.splice(std_cit, std_l1);

  for (it = l0.begin(), std_it = std_l0.begin(); it != l0.end(); ++it, ++std_it)
    EXPECT_EQ(*it, *std_it);

  // пустой список
  list<int> l2;
  l2.sort();

  // список из одного элемента
  list<int> l3 = {1};
  l3.sort();
}

TEST(list, 21) {
  list<double> v = {-2, 6, 5, 8};
  auto it = v.begin();
  ++ ++it;
  v.insert_many(it, 8, 1, 4, 12, -6);
  ASSERT_EQ(v.size(), 9);
}

TEST(list, 22) {
  list<double> v = {-2, 6, 5, 8};
  auto it = v.begin();
  ++it;

  v.insert_many_back(8, 1, 4, 12, -6);
  ASSERT_EQ(v.size(), 9);
  ASSERT_EQ(v.back(), -6);
}

TEST(list, 23) {
  list<double> v = {-2, 6, 5, 8};
  auto it = v.begin();
  ++it;

  v.insert_many_front(8, 1, 4, 12, -6);
  ASSERT_EQ(v.size(), 9);
  ASSERT_EQ(v.front(), 8);
}
