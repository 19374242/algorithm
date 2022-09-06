LCA最近公共祖先（链式向前星）
该题找到祖先后算出两节点之间最短距离
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int to;
	int before;
}edge[200000];
int lg[200000];
int head[200000],depth[200000],fa[200000][22];//fa[u][i]表示u的第2的i次方个祖先（fa[u][0]就是u的父亲）
int n,cnt=0;
void dfs(int now,int father)
{ 
	int i;
	fa[now][0]=father;depth[now]=depth[father]+1;
	for(i=1;i<=lg[depth[now]];i++)
    	fa[now][i]=fa[fa[now][i-1]][i-1]; //这个转移可以说是算法的核心之一
	                                //意思是now的2^i祖先等于now的2^(i-1)祖先的2^(i-1)祖先
                                    	//2^i = 2^(i-1) + 2^(i-1)
	for(i=head[now];i;i=edge[i].before)
    	if(edge[i].to!=father) dfs(edge[i].to,now);
} 
int LCA(int x,int y) 
{
	int k;
	if(depth[x]<depth[y])
	{
		int tmp=x;x=y;y=tmp;
	}
	while(depth[x]>depth[y])
		x=fa[x][lg[depth[x]-depth[y]]-1]; //先跳到同一深度
	if(x==y) //如果x是y的祖先，那他们的LCA肯定就是x了
	{
		return x;
	}
	for(k=lg[depth[x]]-1;k>=0;k--) //不断向上跳（lg就是之前说的常数优化）
	{
		if(fa[x][k]!=fa[y][k])  //因为我们要跳到它们LCA的下面一层，所以它们肯定不相等，如果不相等就跳过去。
		{
			x=fa[x][k];
			y=fa[y][k];
		}
    }
	return fa[x][0];  //返回父节点
}
int main()
{
	int fu,sum;
	int a,b,i,j,q;
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		cnt++;edge[cnt].to=b;edge[cnt].before=head[a];head[a]=cnt;
		cnt++;edge[cnt].to=a;edge[cnt].before=head[b];head[b]=cnt;
	}
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(1,0);
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		fu=LCA(a,b);
		sum=depth[a]+depth[b]-2*depth[fu];
		if(sum%2==0) cout<<"YE5"<<endl;
		else cout<<"N0"<<endl;
	}
	return 0;
} 