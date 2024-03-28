#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n = 0;
  cin >> n;
  int a[n] = {0};
  int one_len = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) one_len += 1;
  }
  if (one_len) {
    cout << n - one_len << endl;
    return;
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
    int fi = a[i];
    for (int j = i + 1; j < n; j++) {
      fi = __gcd(fi, a[j]);
      if (fi == 1) {
        ans = min(ans, j - i);
        break;
      }
    }
  }
  cout << (ans == n ? -1 : ans + n - 1) << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}