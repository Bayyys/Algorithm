#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n,  // 点数 [1, 2e5]
      a,  // y = ax + b |[1, 1e9]|
      b;  // y = ax + b |[1, 1e9]|

  // xi + ui * t = xj + uj * t, yi + vi * t = yj + vj * t
  // (xi - xj) / (uj - ui) = (yi - yj) / (vj - vi)
  // a(ui -uj) = vi - vj
  // a * ui - vi = a * uj - vj
  cin >> n >> a >> b;
  map<ll, int> vis1;            // 记录 a * u - v
  map<pair<ll, ll>, int> vis2;  // 记录 (v, v), 排除相同方向的线
  ll ans = 0;
  while (n--) {
    ll x, u, v;
    cin >> x >> u >> v;
    ans += vis1[a * u - v] - vis2[{u, v}];
    vis1[a * u - v]++, vis2[{u, v}]++;
  }
  cout << 2 * ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}