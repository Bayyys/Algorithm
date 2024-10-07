#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int N,  // 总人数 [1, 1e5]
      S;  // 每个披萨的切片数 [1, 1e5]
  cin >> N >> S;
  vector<pair<int, int>> v1, v2;
  ll cnt1 = 0, cnt2 = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    int s, a, b;
    cin >> s >> a >> b;
    if (a >= b) {
      ans += 1ll * a * s;
      v1.emplace_back(a - b, s);
      cnt1 += s;
    } else {
      ans += 1ll * b * s;
      v2.emplace_back(b - a, s);
      cnt2 += s;
    }
  }
  // 恰好能分完
  if ((cnt1 + S - 1) / S + (cnt2 + S - 1) / S == (cnt1 + cnt2 + S - 1) / S) {
    cout << ans << endl;
    return;
  }
  // 披萨切片数多一片, 进行调整
  sort(v1.begin(), v1.end());  // 从小到大
  sort(v2.begin(), v2.end());  // 从大到小

  int remove1 = cnt1 % S, remove2 = cnt2 % S;  // 可能移动的数量
  ll val1 = 0, val2 = 0;                       // 移动的价值

  for (auto &[diff, cnt] : v1) {
    int remove = min(cnt, remove1);
    remove1 -= remove;
    val1 += 1ll * diff * remove;
    if (remove1 == 0) break;
  }

  for (auto &[diff, cnt] : v2) {
    int remove = min(cnt, remove2);
    remove2 -= remove;
    val2 += 1ll * diff * remove;
    if (remove2 == 0) break;
  }

  cout << ans - min(val1, val2) << endl;
}

signed main() {
  fio;
  solve();
}