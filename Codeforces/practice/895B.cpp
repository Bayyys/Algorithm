#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;  // 数组 a 的大小 [1, 1e5]
  ll x;   // 给定整数 [1, 1e9]
  int k;  // 给定数量 [0, 1e9]
  cin >> n >> x >> k;
  vector<ll> a(n);  // 数组 a [1, 1e9]
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  auto findRange = [](ll val, ll div, int num) -> pair<ll, ll> {
    if (num == 0) {
      if (val % div == 0) {
        return {-1, -1};
      } else {
        return {val, val / div * div + div};
      }
    } else {
      ll nval = 0;
      if (val % div == 0) {
        nval = val;
      } else {
        nval = val / div * div + div;
      }
      return {nval + (num - 1) * div, nval + num * div};
    }
  };

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    auto [l, r] = findRange(a[i], x, k);
    ll pos = upper_bound(a.begin(), a.end(), r - 1) -
             lower_bound(a.begin(), a.end(), l);
    ans += pos;
    // cout << "l: " << l << " r: " << r << " pos: " << pos << endl;
  }
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}