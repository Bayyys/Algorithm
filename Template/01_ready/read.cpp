#include <bits/stdc++.h>
using namespace std;

inline int read() {
  int s = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch <= '9' && ch >= '0') {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return s;
}
