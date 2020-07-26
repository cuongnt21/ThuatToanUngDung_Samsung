#include <bits/stdc++.h>
using namespace std;
int *root;
 
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
			bool visited[this->n + 1];
			for(int i=1; i<=this->n; i++) visited[i]=false;
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
						root[v] = s;
						q.push(v);
					}
				}
			}
		}
};
 
int main(){
	int N;
	cin >> N;
	Graph g(N);
	int u, v;
	for(int i=1; i<=N-1; i++){
		cin >> u >> v;
		g.addEdge(u, v); 
	}
	root =new int[g.n+1];
	g.BFS(1);
	for (int i=2; i<=N;i++){
		cout << root[i] << " ";
	}
}
