#include <doctest/doctest.h>

#include <array>
#include <vector>

// 733. Flood Fill
class Solution {
 public:
  using Image = std::vector<std::vector<int>>;

  Image floodFill(Image& image, int sr, int sc, int newColor) {
    Image visited{image.size(), std::vector<int>(image[0].size(), 0)};
    floodFill(image, sr, sc, newColor, visited);
    return image;
  }

 private:
  struct Direction {
    int dx;
    int dy;
  };

  void floodFill(Image& image, int i, int j, int newColor, Image& visited) {
    if (!visited[i][j]) {
      visited[i][j] = 1;
      std::array<Direction, 4> directions = {
          Direction{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      for (const auto& d : directions) {
        if (is_color(image, i + d.dx, j + d.dy, image[i][j])) {
          floodFill(image, i + d.dx, j + d.dy, newColor, visited);
        }
      }
      image[i][j] = newColor;
    }
  }

  bool is_color(const Image& image, int i, int j, int color) {
    return i >= 0 && static_cast<size_t>(i) < image.size() && j >= 0 &&
           static_cast<size_t>(j) < image[i].size() && image[i][j] == color;
  }
};

TEST_CASE("Flood Fill") {
  Solution s;
  Solution::Image image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  REQUIRE_EQ(s.floodFill(image, 1, 1, 2),
             Solution::Image{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}});
}
