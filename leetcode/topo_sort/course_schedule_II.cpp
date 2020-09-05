#include <doctest/doctest.h>

#include <queue>
#include <vector>

// 210. Course Schedule II
namespace {

class Solution {
 public:
  using Graph = std::vector<std::vector<int>>;

  std::vector<int> findOrder(
      int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    auto [graph, in_degree] = build_graph(numCourses, prerequisites);
    std::vector<int> result;
    std::queue<int> queue;
    for (auto i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0) {
        queue.push(i);
      }
    }
    while (!queue.empty()) {
      auto i = queue.front();
      queue.pop();
      result.push_back(i);
      for (const auto& next : graph[i]) {
        if (--in_degree[next] == 0) {
          queue.push(next);
        }
      }
    }
    for (auto i = 0; i < numCourses; ++i) {
      if (in_degree[i] > 0) {
        return {};
      }
    }
    return result;
  }

 private:
  std::pair<Graph, std::vector<int>> build_graph(
      int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    Graph graph(numCourses);
    std::vector<int> in_degree(numCourses);
    for (const auto& prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
      ++in_degree[prerequisite[0]];
    }
    return {std::move(graph), std::move(in_degree)};
  }
};

}  // namespace

TEST_CASE("Course Schedule II") {
  Solution s;
  REQUIRE_EQ(s.findOrder(2, {{1, 0}}), std::vector<int>{0, 1});
  REQUIRE_EQ(s.findOrder(2, {{0, 1}}), std::vector<int>{1, 0});
  REQUIRE_EQ(s.findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}),
             std::vector<int>{0, 1, 2, 3});
  REQUIRE_EQ(s.findOrder(1, {}), std::vector<int>{0});
  REQUIRE_EQ(s.findOrder(3, {{2, 0}, {2, 1}}), std::vector<int>{0, 1, 2});
}
