#include <bits/stdc++.h>
using namespace std;

int min_vector(vector<int> &v) {
  int min = INT_MAX;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < min) min = v[i];
  }
  return min;
}

inline void solve() {
  int r, c;  // 行/列 [1, 100]
  cin >> r >> c;
  vector<vector<int>> m(r, vector<int>(c, 0));
  vector<int> row(r), col(c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int x;
      cin >> x;
      m[i][j] = x;
      row[i] += x;
      col[j] += x;
    }
  }
  vector<int> flip_r(r, 0), flip_c(c, 0);
  auto check = [&]() -> bool {
    return min_vector(row) < 0 || min_vector(col) < 0;
  };
  while (check()) {
    for (int i = 0; i < r; ++i) {
      if (row[i] < 0) {
        row[i] = -row[i];
        flip_r[i] ^= 1;
        for (int j = 0; j < c; ++j) {
          col[j] -= 2 * m[i][j];
          m[i][j] = -m[i][j];
        }
      }
    }
    for (int j = 0; j < c; ++j) {
      if (col[j] < 0) {
        col[j] = -col[j];
        flip_c[j] ^= 1;
        for (int i = 0; i < r; ++i) {
          row[i] -= 2 * m[i][j];
          m[i][j] = -m[i][j];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < r; i++) ans += flip_r[i];
  cout << ans << " ";
  for (int i = 0; i < r; i++) {
    if (flip_r[i] != 0) cout << i + 1 << " ";
  }
  ans = 0;
  for (int i = 0; i < c; i++) ans += flip_c[i];
  cout << ans << " ";
  for (int i = 0; i < c; i++) {
    if (flip_c[i]) cout << i + 1 << " ";
  }
}

signed main() {
  int t = 1;
  while (t--) solve();
}