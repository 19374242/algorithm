二分图，间谍躲安全屋
//经典二分图算法。题意：n个间谍n个安全屋，都有一个坐标，间谍最多可以移动距离d
//问最少有多少人躲不进安全屋 
#include<iostream>
#include<cmath>
using namespace std;
int map[300][300],visit[300];
int n,d;
int man[300][2];//存间谍坐标 
int house[300];//记录这个房子有没有人住进去了 
bool dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(map[x][i]==1&&visit[i]==0)//有线且本次没被找过 
		{
			visit[i]=1;
			if(house[i]==0||dfs(house[i]))//没人住进去或者可以换一个人连线 
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
	cin>>n>>d;//n指安全屋与间谍数量 
	for(i=1;i<=n;i++) cin>>man[i][0]>>man[i][1];
	for(i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		for(j=1;j<=n;j++)
		{
			if(d*d>=(man[j][0]-x)*(man[j][0]-x)+(man[j][1]-y)*(man[j][1]-y)) map[i][j]=1;//能不能进入 
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