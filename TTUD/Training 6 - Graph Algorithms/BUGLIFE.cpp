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
		bool isBipartite(int s){
			visited[s] = true;
			queue<int> q;
			int colorArr[n+1];
			memset(colorArr, -1, sizeof(colorArr));
			colorArr[s] = 1;
			q.push(s);
			list<int>::iterator i;
			while (!q.empty()){
				s=q.front();
				q.pop();
				for (i=adj[s].begin(); i!=adj[s].end(); ++i){
					int v = *i;
					visited[v] = true;
					if (colorArr[v] == -1){
						colorArr[v] = 1 - colorArr[s];
						q.push(v);
					} else if (colorArr[v] == colorArr[s]){
						return false;
					}
				}
			}
			return true;
		}
}; 
 
int main(){
	int t;
	scanf("%d", &t);
	for(int k=1; k<=t; k++){
		int N, M;
		scanf("%d %d", &N, &M);
		Graph g(N);
		visited = new bool[g.n+1];
		memset(visited, false, sizeof(visited));
		int u, v;
		for(int i=1; i<=M; i++){
			scanf("%d %d", &u, &v);
			g.addEdge(u, v); 
		}
		bool c = true;
		for (int i=1; i<=N; i++){
			if(!visited[i]){
				if(!g.isBipartite(i)){
					c = false;
					break;
				}
			}
		}
		printf("Scenario #%d:\n", k);
		if(c){
			printf("No suspicious bugs found!\n");
		} else {
			printf("Suspicious bugs found!\n");
		}
	}
	
}
