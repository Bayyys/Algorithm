/*
 * @lc app=leetcode.cn id=2951 lang=cpp
 * @lcpr version=30201
 *
 * [2951] 找出峰值
 */

// @lc code=start
class Solution {
 public:
  vector<int> findPeaks(vector<int>& mountain) {
    vector<int> res;
    if (mountain.size() < 3) return res;
    for (int i = 1; i < mountain.size() - 1; i++) {
      if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
        res.push_back(i);
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3,8,5]\n
// @lcpr case=end

 */
