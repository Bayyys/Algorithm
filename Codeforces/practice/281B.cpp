#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  // input
  int x, y, n;
  cin >> x >> y >> n;
  // | x/y - a/b | => bx - ay
  // -----

  int ans_a, ans_b;
  // smallest denominator
  ll min_denominator = INT32_MAX;
  // smallest molecule
  ll min_numerator = 1;

  for (int b = 1; b <= n; b++) {        // 遍历 1-n 为 b, 同时计算 a
    int temp_a = int(1ll * b * x / y);  // a = bx/y (向下取整)
    for (int a = temp_a; a <= temp_a + 1; a++) {
      ll temp_de = abs(1ll * b * x - 1ll * a * y);  // 通分分子
      ll temp_nu = 1ll * b * y;                     // 通分分母
      // temp_de / temp_nu < min_denominator / min_numerator
      if (1ll * temp_de * min_numerator < 1ll * min_denominator * temp_nu) {
        min_denominator = temp_de;
        min_numerator = temp_nu;
        ans_a = a;
        ans_b = b;
      }
    }
  }

  // -----
  // output
  cout << ans_a << "/" << ans_b << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}