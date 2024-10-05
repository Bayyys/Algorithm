#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

class UnionFind {
 public:
  vector<int> parent, rank;
  UnionFind(int n) : parent(n), rank(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    rank[x] += rank[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return rank[find(x)]; }
};

inline void solve() {
  int n,  // 袜子数量 [2, 2e5]
      m,  // 天数 [0, 2e5]
      k;  // 可用的颜色数量 [1, 2e5]
  cin >> n >> m >> k;
  vector<int> cols(n);  // 袜子颜色
  for (auto &c : cols) cin >> c;
  UnionFind uf(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    uf.unite(a - 1, b - 1);
  }
  vector<map<int, int>> cnt(n);  // cnt[i][j] 表示第 i 个集合中颜色 j 的数量
  for (int i = 0; i < n; i++) cnt[uf.find(i)][cols[i]]++;
  int ans = n;
  for (int i = 0; i < n; i++) {
    int max_cnt = 0;
    for (auto [_, j] : cnt[i]) max_cnt = max(max_cnt, j);
    ans -= max_cnt;
  }
  cout << ans << endl;
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}