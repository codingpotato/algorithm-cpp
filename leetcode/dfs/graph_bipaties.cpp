#include <doctest/doctest.h>

#include <vector>

// 785. Is Graph Bipartite?
class Solution {
 public:
  using Graph = std::vector<std::vector<int>>;
  enum Color { none, red, black };

  bool isBipartite(const Graph& graph) {
    std::vector<Color> colors(graph.size(), none);
    for (size_t i = 0; i < graph.size(); ++i) {
      if (colors[i] == none) {
        if (!visit(graph, i, red, colors)) return false;
      }
    }
    return true;
  }

 private:
  bool visit(const Graph& graph, int i, Color color,
             std::vector<Color>& colors) {
    colors[i] = color;
    for (const auto next : graph[i]) {
      if (colors[next] == none) {
        if (!visit(graph, next, color == red ? black : red, colors))
          return false;
      }
      if (colors[next] == colors[i]) return false;
    }
    return true;
  }
};

TEST_CASE("Is Graph Bipartite?") {
  Solution s;
  REQUIRE(s.isBipartite({{1, 3}, {0, 2}, {1, 3}, {0, 2}}));
  REQUIRE_FALSE(s.isBipartite({{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}));
}
