#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double eps = 1e-6;

inline void solve() {
  // Data Load
  int n;  // 点的数量 [2, 60000]
  cin >> n;
  vector<pair<int, int>> p;  // p.first: x, p.second: v
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    p.emplace_back(x, 0);
  }
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    p[i].second = v;
  }
  sort(p.begin(), p.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.first < b.first;
       });
  double l = 0, r = p[n - 1].first;
  double m;
  auto check = [&](double m) -> bool {
    double ll = -1e9, rr = 1e9;
    for (int i = 0; i < n; ++i) {
      ll = max(ll, p[i].first - m * p[i].second); // 找到
      rr = min(rr, p[i].first + m * p[i].second);
    }
    return ll <= rr;
  };
  while (l + eps < r) {
    m = r - (r - l) / 2;
    if (check(m))
      r = m;
    else
      l = m;
  }
  cout << fixed << setprecision(12) << l << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}