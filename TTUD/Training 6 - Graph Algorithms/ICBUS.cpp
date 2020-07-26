#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5005;
const int INF = 1000000000;
 
int n, k;
int c[N], d[N], dist[N], mark[N];
vector<int> a[N];
vector<pair<int, int> > adj[N];
 
void BFS(int u)
{
  queue<int> q;
  memset(mark, 0, sizeof(mark));
  
  dist[u] = 0; 
  mark[u] = 1; 
  q.push(u);
 
  while(!q.empty()) {
    int x = q.front();
    q.pop();
 
    for(int i = 0; i < a[x].size(); i++) {
      int v = a[x][i];
      if(!mark[v]) {
        mark[v] = 1;
        dist[v] = dist[x] + 1;
        q.push(v);
        if(dist[v] <= d[u]) {
          adj[u].push_back(make_pair(v, c[u]));
        }
      }
    }
  }
}
 
 
void ShortestPath(int u)
{
  
  priority_queue<pair<int, int> > pq;
 
  for(int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  
  dist[u] = 0;
  pq.push(make_pair(-dist[u], u));
 
 
  while(!pq.empty()) {
    
    pair<int, int> t = pq.top();
    pq.pop(); 
 
    int uu = t.second; 
    int ww = -t.first; 
    if(dist[uu] != ww) continue;
 
   
    for(int i = 0; i < adj[uu].size(); i++) {
      int vv = adj[uu][i].first;
      int l = adj[uu][i].second;
 
     
      if(dist[vv] > dist[uu] + l) {
       
        dist[vv] = dist[uu] + l;
        pq.push(make_pair(-dist[vv], vv));
      }
    }
  }
}
 
int main()
{
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> c[i] >> d[i];
  }
  int u, v;
  for(int i = 1; i <= k; i++) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
 
  for(int i = 1; i <= n; i++) {
    BFS(i);
  }
 
   ShortestPath(1);
 
  cout << dist[n];
  return 0;
}
