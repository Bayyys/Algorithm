/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 * @lcpr version=30121
 *
 * [1997] 访问完所有房间的第一天
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
  int firstDayBeenInAllRooms(vector<int> &nextVisit) {
    int n = nextVisit.size();
    int MOD = 1e9 + 7;
    vector<long long> dp(n, 0);
    for (int i = 1; i < n; i++) {
      int j = nextVisit[i - 1];
      dp[i] = (2 * dp[i - 1] - dp[j] + 2 + MOD) % MOD;
    }
    return int(dp[n - 1]);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,0]\n
// @lcpr case=end

 */
