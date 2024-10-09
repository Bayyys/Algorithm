#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int mod = 1e9 + 7;
  int x;     // [1, 1e6]
  string s;  // |s|: [1, 500]
  cin >> x >> s;
  int k = s.size(), len = min(k, x);
  vector<int> a(x);
  for (int i = 0; i < len; i++) a[i] = s[i] - '0';
  ll ans = k;
  for (int i = 0; i < x; i++) {
    if (a[i] == 0) break;
    ans += (ans - i - 1) * (a[i] - 1) % mod;
    if (ans >= mod)
      ans -= mod;
    else if (ans < 0)
      ans += mod;
    int j = i + 1, end = len, c = 1;
    while (c < a[i] && len < x) {
      a[len] = a[j];
      len++, j++;
      if (j == end) j = i + 1, c++;
    }
  }
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  cin >> t;
  while (t--) solve();
}