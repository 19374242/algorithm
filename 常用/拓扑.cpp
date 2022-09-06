拓扑排序P.S. 对于拓扑排序不唯一的情况，先输出序号大的点，再输出序号小的点。
优先队列和链式向前星
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int> q;
struct node//链式向前星 
{
	int from;
	int to;
	int before;//同起点上一条边编号 ，-1为无 
	int value;
}edge[500000];
int head[500000];//以i为起点上一条
int in[500000];//入度 
int n,m;
void tuopu()
{
    int i,j;
    for(i=n;i>=1;i--)
    {
        if(in[i]==0)
        {
        	q.push(i);
        	in[i]=-1;
		}
    }
	while(q.empty()!=1)
	{
		int x=q.top();
		q.pop();
		cout<<x<<' ';
		for(j=head[x];j!=-1;j=edge[j].before)//链式向前星访问套路，需要记住
		{
		    in[edge[j].to]--;
		    if(in[edge[j].to]==0)
		    {
		        in[edge[j].to]=-1;
		        q.push(edge[j].to);
		    }
		}
	}
}
int main()
{
	int i,j,x,y;
	cin>>n>>m;
	for(i=0;i<=n;i++) head[i]=-1;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		edge[i].from=x;edge[i].to=y;edge[i].before=head[x];head[x]=i;in[y]++;
	}
	tuopu();
	cout<<"\n";
	return 0;
}