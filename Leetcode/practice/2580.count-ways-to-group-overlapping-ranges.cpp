/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 * @lcpr version=30121
 *
 * [2580] 统计将重叠区间合并成组的方案数
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
const int LEN = 1e9 + 5;
class Solution {
 public:
  static const int MOD = 1e9 + 7;
  int countWays(vector<vector<int>> &ranges) {
    sort(
        ranges.begin(), ranges.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    int n = ranges.size();
    long long res = 1;
    for (int i = 0; i < n;) {
      int r = ranges[i][1];
      int j = i + 1;
      while (j < n && ranges[j][0] <= r) {
        r = max(r, ranges[j][1]);
        j++;
      }
      res = res * 2 % MOD;
      i = j;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[6,10],[5,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[10,20],[2,5],[4,8]]\n
// @lcpr case=end

 */
