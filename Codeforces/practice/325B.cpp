#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  ll n;  // 应该比赛的总场数 [1, 1e18]
  cin >> n;
  bool flg = true;
  for (int i = 0; i < 60; i++) {
    ll index = 1ll << i, l = 0, r = min(1ll << 31, n / max(index - 1, 1ll));
    while (l <= r) {
      ll m = (l + r) >> 1;
      if (m * (m - 1) / 2 + m * (index - 1) <= n)
        l = m + 1;
      else
        r = m - 1;
    }
    if (r * (r - 1) / 2 + r * (index - 1) == n && r & 1) {
      cout << r * index << endl;
      flg = false;
    }
  }
  if (flg) cout << -1 << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}