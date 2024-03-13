/*
 * @lc app=leetcode.cn id=2864 lang=cpp
 * @lcpr version=30119
 *
 * [2864] 最大二进制奇数
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
  string maximumOddBinaryNumber(string s) {
    int n = s.size();
    int num = 0;
    string ans = "";
    for (auto &c : s) {
      if (c == '1') {
        num++;
      }
      ans += "0";
    }
    num--;
    for (int i = 0; i < n; i++) {
      if (num) {
        ans[i] = '1';
        num--;
      } else {
        break;
      }
    }
    ans[n - 1] = '1';
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "010"\n
// @lcpr case=end

// @lcpr case=start
// "0101"\n
// @lcpr case=end

 */
