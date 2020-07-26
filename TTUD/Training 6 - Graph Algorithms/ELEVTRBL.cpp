#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
int f, s, t, u, d;
 
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
		}
		int Dijkstra(int s, int t){
			priority_queue< iPair, vector <iPair> , greater<iPair> > Q;
			vector<int> d(n+1, INT_MAX);
			vector <bool> k(n+1,0);
			
			d[s] = 0;
			Q.push(make_pair(d[s], s));
			
			while(!Q.empty()){
				int u = Q.top().second;
				int cost = Q.top().first;
				Q.pop();
				
				if(u==t){
					return cost;
				}
				
				if(!k[u]){
					k[u] = true;
					list<int>::iterator it;
					for(it=adj[u].begin(); it!=adj[u].end(); ++it){
						int v=*it;
						if(d[v] > d[u] + 1){
							d[v] = d[u] + 1;
							Q.push(make_pair(d[v], v));
						}
					}
				}	
			}
			return -1;
		}
};
 
int main(){
	cin >> f >> s >> t >> u >> d;
	Graph g(f);
	for(int i=1; i<=f; i++){
		if(i-d>=1){
			g.addEdge(i, i-d);
		}
		if(i+u<=f){
			g.addEdge(i, i+u);
		}
	}
	int res = g.Dijkstra(s, t);
	if(res == -1){
		cout << "use the stairs" << endl;
	} else {
		cout << res << endl;
	}
}
