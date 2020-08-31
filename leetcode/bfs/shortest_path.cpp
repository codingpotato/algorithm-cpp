#include <doctest/doctest.h>

#include <queue>
#include <vector>

// 1129. Shortest Path with Alternating Colors
class Solution {
 public:
  enum Color { none, red, blue };

  std::vector<int> shortestAlternatingPaths(
      int n, const std::vector<std::vector<int>>& red_edges,
      const std::vector<std::vector<int>>& blue_edges) {
    Graph red_graph = make_graph(n, red_edges);
    Graph blue_graph = make_graph(n, blue_edges);
    std::vector<int> result(n, -1);
    std::queue<Info> queue;
    queue.emplace(0, none, 0);
    while (!queue.empty()) {
      auto [node, color, paths] = queue.front();
      queue.pop();
      if (result[node] == -1 || paths < result[node]) {
        result[node] = paths;
      }
      if (color == none || color == blue) {
        for (size_t i = 0; i < red_graph[node].size(); ++i) {
          if (red_graph[node][i]) {
            red_graph[node][i] = false;
            queue.emplace(i, red, paths + 1);
          }
        }
      }
      if (color == none || color == red) {
        for (size_t i = 0; i < blue_graph[node].size(); ++i) {
          if (blue_graph[node][i]) {
            blue_graph[node][i] = false;
            queue.emplace(i, blue, paths + 1);
          }
        }
      }
    }
    return result;
  }

 private:
  struct Info {
    Info(int node, Color color, int paths)
        : node{node}, color{color}, paths{paths} {}

    int node;
    Color color;
    int paths;
  };

  using Graph = std::vector<std::vector<bool>>;

  Graph make_graph(int n, const std::vector<std::vector<int>>& edges) {
    Graph graph(n, std::vector<bool>(n));
    for (const auto& edge : edges) {
      graph[edge[0]][edge[1]] = true;
    }
    return graph;
  }
};

TEST_CASE("Shortest Path with Alternating Colors") {
  Solution s;
  REQUIRE_EQ(s.shortestAlternatingPaths(3, {{0, 1}, {1, 2}}, {}),
             std::vector<int>{0, 1, -1});
  REQUIRE_EQ(s.shortestAlternatingPaths(3, {{0, 1}}, {{2, 1}}),
             std::vector<int>{0, 1, -1});
  REQUIRE_EQ(s.shortestAlternatingPaths(3, {{0, 1}}, {{1, 2}}),
             std::vector<int>{0, 1, 2});
  REQUIRE_EQ(s.shortestAlternatingPaths(3, {{0, 1}, {0, 2}}, {{1, 0}}),
             std::vector<int>{0, 1, 1});
  REQUIRE_EQ(s.shortestAlternatingPaths(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}},
                                        {{1, 2}, {2, 3}, {3, 1}}),
             std::vector<int>{0, 1, 2, 3, 7});
  REQUIRE_EQ(
      s.shortestAlternatingPaths(
          6, {{4, 1}, {3, 5}, {5, 2}, {1, 4}, {4, 2}, {0, 0}, {2, 0}, {1, 1}},
          {{5, 5}, {5, 0}, {4, 4}, {0, 3}, {1, 0}}),
      std::vector<int>{0, -1, 4, 1, -1, 2});
}
