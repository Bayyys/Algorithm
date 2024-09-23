#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

class Solve {
 private:
  int n;
  string s;
  vector<pair<int, int> > dp;  // dp[i] = {from, dist} => 从 from 走到 i 的距离

 public:
  Solve(int n, string s1, string s2) : n(n), s(s1 + s2) {
    dp.resize(2 * n);
    vector<bool> vis(2 * n, false);
    for (int i = 0; i < 2 * n; i++) {
      if (is_valid(i))
        dp[i] = make_pair(i, 0);  // 有效点, 自身距离为 0
      else {
        dp[i] = make_pair(-1, -1);  // 无效点, 无法到达
        vis[i] = true;
      }
    }
    for (int from = 0; from < 2 * n; from++) {
      if (!vis[from]) {
        dp[from] = make_pair(from, 0);
        vis[from] = true;
        dfs(from, from, 0, vis);
      }
    }
  }

  void dfs(int pos, int from, int dist, vector<bool> &vis) {
    if (pos != from) {
      // cout << "pos: " << pos + 1 << " from: " << from + 1  // pos -> from
      //      << " dist: " << dist << endl;                   // dist
      vis[pos] = true;
      dp[pos] = make_pair(from, dist);
    }
    vector<int> to_vec = get_to(pos);
    for (auto to : to_vec) {
      if (!vis[to]) {
        dfs(to, from, dist + 1, vis);
      }
    }
  }

  vector<int> get_to(int pos) {
    vector<int> to_vec;
    if (pos - 1 >= 0 && pos % n != 0) to_vec.push_back(pos - 1);
    if (pos + 1 < 2 * n && (pos + 1) % n != 0) to_vec.push_back(pos + 1);
    if (pos - n >= 0) to_vec.push_back(pos - n);
    if (pos + n < 2 * n) to_vec.push_back(pos + n);
    return to_vec;
  }

  bool is_valid(int pos) { return s[pos] == '.'; }

  int solve(int in, int out) {
    int ans = -1;
    if (dp[in - 1].first == -1 || dp[out - 1].first == -1) {
      ans = -1;
    }
    if (dp[in - 1].first == dp[out - 1].first) {
      // cout << "in: " << in << " out: " << out << " from: " << dp[in -
      // 1].first
      //      << " dist-in: " << dp[in - 1].second
      //      << " dist-out: " << dp[out - 1].second << endl;
      ans = abs(dp[in - 1].second - dp[out - 1].second);
    }
    return ans;
  }
};

signed main() {
  fio;
  // input
  int n,  // 2*n 迷宫 [2, 2e5]
      m;  // m 个请求 [1, 2e5]
  cin >> n >> m;
  string s1, s2;
  cin >> s1 >> s2;
  Solve solve(n, s1, s2);
  while (m--) {
    int in, out;
    cin >> in >> out;
    int ans = solve.solve(in, out);
    cout << ans << endl;
  }
}