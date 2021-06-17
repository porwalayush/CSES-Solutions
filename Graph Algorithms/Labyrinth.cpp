#include "bits/stdc++.h"
using namespace std;
const int N = 1000;
char mat[N][N];
bool visited[N][N];
int dx[] = { -1, 0, 1, 0}, dy[] = {0, -1, 0, 1}; // U L D R
char steps[] = {'U', 'L', 'D', 'R'};
int path[N][N];
void bfs(int i, int j, int n, int m)
{
  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = true;
  while (!q.empty())
  {
    pair<int, int> tp = q.front();
    q.pop();
    for (int x = 0; x < 4; x++)
    {
      if (tp.first + dx[x] < n && tp.second + dy[x] < m && tp.first + dx[x] >= 0 && tp.second + dy[x] >= 0 && !visited[tp.first + dx[x]][tp.second + dy[x]] && mat[tp.first + dx[x]][tp.second + dy[x]] != '#')
      {
        q.push({tp.first + dx[x], tp.second + dy[x]});
        visited[tp.first + dx[x]][tp.second + dy[x]] = true;
        path[tp.first + dx[x]][tp.second + dy[x]] = x;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }
  pair<int, int> s, t;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == 'A')
      {
        bfs(i, j, n, m);
        s.first = i, s.second = j;
      }
      if (mat[i][j] == 'B')
      {
        t.first = i, t.second = j;
      }
    }
  }
  vector<char> ans;
  if (visited[t.first][t.second])
  {
    cout << "YES" << endl;
    while (t != s)
    {
      int x = path[t.first][t.second];
      ans.push_back(steps[x]);
      t = {t.first - dx[x], t.second - dy[x]};
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans) cout << it;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}