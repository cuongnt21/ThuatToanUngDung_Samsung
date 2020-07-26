#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> iPair;
 
struct DisjointSets{
	int *parent, *num;
	int n;
	DisjointSets(int n){
		this->n = n;
		parent = new int[n+1];
		num = new int[n+1];
		for(int i=0; i<=n; i++){
			num[i] = 1;
			parent[i] = i;
		}
	}
	// Tim phan tu goc
	int Find(int u){
		while(u != parent[u]) u=parent[u];
		return u;
	}
	// Phoi hai tap 
	void Union(int x, int y){
		int u=Find(x), v=Find(y);
		if(num[u] > num[v]){
			parent[v] = u; num[u] += num[v];
		} else{
			parent[u] = v; num[v] += num[u];
		}
	}
};
 
class Graph{
	public:
		int V, E;
		vector< pair<int, iPair> > edges;
		Graph(int V, int E){
			this->V = V;
			this->E = E;
		}
		void addEdge(int u, int v, int weight){
			edges.push_back({weight, {u, v}});
		}
		long long kruskal(){
			long long mst_wt = 0;
			sort(edges.begin(), edges.end());
			DisjointSets ds(V);
			vector< pair<int, iPair> >::iterator it;
			for(it=edges.begin(); it !=edges.end(); it++){
				int u=it->second.first;
				int v=it->second.second;
				
				int set_u = ds.Find(u);
				int set_v = ds.Find(v);
				
				if(set_u != set_v){
					mst_wt += it->first;
					ds.Union(set_u, set_v);
				}
			}
			return mst_wt;
		}		
};
int main(){
	int V, E;
	cin >> V >> E;
	Graph g(V,E);
	int u, v, w;
	for (int i=1; i<=E; i++){
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	cout << g.kruskal() << endl;
}
