/*
 * @lc app=leetcode.cn id=2834 lang=cpp
 * @lcpr version=30118
 *
 * [2834] 找出美丽数组的最小和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;

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
private:
  int mod = 1e9 + 7;

public:
  int minimumPossibleSum(int n, int target) {
    long long ans = 0;
    if (n <= target / 2) {
      ans = (long long)(n * (n + 1) / 2) % mod;
    } else {
      long long m = target / 2;
      ans = ((long long)m * (m + 1) / 2) % mod;
      ans += ((n - m) * ((long long)target + target + n - m - 1) / 2) % mod;
    }
    return (long long)ans % mod;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
