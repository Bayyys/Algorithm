/*
 * @lc app=leetcode.cn id=2386 lang=cpp
 * @lcpr version=30118
 *
 * [2386] 找出数组的第 K 大和
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
  long long kSum(vector<int> &nums, int k) {
    long long max_sum = 0LL;
    for (auto &n : nums) {
      if (n > 0) {
        max_sum += n;
      } else {
        n = -n;
      }
    }
    // auto cmp = [](pair<long long, int> &a, pair<long long, int> &b) {
    //   return a.first > b.first;
    // };
    sort(nums.begin(), nums.end(), less<int>());
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   //  decltype(cmp)>
                   greater<>>
        pq;
    pq.emplace(0, 0);
    while (--k) {
      auto [sum, i] = pq.top();
      pq.pop();
      if (i < nums.size()) {
        pq.emplace(sum + nums[i], i + 1);
        if (i) pq.emplace(sum + nums[i] - nums[i - 1], i + 1);
      }
    }
    return max_sum - pq.top().first;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,-2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,3,4,-10,12]\n16\n
// @lcpr case=end

 */
