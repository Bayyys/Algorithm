#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int ll
typedef long long ll;

int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

inline void solve() {
  int x0, y0, ax, ay, bx, by, xs, ys, t;
  // (xi, yi) = (ax * xi-1 + bx, ay * yi-1 + by)
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  vector<pair<int, int>> collections;
  int n = 0;
  int start = 0;
  int min = LLONG_MAX;
  int ans = 0;
  // 初始化收集点
  while (++n) {
    collections.emplace_back(x0, y0);
    if (x0 > xs && y0 > ys && dist(xs, ys, x0, y0) > t) break;
    x0 = ax * x0 + bx, y0 = ay * y0 + by;
  }
  for (int i = 0; i < n; i++) {
    int temp_ans = 0;
    int temp_t = t;
    auto [x, y] = collections[i];
    if (dist(x, y, xs, ys) > temp_t && x > xs && y > ys) break;
    if (dist(x, y, xs, ys) <= temp_t) {
      temp_ans = 1;
      temp_t -= dist(x, y, xs, ys);
      for (int j = i - 1; j >= 0; j--) {
        auto [x1, y1] = collections[j];
        if (temp_t >= dist(x, y, x1, y1)) {
          temp_ans++;
          temp_t -= dist(x, y, x1, y1);
          x = x1, y = y1;
        } else
          break;
      }
      for (int j = i + 1; j < n; j++) {
        auto [x1, y1] = collections[j];
        if (temp_t >= dist(x, y, x1, y1)) {
          temp_ans++;
          temp_t -= dist(x, y, x1, y1);
          x = x1, y = y1;
        } else
          break;
      }
      if (temp_ans > ans) ans = temp_ans;
    }
  }
  // 递归收集点, 先向左, 再向右
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}