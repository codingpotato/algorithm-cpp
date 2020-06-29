#include <doctest/doctest.h>

#include <algorithm>
#include <climits>
#include <vector>

// 121. Best Time to Buy and Sell Stock
class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    auto min_price = INT_MAX;
    auto max_profit = 0;
    for (auto n : prices) {
      min_price = std::min(min_price, n);
      max_profit = std::max(max_profit, n - min_price);
    }
    return max_profit;
  }
};

TEST_CASE("Stock once") {
  Solution s;
  REQUIRE_EQ(s.maxProfit({7, 1, 5, 3, 6, 4}), 5);
  REQUIRE_EQ(s.maxProfit({7, 6, 4, 3, 1}), 0);
}
