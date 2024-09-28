/*
 * @lc app=leetcode.cn id=2286 lang=cpp
 * @lcpr version=30204
 *
 * [2286] 以组为单位订音乐会的门票
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
class BookMyShow {
 private:
  vector<int> seats;
  int N, M;
  long long ALL;

 public:
  BookMyShow(int n, int m) {
    seats.resize(n, m);
    N = n, M = m;
    ALL = 1ll * n * m;
  }

  vector<int> gather(int k, int maxRow) {
    if (k > M) return {};
    for (int i = 0; i < seats.size() && i <= maxRow; i++) {
      if (seats[i] >= k) {
        int t = seats[i];
        seats[i] -= k;
        ALL -= k;
        return {i, M - t};
      }
    }
    return {};
  }

  bool scatter(int k, int maxRow) {
    if (k > ALL) return false;
    if (k > 1ll * (maxRow + 1) * M) return false;
    int cnt = 0;
    for (int i = 0; i < seats.size() && i <= maxRow; i++) {
      if (cnt + seats[i] >= k) {
        cnt = k;
        break;
      }
      cnt += seats[i];
    }
    if (cnt < k) return false;
    for (int i = 0; i < seats.size() && i <= maxRow; i++) {
      if (cnt < seats[i]) {
        seats[i] -= cnt;
        ALL -= cnt;
        break;
      } else {
        cnt -= seats[i];
        ALL -= seats[i];
        seats[i] = 0;
      }
    }
    return true;
  }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
// @lc code=end

/*
// @lcpr case=start
// ["BookMyShow", "gather", "gather", "scatter", "scatter"][[2, 5], [4, 0], [2,
0], [5, 1], [5, 1]]\n
// @lcpr case=end

 */
