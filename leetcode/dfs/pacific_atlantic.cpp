#include <doctest/doctest.h>

#include <vector>

// 417. Pacific Atlantic Water Flow
class Solution {
 public:
  using Matrix = std::vector<std::vector<int>>;

  Matrix pacificAtlantic(const Matrix& matrix) {
    Matrix result;
    if (matrix.empty()) return result;

    auto pacific = to_pacific(matrix);
    auto atlantic = to_atlantic(matrix);

    for (auto i = 0; i < static_cast<int>(matrix.size()); ++i) {
      for (auto j = 0; j < static_cast<int>(matrix[i].size()); ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }

 private:
  using Status = std::vector<std::vector<bool>>;

  Status to_pacific(const Matrix& matrix) {
    Status status{matrix.size(), std::vector<bool>(matrix[0].size(), false)};
    for (size_t i = 0; i < matrix.size(); ++i) {
      visit(matrix, i, 0, status);
    }
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      visit(matrix, 0, j, status);
    }
    return status;
  }

  Status to_atlantic(const Matrix& matrix) {
    Status status{matrix.size(), std::vector<bool>(matrix[0].size(), false)};
    for (size_t i = 0; i < matrix.size(); ++i) {
      visit(matrix, i, matrix[0].size() - 1, status);
    }
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      visit(matrix, matrix.size() - 1, j, status);
    }
    return status;
  }

  void visit(const Matrix& matrix, int i, int j, Status& status) {
    status[i][j] = true;
    if (i > 0 && !status[i - 1][j] && matrix[i][j] <= matrix[i - 1][j]) {
      visit(matrix, i - 1, j, status);
    }
    if (i < static_cast<int>(matrix.size()) - 1 && !status[i + 1][j] &&
        matrix[i][j] <= matrix[i + 1][j]) {
      visit(matrix, i + 1, j, status);
    }
    if (j > 0 && !status[i][j - 1] && matrix[i][j] <= matrix[i][j - 1]) {
      visit(matrix, i, j - 1, status);
    }
    if (j < static_cast<int>(matrix[i].size()) - 1 && !status[i][j + 1] &&
        matrix[i][j] <= matrix[i][j + 1]) {
      visit(matrix, i, j + 1, status);
    }
  }
};

TEST_CASE("Pacific Atlantic Water Flow") {
  Solution s;

  SUBCASE("Case 1") {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4},
    };
    std::vector<std::vector<int>> expected = {
        {0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0},
    };
    REQUIRE_EQ(s.pacificAtlantic(matrix), expected);
  }

  SUBCASE("Case 2") {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5},
    };
    std::vector<std::vector<int>> expected = {
        {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2},
    };
    REQUIRE_EQ(s.pacificAtlantic(matrix), expected);
  }
}
