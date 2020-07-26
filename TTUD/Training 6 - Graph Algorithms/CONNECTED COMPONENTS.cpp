#include <bits/stdc++.h>
using namespace std;
bool *visited;
 
class Graph{
	public:
		int n;
		list<int> *adj;
		Graph(int V){
			this->n = V;
			adj = new list<int>[V+1];
		}
		void addEdge(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		void BFS(int s){
			queue<int> q;
			visited[s] = true;
			q.push(s);
			list<int>::iterator i;
			while (!q.empty()){
				s=q.front();
				q.pop();
				for (i=adj[s].begin(); i!=adj[s].end(); ++i){
					int v = *i;
					if (!visited[v]){
						visited[v] = true;
						q.push(v);
					}
				}
			}
		}
};
 
int main(){
	int N, M;
	cin >> N >> M;
	Graph g(N);
	int u, v;
	for(int i=1; i<=M; i++){
		cin >> u >> v;
		g.addEdge(u, v); 
	}
	visited = new bool[g.n + 1];
	for(int i=1; i<=g.n; i++) visited[i]=false;
	int cnt = 0;
	for(int i=1; i<=g.n; i++){
		if(!visited[i]){
			cnt++;
			g.BFS(i);
		}
	}
	cout << cnt << endl;
}
