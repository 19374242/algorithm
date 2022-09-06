ÌâÄ¿ 1 ÄæĞò¶Ô
#include<stdio.h>
#include<string.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
long long int sum=0;
int main()
{
	int a[200000];
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("%lld",sum);
	return 0;
}
void merge(int a[],int left,int mid,int right)
{
	int b[200000];
	int i=left,j=mid+1,k=0,x=0;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			k++;i++;
		}
		else
		{
			x=x+mid-i+1;
			b[k]=a[j];
			k++;j++;
		}
	}
	if(j==right+1)
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;k++;
		}
	}
	if(i==mid+1)
	{
		while(j<=right)
		{
			b[k]=a[j];
			j++;k++;
		}
	}
	for (j=0,i=left;j<k;i++,j++)
	{
		a[i]=b[j];
	}
	sum=sum+x;
}
void mergesort(int a[],int left,int right)
{
	if(left>=right) return ;
	int mid;
	mid=(left+right)/2;
	mergesort(a,left,mid);
	mergesort(a,mid+1,right);
	merge(a,left,mid,right);
}
