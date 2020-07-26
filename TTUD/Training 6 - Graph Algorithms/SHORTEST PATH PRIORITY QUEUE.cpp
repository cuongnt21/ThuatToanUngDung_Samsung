#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 
typedef pair<int, int> iPair;
 
class Graph{
	// So canh cua do thi
	int V;
	vector <iPair> *adj;
	
	public:
		Graph(int V);
		~Graph() {delete [] adj; }
		void addEdge(int u, int v, int weight);
		// Thuat toan Dijkstra thong thuong
		int Dijkstra(int s, int t);
};
 
Graph::Graph(int V){
	this->V = V;
	adj = new vector<iPair> [V+1];
}
 
void Graph::addEdge(int u, int v, int weight){
	adj[u].push_back(make_pair(v,weight));
}
 
int Graph::Dijkstra(int s, int t){
	// Khoang cach
	vector <int> d(V+1, INF);
	// Tap xac dinh de xet
	vector <bool> k(V+1, 0);
	// Khoi toa khoang cach nut goc
	d[s] = 0;
	priority_queue<iPair, vector<iPair>, greater<iPair> > Q;
	Q.push(make_pair(d[s],s));
	while(!Q.empty()){
		// u la node co distance thap nhat
		int u = Q.top().second;
		if(u==t){
			return d[u];
		}
		Q.pop();
		
		if (!k[u]){
			k[u] = true;
			for(int i= 0; i < adj[u].size(); i++){
				int v = adj[u][i].first;
				int weight = adj[u][i].second;
				if (d[v] > d[u]+ weight){
					d[v] = d[u]+ weight;
					Q.push(make_pair(d[v],v));
				}
			}
		}
	}
	return -1;
}
 
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	Graph g(N);
	int u, v, w;
	for (int i=1; i<=M; i++){
		scanf("%d %d %d", &u, &v, &w);
		g.addEdge(u, v, w);
	}
	int s, t;
	scanf("%d %d", &s, &t);
	printf("%d", g.Dijkstra(s, t));
}
