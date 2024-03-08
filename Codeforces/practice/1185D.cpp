#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (register int i = 0; i < n; i++) {
    int x = 0;
    cin >> x;
    a[i] = x;
  }
  if (n <= 3) {
    cout << 1 << endl;
    return;
  }
  sort(a.begin(), a.end());
  int diff1 = a[1] - a[0];
  int diff2 = a[2] - a[1];
  int diff3 = a[3] - a[2];
  int diff = 0;
  if (diff1 == diff2 && diff2 == diff3) {
    diff = diff1;
  }
  int idx = -1;
  for (register int i = 3; i < n; i++) {
    if (a[i] - a[i - 1] != diff1) {
      if (idx == -1) {
        idx = i;
      } else {
        cout << 0 << endl;
        return;
      }
    }
  }
}

int main() {
  solve();
  return 0;
}