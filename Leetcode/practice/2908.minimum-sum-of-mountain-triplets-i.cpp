/*
 * @lc app=leetcode.cn id=2908 lang=cpp
 * @lcpr version=30121
 *
 * [2908] 元素和最小的山形三元组 I
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
  int minimumSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> left(n, 100), right(n, 100);
    int mn = 100;
    for (int i = 1; i < n; i++) {
      mn = min(mn, nums[i - 1]);
      left[i] = mn;
    }
    mn = 100;
    for (int i = n - 2; i >= 0; i--) {
      mn = min(mn, nums[i + 1]);
      right[i] = mn;
    }
    int ans = 200;
    for (int i = 1; i < n - 1; i++) {
      if (nums[i] > left[i] && nums[i] > right[i]) {
        ans = min(ans, left[i] + nums[i] + right[i]);
      }
    }
    return ans < 200 ? ans : -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [8,6,1,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,7,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,3,4,5]\n
// @lcpr case=end

 */
