#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;  // [1, 30]
  cin >> n;
  vector<vector<int>> path(n);
  vector<pair<ll, ll>> ans(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    path[u].push_back(v);
    path[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (path[i].size() > 4) {
      cout << "NO" << endl;
      return;
    }
  }
  vector<pair<ll, ll>> edges = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  auto dfs = [&](auto f, int u, int fa, int k, int from) -> void {
    int dir = 0;
    for (auto v : path[u]) {
      if (v == fa) continue;
      if (dir == from) dir++;
      ans[v] = {ans[u].first + edges[dir].first * (1 << k),
                ans[u].second + edges[dir].second * (1 << k)};
      f(f, v, u, k - 1, (dir + 2) % 4);
      dir++;
    }
  };
  ans[0] = {0, 0};
  dfs(dfs, 0, -1, 29, -1);
  cout << "YES" << endl;
  for (auto [x, y] : ans) cout << x << " " << y << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}