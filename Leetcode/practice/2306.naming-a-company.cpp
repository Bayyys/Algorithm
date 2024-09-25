/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 * @lcpr version=30204
 *
 * [2306] 公司命名
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
  long long distinctNames(vector<string> &ideas) {
    unordered_set<string> s[26];
    for (auto &idea : ideas) {
      s[idea[0] - 'a'].insert(idea.substr(1));
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {  // i: 遍历所有的前缀 (a-z)
      for (int j = 0; j < i; j++) {  // j: 遍历 (a-i) 前缀的所有可能后缀
        int U = 0;
        for (auto &sub : s[i]) {  // sub: 遍历 i 为前缀的后缀
          U += s[j].count(sub);   // 计算公共后缀的数量
        }
        ans += (long long)(s[i].size() - U) *
               (s[j].size() - U);  // 计算不同前缀的组合
      }
    }
    return ans * 2; // 前后缀可以交换
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["coffee","donuts","time","toffee"]\n
// @lcpr case=end

// @lcpr case=start
// ["lack","back"]\n
// @lcpr case=end

 */
