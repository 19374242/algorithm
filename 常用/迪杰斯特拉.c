�Ͻ�˹�����㷨
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
priority_queue<P,vector<P>,greater<P> >q;//Ϊ��ʽģ�� 
//����С��Ԫ�ط��ڶ��׵����ȶ���,����һ��д�������ȶ�������pair���е�һ��Ԫ�أ�greater��Ĭ���෴����С���ѣ����� 
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
    q.push(make_pair(0,from));//pair�����Ҫ��make_pair 
    while(!q.empty())
    //��Ϊ�ռ�Ϊ���е㶼����
    {
        int x=q.top().second;
        q.pop();
        //��¼�Ѷ������䵯��
        if(!vis[x])
        //û�б���������Ҫ����
        {
            vis[x]=1;
            for(int i=head[x];i;i=edge[i].before)
            //�����Ѷ���������
            {
                int v=edge[i].to;
                dis[v]=min(dis[v],dis[x]+edge[i].value);
                //�ɳڲ���
                q.push(make_pair(dis[v],v));
            }
        }
    }
}