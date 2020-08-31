#include <doctest/doctest.h>

#include <vector>

// 622. Design Circular Queue
class MyCircularQueue {
 public:
  MyCircularQueue(int k) : v(k), back(k - 1), front{0}, size{0} {}

  bool enQueue(int value) {
    if (isFull()) return false;
    back = (back + 1) % v.size();
    v[back] = value;
    ++size;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    front = (front + 1) % v.size();
    --size;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;
    return v[front];
  }

  int Rear() {
    if (isEmpty()) return -1;
    return v[back];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == v.size(); }

 private:
  std::vector<int> v;
  int back;
  int front;
  size_t size;
};

TEST_CASE("Design Circular Queue") {
  SUBCASE("Case 1") {
    MyCircularQueue circularQueue{3};
    REQUIRE_EQ(circularQueue.enQueue(1), true);
    REQUIRE_EQ(circularQueue.enQueue(2), true);
    REQUIRE_EQ(circularQueue.enQueue(3), true);
    REQUIRE_EQ(circularQueue.enQueue(4), false);
    REQUIRE_EQ(circularQueue.Rear(), 3);
    REQUIRE_EQ(circularQueue.isFull(), true);
    REQUIRE_EQ(circularQueue.deQueue(), true);
    REQUIRE_EQ(circularQueue.enQueue(4), true);
    REQUIRE_EQ(circularQueue.Rear(), 4);
  }

  SUBCASE("Case 2") {
    MyCircularQueue circularQueue{6};
    REQUIRE_EQ(circularQueue.enQueue(6), true);
    REQUIRE_EQ(circularQueue.Rear(), 6);
    REQUIRE_EQ(circularQueue.Rear(), 6);
    REQUIRE_EQ(circularQueue.deQueue(), true);
    REQUIRE_EQ(circularQueue.enQueue(5), true);
    REQUIRE_EQ(circularQueue.Rear(), 5);
    REQUIRE_EQ(circularQueue.deQueue(), true);
    REQUIRE_EQ(circularQueue.Front(), -1);
    REQUIRE_EQ(circularQueue.deQueue(), false);
    REQUIRE_EQ(circularQueue.deQueue(), false);
    REQUIRE_EQ(circularQueue.deQueue(), false);
  }
}
