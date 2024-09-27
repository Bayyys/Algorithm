#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

inline void solve() {
  int n;  // 团体数量 [1, 1000]
  cin >> n;
  vector<pair<int, int>> teams;  // 团队人数 [1,1000] + 金额 [1,1000]
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    teams.push_back({a, b});
  }
  int k;  // 餐桌数量 [1, 1000]
  cin >> k;
  vector<int> tables;  // 餐桌容量 [1, 1000]
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    tables.push_back(x);
  }

  // 根据队伍人数排序 (升序)
  vector<int> team_index(n, 0);
  iota(team_index.begin(), team_index.end(), 0);
  sort(team_index.begin(), team_index.end(),
       [&](int i, int j) { return teams[i].first < teams[j].first; });

  // 根据餐桌容量排序 (升序)
  vector<int> table_index(k, 0);
  iota(table_index.begin(), table_index.end(), 0);
  sort(table_index.begin(), table_index.end(),
       [&](int i, int j) { return tables[i] < tables[j]; });

  // 每个队伍应分配对应的餐桌号
  vector<int> ans(n, -1);
  int price = 0, cnt = 0;
  int cur = 0;

  // 金额的最大堆
  priority_queue<pair<int, int>> pq;
  for (auto &table : table_index) {
    while (cur < n && teams[team_index[cur]].first <= tables[table]) {
      pq.push({teams[team_index[cur]].second, team_index[cur]});
      cur++;
    }
    if (!pq.empty()) {
      price += pq.top().first;
      cnt++;
      ans[pq.top().second] = table;
      pq.pop();
    }
  }

  cout << cnt << " " << price << endl;
  for (int i = 0; i < n; i++) {
    if (ans[i] != -1) {
      cout << i + 1 << " " << ans[i] + 1 << endl;
    }
  }
}

signed main() {
  fio;
  int t = 1;
  while (t--) solve();
}