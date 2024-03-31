/*
 * @lc app=leetcode.cn id=331 lang=cpp
 * @lcpr version=30121
 *
 * [331] 验证二叉树的前序序列化
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
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    int n = preorder.size();
    int i = 0;
    int slots = 1;
    while (i < n) {
      if (slots == 0) return false;
      if (preorder[i] == '#') {
        slots--;
        i++;
      } else {
        while (i < n && preorder[i] != ',') i++;
        slots++;
      }
      while (i < n && preorder[i] == ',') i++;
    }
    return slots == 0;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "9,3,4,#,#,1,#,#,2,#,6,#,#"\n
// @lcpr case=end

// @lcpr case=start
// "1,#"\n
// @lcpr case=end

// @lcpr case=start
// "9,#,#,1"\n
// @lcpr case=end

 */
