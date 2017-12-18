#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int bfs(vector<vector<char> > &a, int n, int m) {
  queue<pair<int, int> > cur;
  vector<vector<bool> > color(n, vector<bool>(m, false));
  vector<vector<int> > dist(n, vector<int>(m, -1));

  color[0][0] = true;
  cur.push(make_pair(0, 0));
  dist[0][0] = 0;
  while (!cur.empty()) {
    pair<int, int> x = cur.back();
    int curx = x.first, cury = x.second;
    cur.pop();
    for (int i1 = -1; i1 <= 1; ++i1) {
      for (int j1 = -1; j1 <= 1; ++j1) {
        if (i1 != 0 && j1 != 0)
          continue;
        int nx = curx + i1;
        int ny = cury + j1;
        if (nx < 0 || ny < 0 || nx == n || ny == n || a[nx][ny] == '#' ||
            color[nx][ny])
          continue;
        color[nx][ny] = true;
        dist[nx][ny] = dist[curx][cury] + 1;

        cur.push(make_pair(nx, ny));
      }
    }
  }

  return dist[n - 1][m - 1];
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > kart(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> kart[i][j];
    }
  }
  if (kart[0][0] == '#') {
    cout << -1 << endl;
    return 0;
  }
  cout << bfs(kart, n, m);
  return 0;
}
