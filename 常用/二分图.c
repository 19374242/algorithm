����ͼ������㰲ȫ��
//�������ͼ�㷨�����⣺n�����n����ȫ�ݣ�����һ�����꣬����������ƶ�����d
//�������ж����˶㲻����ȫ�� 
#include<iostream>
#include<cmath>
using namespace std;
int map[300][300],visit[300];
int n,d;
int man[300][2];//�������� 
int house[300];//��¼���������û����ס��ȥ�� 
bool dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(map[x][i]==1&&visit[i]==0)//�����ұ���û���ҹ� 
		{
			visit[i]=1;
			if(house[i]==0||dfs(house[i]))//û��ס��ȥ���߿��Ի�һ�������� 
			{
				house[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int i,j;
	cin>>n>>d;//nָ��ȫ���������� 
	for(i=1;i<=n;i++) cin>>man[i][0]>>man[i][1];
	for(i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		for(j=1;j<=n;j++)
		{
			if(d*d>=(man[j][0]-x)*(man[j][0]-x)+(man[j][1]-y)*(man[j][1]-y)) map[i][j]=1;//�ܲ��ܽ��� 
		}
	}
	int num=0;
	for(i=1;i<=n;i++) 
	{
		for(j=1;j<=n;j++) visit[j]=0;
		if(dfs(i)) num++; 
	}  
	cout<<num<<endl;
	return 0;
} 