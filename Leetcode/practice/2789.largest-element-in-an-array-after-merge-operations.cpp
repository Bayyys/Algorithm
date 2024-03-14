/*
 * @lc app=leetcode.cn id=2789 lang=cpp
 * @lcpr version=30119
 *
 * [2789] 合并后数组中的最大元素
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
  long long maxArrayValue(vector<int> &nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    long long maxVal = 0;
    long long cur = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] <= cur) {
        cur += nums[i];
      } else {
        cur = nums[i];
      }
      if (cur > maxVal) {
        maxVal = cur;
      }
    }
    return maxVal;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,7,9,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,3,3]\n
// @lcpr case=end

 */
