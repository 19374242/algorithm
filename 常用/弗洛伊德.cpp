floyd�㷨�������и�Ȩ�ߣ������и�Ȩ��·������ǵ��֮����Сֵ��
#include<stdio.h>
long long int n,m,p;
long long int a[510][510];
int main()
{
	long long int i,j,x,y,z,k;
	for(i=0;i<510;i++)
	{
		for(j=0;j<510;j++)
		{
			if(i==j) a[i][j]=0;
			else a[i][j]=1e9;
		}
	}
	scanf("%lld%lld%lld",&n,&m,&p);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(a[x][y]>z) a[x][y]=z;//�������ظ��� 
	}
	for(k=1;k<=n;k++)//���Ĵ���
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	for(i=0;i<p;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(a[x][y]==1e9) printf("-1\n");
		else printf("%lld\n",a[x][y]);
	}
}