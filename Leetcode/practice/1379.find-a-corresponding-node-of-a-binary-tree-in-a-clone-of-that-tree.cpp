/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 * @lcpr version=30121
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    if (original == nullptr) return nullptr;
    if (original == target) return cloned;
    TreeNode *left = getTargetCopy(original->left, cloned->left, target);
    if (left != nullptr) return left;
    return getTargetCopy(original->right, cloned->right, target);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [7,4,3,null,null,6,19]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [8,null,6,null,5,null,4,null,3,null,2,null,1]\n4\n
// @lcpr case=end

 */
