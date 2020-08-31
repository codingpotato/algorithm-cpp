#include <doctest/doctest.h>

#include <stack>
#include <vector>

// 84. Largest Rectangle in Histogram
namespace {

class Solution {
 public:
  int largestRectangleArea(const std::vector<int>& heights) {
    struct Info {
      Info(int index, int height) : index{index}, height{height} {}
      int index;
      int height;
    };

    int size = heights.size();
    std::stack<Info> stack;
    stack.emplace(-1, 0);
    int max_area = 0;
    for (auto i = 0; i <= size; ++i) {
      auto next_height = i < size ? heights[i] : 0;
      while (stack.size() > 1 && next_height <= stack.top().height) {
        auto info = stack.top();
        stack.pop();
        max_area =
            std::max(max_area, info.height * (i - stack.top().index - 1));
      }
      stack.emplace(i, next_height);
    }
    return max_area;
  }
};

}  // namespace

TEST_CASE("Largest Rectangle in Histogram") {
  Solution s;
  REQUIRE_EQ(s.largestRectangleArea({2, 1, 5, 6, 2, 3}), 10);
}
