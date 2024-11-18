#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

// 反转字符串 （ “+” -> “*”  “*” -> “+” )
string reverse(string s) {
  string res = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      res += '*';
    } else {
      res += '+';
    }
  }
  return res;
}

inline void solve() {
  int k;  // k dimension [0, 9]
  cin >> k;
  if (k == 0) {
    cout << "+" << endl;
    return;
  }
  vector<string> ans;
  ans.push_back("++");
  ans.push_back("+*");
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < pow(2, i); j++) {
      ans.push_back(ans[j]);
    }
    for (int j = 0; j < pow(2, i); j++) {
      ans[j] += ans[j];
    }
    for (int j = pow(2, i); j < pow(2, (i + 1)); j++) {
      ans[j] += reverse(ans[j]);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}