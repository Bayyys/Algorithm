#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int odd = 0, even = 0;
  int flag = 1;
  for (auto &x : a) {
    cin >> x;
    if (flag)
      odd = max(odd, x);
    else
      even = max(even, x);
    flag ^= 1;
  }
  cout << max(odd + n / 2 + (n % 2 == 0 ? 0 : 1), even + n / 2) << '\n';
}

signed main() {
  fio;
  int t = 1;
  cin >> t;
  while (t--) solve();
}