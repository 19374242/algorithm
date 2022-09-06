
一串数组分k段，各段最大值的最大值 最小是多少（二分法，给出答案区间分治）
#include<stdio.h>
int a[200000];
int judge(int mid,int divided_num,int n)
{
	int i,num=1,sum=0;
    for(i=0;i<n;i++)
    {
        sum=a[i]+sum;
        if(sum>mid)                //从左到右将数组元素之和与mid比较，如是大于则再起一段，最后看段的大小
        {
            sum=a[i];
            num++;
        }
    }
    if(num>divided_num)            //若是段大于段数，则必然不和条件
        return 0;
    else
        return 1;

}
int merge(int left,int right,int divided_num,int n)//divided_num为分段个数，n为数组个数 
{
	if(left>=right) return left;
	else
	{
		int mid=left+(right-left)/2;
		if(judge(mid,divided_num,n)==1) return merge(left,mid,divided_num,n);
		else  return merge(mid+1,right,divided_num,n);
	}
}
int main()
{
	int n,divided_num,i;
	int max=0,min=0;
	scanf("%d%d",&n,&divided_num);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		max=max+a[i];
		if(a[i]>min) min=a[i];//这里的Min指的是单个数最大值 
	}
	int ans=merge(min,max,divided_num,n);
	printf("%d",ans);
	return 0;
}