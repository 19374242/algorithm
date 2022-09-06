
���������
//������Dinic�㷨
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct node//��ʽ��ǰ�� 
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
long long int dfs(int pos,long long int low)//��ǰλ�ú���С������dfs����Ѱ������· 
{
    long long int out=0;
    if(pos==t)//������
    {
        return low;//������С����������Ϊ0ʱ˵��û������·�ˣ� 
    }
    for(int i=head[pos];i!=0&&low!=0;i=edge[i].before)
    {
        int v=edge[i].to;
        if(edge[i].value!=0&&dep[v]==dep[pos]+1)//С�Ż�������v�ڵ�ǰλ�õ���һ���вŽ��в����Ƿ�������·
        {
            long long int rlow=dfs(v,min(low,edge[i].value));
            low-=rlow;//�õ�ʹ�õ���������
            edge[i].value-=rlow;//��ȥ�ı���ʣ���֧����� 
            edge[i^1].value+=rlow;//�����+���� 
            out+=rlow;
        }
     }
     if(out==0) dep[pos]=0x3f3f3f3f;
     return out;//���ظõ���ʹ������ 
}
bool bfs()//������·�ϵĵ�ֲ� 
{
	std::queue<int>q; 
    memset(dep,0x3f3f3f3f,sizeof(dep));
    memset(inque,0,sizeof(inque));
    dep[s]=0;//Դ����ȵ�ȻΪ0
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inque[u]=0;//���ڶ�������
        for(int i=head[u];i!=0;i=edge[i].before)
        {
            int v=edge[i].to;//ͨ��ĵ� 
            if(edge[i].value!=0&&dep[v]>dep[u]+1)//���������Ϊ0����u��֮ǰ��û�б��ѵ�
            {
                dep[v]=dep[u]+1;
                if(inque[v]==0)//�����v���ڵ�ǰ������ 
                {
                    q.push(v);
                    inque[v]=1; 
                }
            }
        } 
    }
    if (dep[t]!=0x3f3f3f3f)//ֻҪ��㱻�ѵ��ˣ��ͻ�������· 
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
		cnt++;edge[cnt].to=b;edge[cnt].value=c;edge[cnt].before=head[a];head[a]=cnt;//����Ϊż������2��ʼ 
		cnt++;edge[cnt].to=a;edge[cnt].value=0;edge[cnt].before=head[b];head[b]=cnt;//����Ϊ��������3��ʼ����ʼ����Ϊ0 
                //˫�򷴱�����ҲΪc����������Ϊ0
	}
	while(bfs())//�����������·�ͼ���dfs 
        maxflow=maxflow+dfs(s, 1e9);
	cout<<maxflow<<endl;
    return 0;
}