#include <gtest/gtest.h>

#include <vector>

#include "../s21_containers.h"

TEST(vector, 1) {
  s21::vector<int> s21_v;
  for (size_t i = 0; i < s21_v.size(); ++i) {
    ASSERT_EQ(s21_v[i], i);
  }
}

TEST(vector, 2) {
  s21::vector<unsigned int> s21_v = {1, 2, 3};
  std::vector<unsigned int> v = {1, 2, 3};
  for (int i = 0; i != 3; ++i) {
    ASSERT_EQ(s21_v[i], v[i]);
  }
}

TEST(vector, 3) {
  s21::vector<double> s21_v = {0, 1, 2};
  s21_v.push_back(3);
  std::vector<double> v = {0, 1, 2};
  v.push_back(3);
  for (auto i = 0; i != 4; ++i) {
    ASSERT_EQ(s21_v[i], v[i]);
  }
}

TEST(vector, 5) {
  s21::vector<double> s21_v = {1};
  ASSERT_FALSE(s21_v.empty());
  s21_v.pop_back();
  ASSERT_TRUE(s21_v.empty());
}

TEST(vector, 7) {
  s21::vector<double> s21_v = {1, 1, 3};
  std::vector<int> v = {2, 4};
  s21_v.clear();
  v.clear();
  ASSERT_TRUE(s21_v.empty());
  ASSERT_EQ(v.empty(), s21_v.empty());
}

TEST(vector, 8) {
  s21::vector<double> s21_v = {0.2, 0.02, 0.111};
  s21::vector<double> s21_v2;
  s21_v2 = s21_v;
  for (size_t i = 0; i < s21_v.size(); ++i) {
    ASSERT_EQ(s21_v[i], s21_v2[i]);
  }
}

TEST(vector, 9) {
  s21::vector<double> v = {6, 5, 8};
  std::vector<double> vc = {6, 5, 8};
  ASSERT_EQ(v.front(), vc.front());
  ASSERT_EQ(v.back(), vc.back());
}

TEST(vector, 10) {
  s21::vector<double> v = {-2.4, 6.6, 5, 8};
  std::vector<double> vc = {-2.4, 6.6, 5, 8};
  ASSERT_EQ(*v.begin(), *vc.begin());
}

TEST(vector, 11) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v.max_size(), vc.max_size());
}

TEST(vector, 12) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  v.reserve(20);
  vc.reserve(20);
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v.max_size(), vc.max_size());
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 13) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  v.reserve(20);
  vc.reserve(20);
  v.shrink_to_fit();
  vc.shrink_to_fit();
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v.max_size(), vc.max_size());
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 14) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  v.clear();
  vc.clear();
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v.max_size(), vc.max_size());
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 15) {
  s21::vector<int> v = {-2, 6, 5, 8};
  std::vector<int> vc = {-2, 6, 5, 8};
  v.insert(v.begin(), 15);
  vc.insert(vc.begin(), 15);
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v[0], vc[0]);
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 16) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  v.erase(v.begin());
  vc.erase(vc.begin());
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v[0], vc[0]);
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 17) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  v.push_back(15);
  vc.push_back(15);
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v[4], vc[4]);
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 18) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  v.pop_back();
  vc.pop_back();
  ASSERT_EQ(v.size(), vc.size());
  ASSERT_EQ(v.capacity(), vc.capacity());
}

TEST(vector, 19) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  s21::vector<double> v2;
  std::vector<double> vc2;
  v.swap(v2);
  vc.swap(vc2);
  ASSERT_EQ(v2.size(), vc2.size());
  ASSERT_EQ(v2.capacity(), vc2.capacity());
}

TEST(vector, 20) {
  s21::vector<double> v = {-2, 6, 5, 8};
  std::vector<double> vc = {-2, 6, 5, 8};
  auto v2 = v.begin();
  auto vc2 = vc.begin();
  ASSERT_EQ(*v2, *vc2);
  v2++;
  vc2++;
  ASSERT_EQ(*v2, *vc2);
}

TEST(vector, 21) {
  s21::vector<int> v = {-2, 6, 5, 8};
  auto it = v.begin();
  ++it;
  ++it;
  v.insert_many(it, 8, 1, 4, 12, -6);
  ASSERT_EQ(v.size(), 9);
  ASSERT_EQ(v.at(2), 8);
}

TEST(vector, 22) {
  s21::vector<double> v = {-2, 6, 5, 8};
  auto it = v.begin();
  ++it;

  v.insert_many_back(8, 1, 4, 12, -6);
  ASSERT_EQ(v.size(), 9);
  ASSERT_EQ(v.at(5), 1);
  ASSERT_EQ(v.back(), -6);
}

TEST(vector_test, at1) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, operator_brackets) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1[i], vec2[i]);
  }
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, front) {
  s21::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.front(), vec2.front());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, back) {
  s21::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.back(), vec2.back());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, data) {
  s21::vector<int> vec1;
  EXPECT_EQ(vec1.data(), nullptr);
  s21::vector<int> vec2 = {1, 2, 3};
  EXPECT_FALSE(vec2.data() == nullptr);
}

TEST(vector_test, begin) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.begin();
  auto iter2 = vec2.begin();
  EXPECT_EQ(*iter1, *iter2);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, end) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  auto iter1 = vec1.end();
  auto iter2 = vec2.end();
  EXPECT_EQ(*(iter1 - 1), *(iter2 - 1));
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, size) {
  s21::vector<int> vec1;
  std::vector<int> vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), 0);
  vec1 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, reserve) {
  s21::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  vec1.reserve(100);
  vec2.reserve(100);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, capacity) {
  s21::vector<int> vec1;
  std::vector<int> vec2;
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  vec1 = {1, 2, 3};
  vec2 = {1, 2, 3};
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, shrink_to_fit) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.push_back(11);
  vec2.push_back(11);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, clear) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.clear();
  vec2.clear();

  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, push_back) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.push_back(11);
  vec2.push_back(11);
  EXPECT_EQ(vec1[10], vec2[10]);
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, pop_back) {
  s21::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec1.pop_back();
  vec2.pop_back();
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
}

TEST(vector_test, swap) {
  s21::vector<int> vec1 = {1, 2, 3};
  s21::vector<int> vec1_1 = {3, 2, 1};
  vec1.swap(vec1_1);
  for (int i = 0, j = 3; i < 3; i++) {
    EXPECT_EQ(vec1_1[i], i + 1);
    EXPECT_EQ(vec1[i], j--);
  }
}

TEST(vector_test, operator_eq) {
  s21::vector<int> vec1 = {1, 2, 3, 5, 6, 3, 4};
  s21::vector<int> vec2;
  vec2 = vec1;
  EXPECT_EQ(vec1.size(), vec2.size());
  EXPECT_EQ(vec1.capacity(), vec2.capacity());
  auto it_2 = vec2.begin();
  for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }