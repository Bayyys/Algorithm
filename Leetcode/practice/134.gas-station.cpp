/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30111
 *
 * [134] 加油站
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
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    int val = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i];
      val += gas[i] - cost[i];
      if (val < 0) {
        start = i + 1;
        val = 0;
      }
    }
    if (sum < 0) return -1;
    return start;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */
