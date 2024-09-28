#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

void print(vector<vector<int>> &dp) {
  for (auto &row : dp) {
    for (auto &cell : row) {
      cout << cell << ' ';
    }
    cout << '\n';
  }
}

inline void solve() {
  int row, col;  // [3, 1000]
  cin >> row >> col;
  vector<vector<int>> grid(row, vector<int>(col));  // [0, 1e5]
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> dp1(row,
                          vector<int>(col)),  // top -> bottom, left -> right
      dp2(row, vector<int>(col)),             // top -> bottom, right -> left
      dp3(row, vector<int>(col)),             // bottom -> top, left -> right
      dp4(row, vector<int>(col));             // bottom -> top, right -> left
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int t = 0;
      if (i > 0) t = max(t, dp1[i - 1][j]);
      if (j > 0) t = max(t, dp1[i][j - 1]);
      dp1[i][j] = grid[i][j] + t;
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = col - 1; j >= 0; j--) {
      int t = 0;
      if (i > 0) t = max(t, dp2[i - 1][j]);
      if (j < col - 1) t = max(t, dp2[i][j + 1]);
      dp2[i][j] = grid[i][j] + t;
    }
  }
  for (int i = row - 1; i >= 0; i--) {
    for (int j = 0; j < col; j++) {
      int t = 0;
      if (i < row - 1) t = max(t, dp3[i + 1][j]);
      if (j > 0) t = max(t, dp3[i][j - 1]);
      dp3[i][j] = grid[i][j] + t;
    }
  }
  int ans = 0;
  for (int i = row - 1; i > 0; i--) {
    for (int j = col - 1; j > 0; j--) {
      int t = 0;
      if (i < row - 1) t = max(t, dp4[i + 1][j]);
      if (j < col - 1) t = max(t, dp4[i][j + 1]);
      dp4[i][j] = grid[i][j] + t;
    }
  }
  for (int i = row - 2; i > 0; i--) {
    for (int j = col - 2; j > 0; j--) {
      ans = max(ans,
                dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j]);
      ans = max(ans,
                dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1]);
    }
  }
  cout << ans << '\n';
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}