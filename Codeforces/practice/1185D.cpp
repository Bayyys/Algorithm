#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long

inline void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x = 0;
    cin >> x;
    a[i] = {x, i};
  }
  if (n <= 3) {
    cout << 1 << endl;
    return;
  }
  sort(a.begin(), a.end(), [](auto &x, auto &y) { return x.first < y.first; });
  vector<pair<int, int>> diff_pair;
  diff_pair.emplace_back(0, 1);
  diff_pair.emplace_back(1, 2);
  diff_pair.emplace_back(0, 2);
  for (auto [f, t] : diff_pair) {
    int diff = a[t].first - a[f].first;
    int cnt = 0;
    int from = a[f].first;
    int tmp = a[0].second + 1;
    for (int i = 0; i < n; i++) {
      if (a[i].first == from) {
        cnt++;
        from += diff;
      } else {
        tmp = a[i].second + 1;
      }
    }
    if (cnt >= n - 1) {
      cout << tmp << endl;
      return;
    }
  }
  cout << -1 << endl;
}

signed main() { solve(); }