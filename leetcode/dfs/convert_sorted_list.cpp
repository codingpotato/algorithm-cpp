#include <doctest/doctest.h>

#include "list.h"
#include "tree.h"

// 109. Convert Sorted List to Binary Search Tree
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    return sortedListToBST(head, nullptr);
  }

 private:
  TreeNode* sortedListToBST(ListNode* head, ListNode* end) {
    if (head == end) return nullptr;
    auto mid = split(head, end);
    auto node = new TreeNode{mid->val};
    node->left = sortedListToBST(head, mid);
    node->right = sortedListToBST(mid->next, end);
    return node;
  }

  ListNode* split(ListNode* head, ListNode* end) {
    auto slow = head;
    auto fast = head;
    while (fast != end && fast->next != end) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

TEST_CASE("Convert Sorted List to Binary Search Tree") {
  Solution s;

  SUBCASE("Case 1") {
    List list{-10, -3, 0, 5, 9};
    auto root = s.sortedListToBST(list.head);
    Tree expected{"0, -3, 9, -10, null, 5"};
    REQUIRE(is_same(root, expected.root));
  }

  SUBCASE("Case 2") {
    List list{};
    auto root = s.sortedListToBST(list.head);
    Tree expected{""};
    REQUIRE(is_same(root, expected.root));
  }

  SUBCASE("Case 3") {
    List list{0};
    auto root = s.sortedListToBST(list.head);
    Tree expected{"0"};
    REQUIRE(is_same(root, expected.root));
  }

  SUBCASE("Case 4") {
    List list{1, 3};
    auto root = s.sortedListToBST(list.head);
    Tree expected{"3, 1"};
    REQUIRE(is_same(root, expected.root));
  }
}
