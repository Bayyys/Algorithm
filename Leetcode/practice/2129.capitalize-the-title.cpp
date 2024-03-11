/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 * @lcpr version=30119
 *
 * [2129] 将标题首字母大写
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
  string capitalizeTitle(string title) {
    vector<int> spaces;
    spaces.emplace_back(-1);
    int n = title.size();
    for (int i = 0; i < n; i++) {
      if (title[i] == ' ') {
        spaces.emplace_back(i);
      }
    }
    spaces.emplace_back(n);
    int s = spaces[0] + 1;
    for (int i = 1; i < spaces.size(); i++) {
      int e = spaces[i];
      if (spaces[i] - spaces[i - 1] <= 3) {
        // 变为小写
        for (int j = s; j < e; j++) {
          title[j] = tolower(title[j]);
        }
      } else {
        // 变为大写
        title[s] = toupper(title[s]);
        s++;
        for (int j = s; j < e; j++) {
          title[j] = tolower(title[j]);
        }
      }
      s = e + 1;
    }
    return title;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "capiTalIze tHe titLe"\n
// @lcpr case=end

// @lcpr case=start
// "First leTTeR of EACH Word"\n
// @lcpr case=end

// @lcpr case=start
// "i lOve leetcode"\n
// @lcpr case=end

 */
