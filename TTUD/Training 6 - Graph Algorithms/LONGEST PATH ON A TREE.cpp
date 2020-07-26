#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
bool *visited;
int *dis;
 
class Graph{
	public:
		int V;
		list<iPair> *adj;
		Graph(int V){
			this->V = V;
			adj = new list<iPair>[V+1];
		}
		void addEdge(int u, int v, int weight){
			adj[u].push_back(make_pair(v, weight));
			adj[v].push_back(make_pair(u, weight));
		}
		void DFS(int s){
			visited[s] = true;
			list<iPair>::iterator it;
			for (it=adj[s].begin(); it!=adj[s].end(); ++it){
				int v = it->first;
				if (!visited[v]){
					visited[v] = true;
					dis[v] = dis[s] + it->second;
					DFS(v);
				}
			}
		}	
};
 
int main(){
	int N;
	cin >> N;
	Graph g(N);
	int u, v, w;
	for (int i=1; i<=N-1; i++){
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	dis = new int[g.V+1];
	visited = new bool[g.V + 1];
	
	for(int i=1; i<=g.V; i++) visited[i]=false;
	g.DFS(1);
	int *a = max_element(dis+1, dis+1+g.V);
	
	for(int i=1; i<=g.V; i++){
		visited[i]=false;
		dis[i] = 0;
	} 
	g.DFS(a -dis);
	int *b = max_element(dis+1, dis+1+g.V);
	cout << dis[b - dis] << endl;
}
