/*
 * @lc app=leetcode.cn id=871 lang=cpp
 * @lcpr version=30204
 *
 * [871] 最低加油次数
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
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    sort(stations.begin(), stations.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });
    priority_queue<int> pq;
    int to = startFuel, idx = 0, ans = 0;
    while (to < target) {
      while (idx < stations.size() && stations[idx][0] <= to) {
        pq.push(stations[idx][1]);
        idx++;
      }
      if (pq.empty()) break;
      to += pq.top();
      pq.pop();
      ans += 1;
    }
    return to >= target ? ans : -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 100\n1\n[[10,100]]\n
// @lcpr case=end

// @lcpr case=start
// 100\n10\n[[10,60],[20,30],[30,30],[60,40]]\n
// @lcpr case=end

 */
