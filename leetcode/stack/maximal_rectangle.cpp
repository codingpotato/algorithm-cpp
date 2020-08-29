#include <doctest/doctest.h>

#include <stack>
#include <vector>

// 85. Maximal Rectangle
class Solution {
 public:
  int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    std::vector<int> heights(n);
    int max_area = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1') {
          ++heights[j];
        } else {
          heights[j] = 0;
        }
      }
      max_area = std::max(max_area, calculate_max_area(heights));
    }
    return max_area;
  }

 private:
  int calculate_max_area(const std::vector<int>& heights) {
    struct Info {
      Info(int index, int height) : index{index}, height{height} {}
      int index;
      int height;
    };
    std::stack<Info> stack;
    stack.emplace(-1, 0);
    const int size = heights.size();
    int max_area = 0;
    for (int i = 0; i <= size; ++i) {
      int next_height = i < size ? heights[i] : 0;
      while (stack.size() > 1 && next_height <= stack.top().height) {
        auto height = stack.top().height;
        stack.pop();
        max_area = std::max(max_area, height * (i - stack.top().index - 1));
      }
      stack.emplace(i, next_height);
    }
    return max_area;
  }
};

TEST_CASE("Maximal Rectangle") {
  Solution s;
  REQUIRE_EQ(s.maximalRectangle({
                 {'1', '0', '1', '0', '0'},
                 {'1', '0', '1', '1', '1'},
                 {'1', '1', '1', '1', '1'},
                 {'1', '0', '0', '1', '0'},
             }),
             6);
}
