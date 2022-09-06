矩阵连乘最多次/最少次
#include<stdio.h>
#include<string.h>
// 如果i=j，m[i,j]=0
// 如果i<j，m[i,j]=min{m[i,k]+m[k+1,j]+p(i-1)p(k)p(j)}  i<=k<j
long long int line[2000],row[2000];
long long int dp_min[2000][2000],dp_max[2000][2000];
int main()
{
	long long int n,i,x,j,k,min=9e18,max=-1;
	scanf("%lld",&n);
	for(i=0;i<=n;i++)//读取矩阵n个 
	{
		scanf("%lld",&x);
		if(i==0) line[i]=x;
		else if(i==n) row[i-1]=x;
		else row[i-1]=line[i]=x;
	}
	for(x=1;x<n;x++)//动态规划 
	{
		for(i=0;i<n-x;i++)
		{
			j=x+i;
			for(k=i;k<j;k++)
			{
				if(dp_min[i][k]+dp_min[k+1][j]+line[i]*row[j]*row[k]<min)
				{
					min=dp_min[i][k]+dp_min[k+1][j]+line[i]*row[j]*row[k];
				}
				if(dp_max[i][k]+dp_max[k+1][j]+line[i]*row[j]*row[k]>max)
				{
					max=dp_max[i][k]+dp_max[k+1][j]+line[i]*row[j]*row[k];
				}
			}
			dp_min[i][j]=min;
			dp_max[i][j]=max;
			min=9e18;
			max=-1;
		}
	}
	printf("%lld\n",dp_min[0][n-1]);
	printf("%lld\n",dp_max[0][n-1]);
	return 0;
}