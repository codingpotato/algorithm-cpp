#include <doctest/doctest.h>

// 461. Hamming Distance
class Solution {
 public:
  int hammingDistance(int x, int y) {
    auto n = x ^ y;
    auto result = 0;
    while (n != 0) {
      n &= n - 1;
      ++result;
    }
    return result;
  }
};

TEST_CASE("Hamming Distance") {
  Solution s;
  REQUIRE_EQ(s.hammingDistance(1, 4), 2);
}
