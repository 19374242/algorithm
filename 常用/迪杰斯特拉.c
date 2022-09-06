迪杰斯特拉算法
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int to,value,before;
}edge[300000];
int head[300000],cnt=0,n,m,vis[300000],dis[300000];
#define P pair<long long int,int> 
priority_queue<P,vector<P>,greater<P> >q;//为格式模板 
//把最小的元素放在队首的优先队列,这是一个写法，优先队列是以pair组中第一个元素（greater与默认相反，是小顶堆）排序 
void dijkstra(int);
void add(int u,int v,int w)
{
	cnt++;
    edge[cnt].to=v;
    edge[cnt].value=w;
    edge[cnt].before=head[u];
    head[u]=cnt; 
}
int main()
{
    cin>>n>>m;
    int i,x,y,z,from,to;
    cin>>from>>to;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra(from);
    cout<<dis[to]<<endl;
    return 0;
}
void dijkstra(int from)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
    }
    dis[from]=0;
    q.push(make_pair(0,from));//pair入队需要用make_pair 
    while(!q.empty())
    //堆为空即为所有点都更新
    {
        int x=q.top().second;
        q.pop();
        //记录堆顶并将其弹出
        if(!vis[x])
        //没有遍历过才需要遍历
        {
            vis[x]=1;
            for(int i=head[x];i;i=edge[i].before)
            //搜索堆顶所有连边
            {
                int v=edge[i].to;
                dis[v]=min(dis[v],dis[x]+edge[i].value);
                //松弛操作
                q.push(make_pair(dis[v],v));
            }
        }
    }
}