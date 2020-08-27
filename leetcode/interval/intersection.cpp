#include <doctest/doctest.h>

#include <vector>

// 986. Interval List Intersections
class Solution {
 public:
  using Intervals = std::vector<std::vector<int>>;

  Intervals intervalIntersection(const Intervals& A, const Intervals& B) {
    Intervals intervals;
    if (A.empty() && B.empty()) return intervals;

    size_t i = 0;
    size_t j = 0;
    auto [start, end] = get_first(A, B, i, j);
    while (has_interval(A, B, i, j)) {
      auto [next_s, next_e] = get_first(A, B, i, j);
      if (next_s <= end) {
        intervals.push_back({next_s, std::min(end, next_e)});
      }
      start = next_e > end ? next_s : start;
      end = next_e > end ? next_e : end;
    }
    return intervals;
  }

 private:
  bool has_interval(const Intervals& A, const Intervals& B, size_t i,
                    size_t j) {
    return i < A.size() || j < B.size();
  }

  std::pair<int, int> get_first(const Intervals& A, const Intervals& B,
                                size_t& i, size_t& j) {
    if (i < A.size() && j < B.size()) {
      if (A[i][0] < B[j][0]) {
        auto result = std::make_pair(A[i][0], A[i][1]);
        ++i;
        return result;
      } else {
        auto result = std::make_pair(B[j][0], B[j][1]);
        ++j;
        return result;
      }
    } else if (i < A.size()) {
      auto result = std::make_pair(A[i][0], A[i][1]);
      ++i;
      return result;
    } else {
      auto result = std::make_pair(B[j][0], B[j][1]);
      ++j;
      return result;
    }
  }
};

TEST_CASE("Interval List Intersections") {
  Solution s;
  REQUIRE_EQ(s.intervalIntersection({{0, 2}, {5, 10}, {13, 23}, {24, 25}},
                                    {{1, 5}, {8, 12}, {15, 24}, {25, 26}}),
             Solution::Intervals{
                 {1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}});
}
