#include <doctest/doctest.h>

// 371. Sum of Two Integers
class Solution {
 public:
  int getSum(int a, int b) {
    while (b != 0) {
      auto sum = a ^ b;
      auto carry = static_cast<unsigned>(a & b) << 1;
      a = sum;
      b = carry;
    }
    return a;
  }
};

TEST_CASE("Sum of Two Integers") {
  Solution s;
  REQUIRE_EQ(s.getSum(1, 2), 3);
  REQUIRE_EQ(s.getSum(125, 967), 1092);
  REQUIRE_EQ(s.getSum(-2, 3), 1);
  REQUIRE_EQ(s.getSum(-1, 1), 0);
}
