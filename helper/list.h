#ifndef __LIST__H__
#define __LIST__H__

#include <initializer_list>
#include <iterator>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
};

struct List {
  List(const std::initializer_list<int> &nums) {
    for (auto it = std::rbegin(nums); it != std::rend(nums); ++it) {
      head = new ListNode{*it, head};
    }
  }

  void make_cycle(int pos) {
    REQUIRE(head);
    auto index = 0;
    ListNode *cycle_target = nullptr;
    auto node = head;
    while (node->next) {
      if (index == pos) {
        cycle_target = node;
      }
      node = node->next;
      ++index;
    }
    REQUIRE(cycle_target);
    node->next = cycle_target;
  }

  ListNode *head = nullptr;
};

inline bool is_same(const ListNode *lhs, const ListNode *rhs) {
  while (lhs && rhs) {
    if (lhs->val != rhs->val) return false;
    lhs = lhs->next;
    rhs = rhs->next;
  }
  return lhs == rhs;
}

inline bool is_same(const ListNode *lhs, const std::vector<int> &rhs) {
  size_t index = 0;
  while (lhs && index < rhs.size()) {
    if (lhs->val != rhs[index]) return false;
    lhs = lhs->next;
    ++index;
  }
  return !lhs && index == rhs.size();
}

TEST_CASE("is same as vector") {
  List list{1, 2, 3, 4, 5};
  REQUIRE(is_same(list.head, std::vector<int>{1, 2, 3, 4, 5}));
}

#endif  // __LIST__H__
