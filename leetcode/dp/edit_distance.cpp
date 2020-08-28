#include <doctest/doctest.h>

#include <string>
#include <vector>

// 72. Edit Distance
class Solution {
 public:
  int minDistance(const std::string& word1, const std::string& word2) {
    int m = word1.size();
    int n = word2.size();
    std::vector<std::vector<int>> table(m, std::vector<int>(n, -1));
    return minDistance(word1, word2, m, n, 0, 0, table);
  }

 private:
  int minDistance(const std::string& word1, const std::string& word2, int m,
                  int n, int i, int j, std::vector<std::vector<int>>& table) {
    if (i == m && j == n) return 0;
    if (i == m) return n - j;
    if (j == n) return m - i;
    if (table[i][j] == -1) {
      table[i][j] = minDistance(word1, word2, m, n, i + 1, j + 1, table) +
                    (word1[i] == word2[j] ? 0 : 1);
      table[i][j] = std::min(
          table[i][j], minDistance(word1, word2, m, n, i + 1, j, table) + 1);
      table[i][j] = std::min(
          table[i][j], minDistance(word1, word2, m, n, i, j + 1, table) + 1);
    }
    return table[i][j];
  }
};

TEST_CASE("Edit Distance") {
  Solution s;
  REQUIRE_EQ(s.minDistance("horse", "ros"), 3);
  REQUIRE_EQ(s.minDistance("intention", "execution"), 5);
  REQUIRE_EQ(s.minDistance("plasma", "altruism"), 6);
}
