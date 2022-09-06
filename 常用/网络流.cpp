#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int MAXN = 100000 + 50;
const int INF = 1e8;
int head[MAXN], dist[MAXN], vis[MAXN];
int cur[MAXN];
int n, m, q;
int top = 0;
struct Edge {
int to, cap, flow, next;
}edge[MAXN * 20];
void init() {
	top = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
}
void addedge(int a, int b, int c) {
	Edge E1 = {b, c, 0, head[a]};
	edge[top] = E1;
	head[a] = top++;
	Edge E2 = {a, 0, 0, head[b]};
	edge[top] = E2;
	head[b] = top++;
}
bool BFS(int st, int ed) {
	memset(dist, -1, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	queue<int> que;
	que.push(st);
	vis[st] = 1;
	dist[st] = 0;
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		for(int i = head[u]; i != -1; i = edge[i].next) {
			Edge E = edge[i];
			if(!vis[E.to] && E.cap > E.flow) {
				21 / 58
				dist[E.to] = dist[u] + 1;
				vis[E.to] = 1;
				if(E.to == ed) return true;
				que.push(E.to);
			}
		}
	}
	return false;
}
int DFS(int x, int a, int ed) {
	if(x == ed || a == 0) return a;
	int flow = 0, f;
	for(int& i = cur[x]; i != -1; i = edge[i].next) {
		Edge& E = edge[i];
		if(dist[E.to] == dist[x] + 1 && (f = DFS(E.to, min(a, E.cap - E.flow), ed)) > 0) {
			E.flow += f;
			edge[i^1].flow -= f;
			flow += f;
			a -= f;
			if(a == 0) break;
		}
	}
	return flow;
}
int Maxflow(int st, int ed) {
	int flow = 0;
	while(BFS(st, ed)) {
		memcpy(cur, head, sizeof(head));
		flow += DFS(st, INF, ed);
	}
	return flow;
}
int main(){
	init();
	int i,j;
	int n,m,a,b,c;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i){
		scanf("%d%d%d", &a, &b, &c);
		addedge(a,b,c);
		addedge(b,a,c);
	}
	int ans = Maxflow(1, n);
	printf("%d\n", ans);
	return 0;
}
