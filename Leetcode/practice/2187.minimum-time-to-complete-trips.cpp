/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 * @lcpr version=30204
 *
 * [2187] 完成旅途的最少时间
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
  long long minimumTime(vector<int> &time, int totalTrips) {
    // 1 <= time.length <= 10^5
    // 1 <= time[i] <= 10^7
    // 1 <= totalTrips <= 10^7
    int min_time = *min_element(time.begin(), time.end());
    long long l = 0, r = 1ll * min_time * totalTrips;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      long long sum = 0;
      for (int t : time) {
        sum += mid / t;
      }
      if (sum >= totalTrips) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
