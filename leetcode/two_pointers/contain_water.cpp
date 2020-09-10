#include <doctest/doctest.h>

#include <vector>

// 11. Container With Most Water
class Solution {
 public:
  int maxArea(const std::vector<int>& height) {
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
      max_area = std::max(
          max_area, std::min(height[left], height[right]) * (right - left));
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return max_area;
  }
};

TEST_CASE("Container With Most Water") {
  Solution s;
  REQUIRE_EQ(s.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}), 49);
}
