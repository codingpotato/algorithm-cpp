#include <doctest/doctest.h>

#include <climits>
#include <vector>

// 322. Coin Change
class Solution {
 public:
  int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto i = 1; i <= amount; ++i) {
      for (const auto& c : coins) {
        if (i >= c && dp[i - c] != INT_MAX && dp[i - c] + 1 < dp[i]) {
          dp[i] = dp[i - c] + 1;
        }
      }
    }
    return dp[amount] != INT_MAX ? dp[amount] : -1;
  }
};

TEST_CASE("Coin Change") {
  Solution s;
  REQUIRE_EQ(s.coinChange({1, 2, 5}, 11), 3);
  REQUIRE_EQ(s.coinChange({2}, 3), -1);
  REQUIRE_EQ(s.coinChange({2, 5, 10, 1}, 27), 4);
}
