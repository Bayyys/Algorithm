#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

template <class T>
struct fenwick_tree {
 public:
  fenwick_tree() : _n(0) {}
  explicit fenwick_tree(int n) : _n(n), data(n) {}

  void add(int p, T x) {
    p++;
    while (p <= _n) {
      data[p - 1] += x;
      p += p & -p;
    }
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

  int bisect_min_larger(T x) {
    if (x <= 0) return -1;
    int note = -1;
    T tmp = 0;
    for (int pw = 1 << 32 - __builtin_clz(_n); pw > 0; pw >>= 1) {
      if (note + pw < _n && tmp + data[note + pw] < x) {
        note += pw;
        tmp += data[note];
      }
    }
    return note + 1;
  }

 private:
  int _n;
  std::vector<T> data;

  T sum(int r) {
    T s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};

inline void solve() {
  int n;  // 序列数量 [1， 2e5]
  cin >> n;
  vector<int> a(n);  // [1, 1e9]
  for (auto &x : a) cin >> x;

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  stable_sort(idx.begin(), idx.end(),
              [&](int i, int j) { return -a[i] < -a[j]; });
  // for (auto &x : idx) cout << x << " ";

  int m;  // 查询数量 [2, 2e5]
  cin >> m;
  vector<int> pos;
  vector<vector<int>> queries(n);
  for (int i = 0; i < m; ++i) {
    int k,  // 最优序列长度 [1, n]
        p;  // 位置 [1, k]
    cin >> k >> p;
    queries[k - 1].emplace_back(i);
    pos.emplace_back(p);
  }

  vector<int> ans(m);
  fenwick_tree<int> bit(n);
  for (int i = 0; i < n; ++i) {
    bit.add(idx[i], 1);
    for (auto &x : queries[i]) ans[x] = a[bit.bisect_min_larger(pos[x])];
  }

  for (auto &x : ans) cout << x << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}