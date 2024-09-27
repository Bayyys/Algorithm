/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 * @lcpr version=30204
 *
 * [2516] 每种字符至少取 K 个
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
  int takeCharacters(string s, int k) {
    vector<int> cnt(3, 0);
    int l = 0, r = s.size() - 1, ans = s.size(), n = s.size();

    auto min_cnt = [&cnt]() { return *min_element(cnt.begin(), cnt.end()); };

    for (auto &c : s) {
      cnt[c - 'a']++;
      if (min_cnt() >= k) break;
      l++;
    }
    if (l > r) return -1;

    ans = l + 1;
    while (l >= 0) {
      cnt[s[l] - 'a']--, l--;
      while (min_cnt() < k) {
        cnt[s[r] - 'a']++, r--;
      }
      ans = min(ans, l + n - r);
    }
    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aabaaaacaabc"\n2\n
// @lcpr case=end

// @lcpr case=start
// "a"\n1\n
// @lcpr case=end

 */
