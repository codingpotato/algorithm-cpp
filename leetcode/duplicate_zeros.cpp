#include <doctest/doctest.h>

#include <vector>

// 1089. Duplicate Zeros
class Solution {
public:
  void duplicateZeros(std::vector<int> &arr) {
    auto src = 0;
    auto target = 0;
    while (target < arr.size()) {
      target = arr[src] != 0 ? target + 1 : target + 2;
      ++src;
    }

    --src;
    --target;

    while (src >= 0) {
      if (arr[src] != 0) {
        if (target < arr.size()) {
          arr[target] = arr[src];
        }
        --target;
      } else {
        if (target < arr.size()) {
          arr[target] = arr[src];
        }
        --target;
        if (target < arr.size()) {
          arr[target] = arr[src];
        }
        --target;
      }
      --src;
    }
  }
};

TEST_CASE("Duplicate zeros") {
  std::vector<int> arr{1, 0, 2, 3, 0, 4, 5, 0};
  Solution s;
  s.duplicateZeros(arr);
  REQUIRE_EQ(arr, std::vector{1, 0, 0, 2, 3, 0, 0, 4});
}

TEST_CASE("Duplicate zeros without zero") {
  std::vector<int> arr{1, 2, 3};
  Solution s;
  s.duplicateZeros(arr);
  REQUIRE_EQ(arr, std::vector{1, 2, 3});
}

TEST_CASE("Duplicate zeros one zero") {
  std::vector<int> arr{0};
  Solution s;
  s.duplicateZeros(arr);
  REQUIRE_EQ(arr, std::vector{0});
}

TEST_CASE("Duplicate zeros four zero") {
  std::vector<int> arr{0, 0, 0, 0};
  Solution s;
  s.duplicateZeros(arr);
  REQUIRE_EQ(arr, std::vector{0, 0, 0, 0});
}

TEST_CASE("Duplicate zeros middle zeros") {
  std::vector<int> arr{8, 4, 5, 0, 0, 0, 0, 7};
  Solution s;
  s.duplicateZeros(arr);
  REQUIRE_EQ(arr, std::vector{8, 4, 5, 0, 0, 0, 0, 0});
}
