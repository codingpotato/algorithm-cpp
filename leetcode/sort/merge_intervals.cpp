#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

// 56. Merge Intervals
class Solution {
 public:
  using Vector = std::vector<std::vector<int>>;

  Vector merge(Vector& intervals) {
    if (intervals.empty()) return intervals;
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) { return a[0] < b[0]; });

    Vector result;
    auto start = intervals[0][0];
    auto end = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= start && intervals[i][0] <= end) {
        end = std::max(end, intervals[i][1]);
      } else {
        result.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }
    result.push_back({start, end});
    return result;
  }
};

TEST_CASE("Merge Intervals") {
  Solution s;

  SUBCASE("Case 1") {
    Solution::Vector intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    REQUIRE_EQ(s.merge(intervals), Solution::Vector{{1, 6}, {8, 10}, {15, 18}});
  }

  SUBCASE("Case 2") {
    Solution::Vector intervals{{1, 4}, {4, 5}};
    REQUIRE_EQ(s.merge(intervals), Solution::Vector{{1, 5}});
  }
}
