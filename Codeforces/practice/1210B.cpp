#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;
  cin >> n;  // 数量 [1, 7000]
  ll a[n];
  int b[n];
  map<ll, int> all;
  for (int i = 0; i < n; i++) {
    cin >> a[i];  // a[i] [0, 2e60)
    all[a[i]]++;
  }
  for (int i = 0; i < n; i++) cin >> b[i];  // b[i] [1, 1e9]

  ll ans = 0;
  vector<int> used(n, 0);
  for (auto &[k, v] : all) {
    if (v > 1) {
      for (int i = 0; i < n; i++) {
        if (used[i] == 0 && (a[i] & k) == a[i]) {
          used[i] = 1;
          ans += b[i];
        }
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}