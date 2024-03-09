#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n = 0;  // 字符串长度 [1, 100]
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> cnt(26, 0);
  for (int i = 0; i < n; i++) {
    char c = s[i];
    cnt[c - 'a']++;
    c = t[i];
    cnt[c - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] != 0) {
      cout << -1 << endl;
      return;
    }
  }
  int ans = 0;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp = i;
    for (auto c : s) {
      if (tmp < n && t[tmp] == c) {
        tmp++;
      }
    }
    ans = max(ans, tmp - i);
  }
  cout << n - ans << endl;
}

signed main() {
  fio;
  int t = 1;
  cin >> t;
  while (t--) solve();
}