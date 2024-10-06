#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int h,  // 树的高度 [1, 50]
      q;  // 问题数量 [0, 1e5]
  cin >> h >> q;
  map<ll, int> mp;
  mp[1ll << h] = 0, mp[1ll << h - 1] = 0;  // 初始化: 叶子结点的左右边界
  for (auto _ : vector<int>(q)) {
    int i,           // 层数 [1, h]
        ans;         // 是否在范围内 [0, 1]
    long long l, r;  // 区间 [2^(i-1), 2^i-1]
    cin >> i >> l >> r >> ans;
    r++;
    l <<= h - i;
    r <<= h - i;
    if (ans)
      mp[l]++, mp[r]--;
    else
      mp[1ll << h - 1]++, mp[l]--, mp[r]++, mp[1ll << h]--;
  }
  int cur = 0;
  ll start = 0, cnt = 0, last = 1ll << h - 1;
  for (auto &[k, v] : mp) {
    if (cur == q) {
      cnt += k - last;
      start = last;
    }
    cur += v;
    last = k;
  }
  if (cnt == 0)
    cout << "Game cheated!" << endl;
  else if (cnt == 1)
    cout << start << endl;
  else
    cout << "Data not sufficient!" << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}