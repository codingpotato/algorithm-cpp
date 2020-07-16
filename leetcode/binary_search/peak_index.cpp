#include <doctest/doctest.h>

#include <vector>

// 852. Peak Index in a Mountain Array
class Solution {
 public:
  int peakIndexInMountainArray(const std::vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
        return mid;
      } else if (A[mid] < A[mid - 1]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

TEST_CASE("Peak index") {
  Solution s;
  REQUIRE_EQ(s.peakIndexInMountainArray({0, 1, 0}), 1);
  REQUIRE_EQ(s.peakIndexInMountainArray({0, 2, 1, 0}), 1);
  REQUIRE_EQ(s.peakIndexInMountainArray({0, 1, 2, 0}), 2);
  REQUIRE_EQ(s.peakIndexInMountainArray({0, 1, 2, 1, 0}), 2);
  REQUIRE_EQ(s.peakIndexInMountainArray({0, 1, 2}), 2);
  REQUIRE_EQ(s.peakIndexInMountainArray({2, 1, 0}), 0);
  REQUIRE_EQ(s.peakIndexInMountainArray({1, 2}), 1);
}
