#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

// 57. Insert Interval
class Solution {
 public:
  using Vector = std::vector<std::vector<int>>;

  Vector insert(const Vector& intervals, const std::vector<int>& newInterval) {
    Vector result;
    auto start = newInterval[0];
    auto end = newInterval[1];
    for (const auto& interval : intervals) {
      if (end < interval[0]) {
        result.push_back({start, end});
        start = interval[0];
        end = interval[1];
      } else if (start > interval[1]) {
        result.push_back(interval);
      } else {
        start = std::min(start, interval[0]);
        end = std::max(end, interval[1]);
      }
    }
    result.push_back({start, end});
    return result;
  }
};

TEST_CASE("Insert Intervals") {
  Solution s;
  REQUIRE_EQ(s.insert({{1, 3}, {6, 9}}, {2, 5}),
             Solution::Vector{{1, 5}, {6, 9}});
  REQUIRE_EQ(s.insert({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}),
             Solution::Vector{{1, 2}, {3, 10}, {12, 16}});
}
