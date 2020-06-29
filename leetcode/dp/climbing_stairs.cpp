#include <doctest/doctest.h>

// 70. Climbing Stairs
class Solution {
 public:
  int climbStairs(int n) {
    auto previous = 1;
    auto current = 1;
    for (auto i = 1; i < n; ++i) {
      auto next = previous + current;
      previous = current;
      current = next;
    }
    return current;
  }
};

TEST_CASE("Climbing stairs") {
  Solution s;
  REQUIRE_EQ(s.climbStairs(2), 2);
  REQUIRE_EQ(s.climbStairs(3), 3);
}
