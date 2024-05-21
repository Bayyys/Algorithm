#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  // Data input
  int len;
  string s;
  string t;
  cin >> len;
  cin >> s >> t;
  // Code here
  // 1. 去除相同前缀
  for (int i = 0; i < len; i++) {
    if (s[i] != t[i]) {
      s = s.substr(i);
      t = t.substr(i);
      len -= i;
      break;
    }
  }
  // 2. 去除相同后缀
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] != t[i]) {
      s = s.substr(0, i + 1);
      t = t.substr(0, i + 1);
      len = i + 1;
      break;
    }
  }
  // 3. 检查是否可以通过交换得到
  int ans = 0;
  if (s.substr(1) == t.substr(0, len - 1)) {
    ans += 1;
  }
  if (s.substr(0, len - 1) == t.substr(1)) {
    ans += 1;
  }
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}