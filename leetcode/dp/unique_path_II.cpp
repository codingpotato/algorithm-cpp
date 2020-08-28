#include <doctest/doctest.h>

#include <vector>

// 63. Unique Paths II
class Solution {
 public:
  using Map = std::vector<std::vector<int>>;

  int uniquePathsWithObstacles(const Map& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    Map paths(m, std::vector<int>(n, 0));
    for (auto i = 0; i < m; ++i) {
      for (auto j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 0) {
          if (i == 0 && j == 0) {
            paths[i][j] = 1;
          } else if (i == 0) {
            paths[i][j] = paths[i][j - 1];
          } else if (j == 0) {
            paths[i][j] = paths[i - 1][j];
          } else {
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
          }
        }
      }
    }
    return paths[m - 1][n - 1];
  }
};

TEST_CASE("Unique Paths II") {
  Solution s;
  REQUIRE_EQ(s.uniquePathsWithObstacles({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}), 2);
  REQUIRE_EQ(s.uniquePathsWithObstacles({{1}}), 0);
}
