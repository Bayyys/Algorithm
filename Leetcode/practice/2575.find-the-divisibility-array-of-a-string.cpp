/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 * @lcpr version=30118
 *
 * [2575] 找出字符串的可整除数组
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
  vector<int> divisibilityArray(string word, int m) {
    int n = word.size();
    vector<int> dp;
    long long sum = 0;
    for (auto &ch : word) {
      long long num = ch - '0';
      sum = (sum * 10 + num) % m;
      if (sum % m == 0) {
        dp.emplace_back(1);
        sum = 0;
      } else
        dp.emplace_back(0);
    }
    return dp;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "998244353"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n10\n
// @lcpr case=end

 */
