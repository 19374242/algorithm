
最大流问题
//网络流Dinic算法
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct node//链式向前星 
{
	int to;int value;int before;
}edge[10020];
int head[10020],dep[10020];
int inque[10020];
int cnt=1;
int n,m,s,t;
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
long long int dfs(int pos,long long int low)//当前位置和最小残量，dfs用于寻找增广路 
{
    long long int out=0;
    if(pos==t)//到达汇点
    {
        return low;//返回最小残量（当它为0时说明没有增广路了） 
    }
    for(int i=head[pos];i!=0&&low!=0;i=edge[i].before)
    {
        int v=edge[i].to;
        if(edge[i].value!=0&&dep[v]==dep[pos]+1)//小优化：仅当v在当前位置的下一层中才进行查找是否有增广路
        {
            long long int rlow=dfs(v,min(low,edge[i].value));
            low-=rlow;//该点使用的流量增加
            edge[i].value-=rlow;//过去的边是剩余可支配的量 
            edge[i^1].value+=rlow;//反向边+流量 
            out+=rlow;
        }
     }
     if(out==0) dep[pos]=0x3f3f3f3f;
     return out;//返回该点已使用流量 
}
bool bfs()//给增广路上的点分层 
{
	std::queue<int>q; 
    memset(dep,0x3f3f3f3f,sizeof(dep));
    memset(inque,0,sizeof(inque));
    dep[s]=0;//源点深度当然为0
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inque[u]=0;//不在队伍中了
        for(int i=head[u];i!=0;i=edge[i].before)
        {
            int v=edge[i].to;//通向的点 
            if(edge[i].value!=0&&dep[v]>dep[u]+1)//如果容量不为0且在u点之前还没有被搜到
            {
                dep[v]=dep[u]+1;
                if(inque[v]==0)//如果点v不在当前队伍中 
                {
                    q.push(v);
                    inque[v]=1; 
                }
            }
        } 
    }
    if (dep[t]!=0x3f3f3f3f)//只要汇点被搜到了，就还有增广路 
        return 1;
    return 0; 
}
int main()
{
	long long int maxflow=0;
	cin>>n>>m>>s>>t;
	int i,a,b,c;
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		cnt++;edge[cnt].to=b;edge[cnt].value=c;edge[cnt].before=head[a];head[a]=cnt;//正边为偶数，从2开始 
		cnt++;edge[cnt].to=a;edge[cnt].value=0;edge[cnt].before=head[b];head[b]=cnt;//反边为奇数，从3开始，初始流量为0 
                //双向反边流量也为c，单向流量为0
	}
	while(bfs())//如果还有增广路就继续dfs 
        maxflow=maxflow+dfs(s, 1e9);
	cout<<maxflow<<endl;
    return 0;
}