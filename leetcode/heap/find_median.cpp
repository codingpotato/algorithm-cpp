#include <doctest/doctest.h>

#include <queue>

// 295. Find Median from Data Stream
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (small.empty() && big.empty()) {
      small.push(num);
    } else if (big.empty()) {
      if (num <= small.top()) {
        big.push(small.top());
        small.pop();
        small.push(num);
      } else {
        big.push(num);
      }
    } else {
      if (num <= small.top()) {
        if (small.size() > big.size()) {
          big.push(small.top());
          small.pop();
        }
        small.push(num);
      } else if (num >= big.top()) {
        if (big.size() > small.size()) {
          small.push(big.top());
          big.pop();
        }
        big.push(num);
      } else {
        if (small.size() > big.size()) {
          big.push(num);
        } else {
          small.push(num);
        }
      }
    }
  }

  double findMedian() {
    if (small.size() == big.size()) {
      return static_cast<double>(small.top() + big.top()) / 2;
    } else if (small.size() > big.size()) {
      return small.top();
    } else {
      return big.top();
    }
  }

 private:
  std::priority_queue<int> small;
  std::priority_queue<int, std::vector<int>, std::greater<int>> big;
};

TEST_CASE("Find Median from Data Stream") {
  SUBCASE("Case 1") {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    REQUIRE_EQ(medianFinder.findMedian(), 1.5);
    medianFinder.addNum(3);
    REQUIRE_EQ(medianFinder.findMedian(), 2);
  }

  SUBCASE("Case 2") {
    MedianFinder medianFinder;
    medianFinder.addNum(-1);
    REQUIRE_EQ(medianFinder.findMedian(), -1);
    medianFinder.addNum(-2);
    REQUIRE_EQ(medianFinder.findMedian(), -1.5);
    medianFinder.addNum(-3);
    REQUIRE_EQ(medianFinder.findMedian(), -2);
    medianFinder.addNum(-4);
    REQUIRE_EQ(medianFinder.findMedian(), -2.5);
    medianFinder.addNum(-5);
    REQUIRE_EQ(medianFinder.findMedian(), -3);
  }
}
