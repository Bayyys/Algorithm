#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;       // 操作数 [1, 2e5]
  string ops;  // 操作列表 U, D, L, R
  int x, y;    // 目标坐标 [-1e9, 1e9]
  cin >> n >> ops >> x >> y;

  vector<pair<int, int>> pos;
  pair<int, int> final = {0, 0};
  auto step = [](char c) -> pair<int, int> {
    switch (c) {
      case 'U':
        return make_pair(0, 1);
        break;
      case 'D':
        return make_pair(0, -1);
        break;
      case 'L':
        return make_pair(-1, 0);
        break;
      case 'R':
        return make_pair(1, 0);
        break;
      default:
        return make_pair(0, 0);
    }
  };

  for (char c : ops) {
    pos.push_back(final);
    int dx, dy;
    tie(dx, dy) = step(c);
    final.first += dx, final.second += dy;
  }
  pos.push_back(final);

  // for (auto p : pos) {
  //   cout << p.first << " " << p.second << endl;
  // }

  auto isValid = [&](int l, int r) -> bool {
    return abs(pos[l].first + final.first - pos[r].first - x) +
               abs(pos[l].second + final.second - pos[r].second - y) >
           r - l;
  };

  if (abs(x) + abs(y) > n || (x + y - n) % 2) {
    return cout << -1 << endl, void();
  }
  int l = 0, r = 0;
  int ans = n + 1;
  while (l <= n) {
    while (r < n && isValid(l, r)) r++;
    if (isValid(l, r)) break;
    ans = min(ans, r - l);
    l++;
  }
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}