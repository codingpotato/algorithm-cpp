#include <doctest/doctest.h>

#include <vector>

// 303. Range Sum Query - Immutable
class NumArray {
 public:
  NumArray(const std::vector<int>& nums) {
    sums.push_back(0);
    for (auto n : nums) {
      sums.push_back(sums.back() + n);
    }
  }

  int sumRange(int i, int j) { return sums[j + 1] - sums[i]; }

 private:
  std::vector<int> sums;
};

TEST_CASE("Range sum query - immutable") {
  NumArray array{{-2, 0, 3, -5, 2, -1}};
  REQUIRE_EQ(array.sumRange(0, 2), 1);
  REQUIRE_EQ(array.sumRange(0, 5), -3);
}
