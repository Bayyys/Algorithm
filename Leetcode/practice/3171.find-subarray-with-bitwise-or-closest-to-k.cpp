/*
 * @lc app=leetcode.cn id=3171 lang=cpp
 * @lcpr version=30204
 *
 * [3171] 找到按位或最接近 K 的子数组
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
  int minimumDifference(vector<int> &nums, int k) {
    vector<int> bits(32, 0);  // 统计每个位上的1的个数
    int l = 0, r = 0;
    int diff = INT_MAX;
    int cur = 0;
    for (l = 0; l < nums.size(); l++) {
      while (r < nums.size() && cur < k) {
        cur |= nums[r];
        updateBits(bits, nums[r], 1);
        r++;
        diff = min(diff, abs(cur - k));
      }
      if (cur == k) {
        return 0;
      }

      updateBits(bits, nums[l], -1);
      cur = getVal(bits);

      if (cur > 0) {
        diff = min(diff, abs(cur - k));
      }
    }
    return diff;
  }

 private:
  // 更新bits数组
  // val: 要更新的值
  // sign: 1表示加，-1表示减
  void updateBits(vector<int> &bits, int val, int sign) {
    int pos = 0;
    while (val > 0) {
      if (val & 1) {
        bits[pos] += sign;
      }
      val >>= 1;
      pos++;
    }
  };

  // 获取bits数组表示的值
  int getVal(const vector<int> &bits) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
      if (bits[i] > 0) {
        cnt += 1 << i;
      }
    }
    return cnt;
  };
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n10\n
// @lcpr case=end

 */
