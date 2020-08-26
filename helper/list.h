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

inline void verify_list(const ListNode *head,
                        const std::vector<int> &expected) {
  for (auto n : expected) {
    REQUIRE_EQ(head->val, n);
    head = head->next;
  }
  REQUIRE_EQ(head, nullptr);
}

#endif  // __LIST__H__
