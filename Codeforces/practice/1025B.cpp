#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

inline void solve() {
  int n = 0;  // 数对个数 [1, 150000]
  cin >> n;
  set<pair<int, int>> b;  // 数对 [2, 2*10^9]
  for (int i = 0; i < n; i++) {
    int x = 0, y = 0;
    cin >> x >> y;
    b.insert({x, y});
  }
  vector<pair<int, int>> a(b.begin(), b.end());
  // 构建可能的因数组
  set<int> divides;
  auto gen_divides = [&](int x) -> void {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        divides.insert(i);
        if (i * i != x) divides.insert(x / i);
      }
    }
    divides.insert(x);
  };
  gen_divides(a[0].first), gen_divides(a[0].second);
  vector<int> div = {divides.begin(), divides.end()};
  sort(div.begin(), div.end(), greater<int>{});
  for (int i = 0; i < div.size(); i++) {
    int flag = 1;
    for (auto &[x, y] : a) {
      if (x % div[i] && y % div[i]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << div[i] << endl;
      return;
    }
  }
  cout << -1 << endl;
}

signed main() {
  int t = 1;
  while (t--) solve();
}