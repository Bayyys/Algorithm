#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
#define int ll

inline void solve() {
  int n;  // 树的顶点数 [2, 1e5]
  cin >> n;
  vector<int> p, s;
  p.emplace_back(-1);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    p.emplace_back(x - 1);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.emplace_back(x);
  }
  for (int i = 1; i < n; i++) {
    if (s[i] >= 0 && (s[i] < s[p[i]] || s[p[i]] == -1)) s[p[i]] = s[i];
  }
  int ans = 0;
  for (int i = n - 1; i > 0; i--) {
    if (s[i] != -1) {
      if (s[i] < s[p[i]]) {
        cout << -1 << endl;
        return;
      }
      ans += s[i] - s[p[i]];
    }
  }
  cout << ans + s[0] << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}