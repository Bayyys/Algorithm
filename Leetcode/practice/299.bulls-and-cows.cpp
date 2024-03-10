/*
 * @lc app=leetcode.cn id=299 lang=cpp
 * @lcpr version=30119
 *
 * [299] 猜数字游戏
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
  string getHint(string secret, string guess) {
    int A = 0, B = 0;
    vector<pair<int, int>> cnt(26, {0, 0});
    for (auto i = 0; i < secret.size(); i++) {
      if (secret[i] == guess[i]) {
        A++;
        secret[i] = guess[i] = ' ';
      }
    }
    for (auto i = 0; i < secret.size(); i++) {
      if (secret[i] != ' ') {
        cnt[secret[i] - '0'].first++;
        cnt[guess[i] - '0'].second++;
      }
    }
    for (auto i = 0; i < 26; i++) {
      B += min(cnt[i].first, cnt[i].second);
    }
    return to_string(A) + "A" + to_string(B) + "B";
  }
};
// @lc code=end

/*
// @lcpr case=start
// "1807"\n"7810"\n
// @lcpr case=end

// @lcpr case=start
// "1123"\n"0111"\n
// @lcpr case=end

 */
