题目十三 二分查找 第一次出现，最后一次出现
#include<stdio.h>
#include<stdlib.h>
long long int n,m;
long long int a[2000000];
int Bsearch(long long int left,long long int right,long long int key)
{
	long long int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==key) return mid;
		else if(a[mid]<key)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return -1;
}
int main()
{
	long long int i,j,x,op,y;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&op,&x);
		y=Bsearch(0,n-1,x);
		if(y==-1) printf("Not Found\n");
		else
		{
			if(op==1)
			{
				while(a[y/2]==a[y]&&y>=3) y=y/2;
				while(a[y-1]==a[y]&&y-1>=0) y=y-1;
			}
			else if(op==2)
			{
				while(a[y*2]==a[y]&&y*2<n) y=y*2;
				while(a[y+1]==a[y]&&y+1<n) y=y+1;
			}
			printf("%lld\n",y+1);
		}
	}
	return 0;
}
