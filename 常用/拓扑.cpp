��������P.S. ������������Ψһ��������������Ŵ�ĵ㣬��������С�ĵ㡣
���ȶ��к���ʽ��ǰ��
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int> q;
struct node//��ʽ��ǰ�� 
{
	int from;
	int to;
	int before;//ͬ�����һ���߱�� ��-1Ϊ�� 
	int value;
}edge[500000];
int head[500000];//��iΪ�����һ��
int in[500000];//��� 
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
		for(j=head[x];j!=-1;j=edge[j].before)//��ʽ��ǰ�Ƿ�����·����Ҫ��ס
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