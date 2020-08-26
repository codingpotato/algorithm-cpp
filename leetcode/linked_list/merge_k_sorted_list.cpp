#include <doctest/doctest.h>

#include <queue>
#include <vector>

#include "list.h"

// 23. Merge k Sorted Lists
class Solution {
 public:
  ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    auto cmp = [](ListNode* node1, ListNode* node2) {
      return node1->val > node2->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> queue{
        cmp};
    for (auto node : lists) {
      while (node) {
        queue.push(node);
        node = node->next;
      }
    }
    ListNode dummy;
    auto current = &dummy;
    while (!queue.empty()) {
      current->next = queue.top();
      queue.pop();
      current = current->next;
    }
    current->next = nullptr;
    return dummy.next;
  }
};

TEST_CASE("Merge k Sorted Lists") {
  Solution s;
  List list1{1, 4, 5};
  List list2{1, 3, 4};
  List list3{2, 6};
  auto head = s.mergeKLists({list1.head, list2.head, list3.head});
  verify_list(head, {1, 1, 2, 3, 4, 4, 5, 6});
}
