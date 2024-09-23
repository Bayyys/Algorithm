/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 * @lcpr version=30204
 *
 * [1014] 最佳观光组合
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
  int maxScoreSightseeingPair(vector<int> &values) {
    // score = values[i] + values[j] + i - j
    int n = values.size();
    int ans = 0;
    int maxLeft = values[0] + 0;
    for (int i = 1; i < n; i++) {
      ans = max(ans, maxLeft + values[i] - i);
      maxLeft = max(maxLeft, values[i] + i);
    }
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [8,1,5,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
