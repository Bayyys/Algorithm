/*
 * @lc app=leetcode.cn id=706 lang=cpp
 * @lcpr version=30122
 *
 * [706] 设计哈希映射
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
class MyHashMap {
 private:
  vector<list<pair<int, int>>> data;
  static const int base = 769;
  static int hash(int key) { return key % base; }

 public:
  MyHashMap() : data(base) {}

  void put(int key, int value) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        (*it).second = value;
        return;
      }
    }
    data[h].push_back(make_pair(key, value));
  }

  int get(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        return (*it).second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if ((*it).first == key) {
        data[h].erase(it);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

/*
// @lcpr case=start
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"][[],
[1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]\n
// @lcpr case=end

 */
