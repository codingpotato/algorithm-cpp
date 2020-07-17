#include <doctest/doctest.h>

#include <cmath>
#include <vector>

// 977. Squares of a Sorted Array
class Solution {
 public:
  std::vector<int> sortedSquares(const std::vector<int>& A) {
    std::vector<int> result;
    auto right = smallest_positive_number(A);
    auto left = right - 1;
    while (left >= 0 && right < A.size()) {
      if (std::abs(A[left]) <= std::abs(A[right])) {
        result.push_back(A[left] * A[left]);
        --left;
      } else {
        result.push_back(A[right] * A[right]);
        ++right;
      }
    }
    while (left >= 0) {
      result.push_back(A[left] * A[left]);
      --left;
    }
    while (right < A.size()) {
      result.push_back(A[right] * A[right]);
      ++right;
    }
    return result;
  }

 private:
  int smallest_positive_number(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] >= 0) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

TEST_CASE("Squares") {
  Solution s;
  REQUIRE_EQ(s.sortedSquares({-4, -1, 0, 3, 10}),
             std::vector<int>{0, 1, 9, 16, 100});
  REQUIRE_EQ(s.sortedSquares({-7, -3, 2, 3, 11}),
             std::vector<int>{4, 9, 9, 49, 121});
}
