#include <bits/stdc++.h>
using namespace std;
 
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
	int N, M;
	cin >> N >> M;
	Graph g(N);
	int u, v;
	for(int i=1; i<=M; i++){
		cin >> u >> v;
		g.addEdge(u, v); 
	}
	if(g.isBipartite(1)){
		cout << "1" << endl;
	} else {
		cout << "0" << endl;
	}
}
