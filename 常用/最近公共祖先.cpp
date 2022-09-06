LCA����������ȣ���ʽ��ǰ�ǣ�
�����ҵ����Ⱥ�������ڵ�֮����̾���
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
int head[200000],depth[200000],fa[200000][22];//fa[u][i]��ʾu�ĵ�2��i�η������ȣ�fa[u][0]����u�ĸ��ף�
int n,cnt=0;
void dfs(int now,int father)
{ 
	int i;
	fa[now][0]=father;depth[now]=depth[father]+1;
	for(i=1;i<=lg[depth[now]];i++)
    	fa[now][i]=fa[fa[now][i-1]][i-1]; //���ת�ƿ���˵���㷨�ĺ���֮һ
	                                //��˼��now��2^i���ȵ���now��2^(i-1)���ȵ�2^(i-1)����
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
		x=fa[x][lg[depth[x]-depth[y]]-1]; //������ͬһ���
	if(x==y) //���x��y�����ȣ������ǵ�LCA�϶�����x��
	{
		return x;
	}
	for(k=lg[depth[x]]-1;k>=0;k--) //������������lg����֮ǰ˵�ĳ����Ż���
	{
		if(fa[x][k]!=fa[y][k])  //��Ϊ����Ҫ��������LCA������һ�㣬�������ǿ϶�����ȣ��������Ⱦ�����ȥ��
		{
			x=fa[x][k];
			y=fa[y][k];
		}
    }
	return fa[x][0];  //���ظ��ڵ�
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