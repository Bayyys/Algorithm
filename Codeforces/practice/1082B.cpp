#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;     // 个数 [2, 2e5]
  string s;  // G/S 字符串
  cin >> n >> s;
  int l = 0, r = 0;  // 左右指针
  int ans = 0;       // 最长的 G 字符串长度
  int cnt = 0;       // 子串 S 的个数
  int cnt_g = 0;
  while (l < n) {
    if (s[l] == 'G') cnt_g++;  // 计算 G 的个数
    while (r < n &&
           cnt + (s[r] == 'S') <= 1) {  // 右指针右移, 保证 S 的个数不超过 1
      cnt += (s[r] == 'S');
      r++;
    }
    ans = max(ans, r - l);
    cnt -= (s[l] == 'S');
    l++;
  }
  cout << min(ans, cnt_g) << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}