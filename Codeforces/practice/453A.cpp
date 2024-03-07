#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline double power(double a, int b) {
  double ans = 1.0;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

inline void solve() {
  int m;  // m 个面 [1, 1e5]
  int n;  // 投掷 n 次 [1, 1e5]
  cin >> m >> n;
  double ans = 0.0;
  for (register int i = 1; i <= m; i++) {
    ans += i * (power(i / (double)m, n) - power((i - 1) / (double)m, n));
  }
  cout << fixed << setprecision(12) << ans << endl;  // 保留 12 位小数
}

int main() {
  solve();
  return 0;
}