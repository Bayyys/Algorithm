#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  ll n, k;  // [1, 1e18]
  cin >> n >> k;
  for (ll i = 1; i < k; i++) {
    if (n % i != (i - 1)) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}