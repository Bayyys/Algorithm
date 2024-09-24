/*
 * @lc app=leetcode.cn id=2207 lang=cpp
 * @lcpr version=30204
 *
 * [2207] 字符串中最多数目的子序列
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
  long long maximumSubsequenceCount(string text, string pattern) {
    long long cnt1 = 0, cnt2 = 0;
    long long ans = 0;
    for (auto c : text) {
      if (c == pattern[0] || c == pattern[1]) {
        if (c == pattern[0])
          cnt1++;
        else {
          cnt2++;
          ans += cnt1;
        }
      }
    }
    if (pattern[0] == pattern[1]) {
      long long all = cnt1 + cnt2;
      return (1 + all) * all / 2;
    }
    ans += max(cnt1, cnt2);
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abdcdbc"\n"ac"\n
// @lcpr case=end

// @lcpr case=start
// "aabb"\n"ab"\n
// @lcpr case=end

 */
