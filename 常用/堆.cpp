
小根堆
int heap[3000000],heap_size=0;
void insert(int d)//加入堆，下标从1开始
{
    heap_size++;
    heap[heap_size]=d;
    int now=heap_size,next,tmp;
    while(now>1)
    {
        next=now/2;
        if(heap[now]>=heap[next]) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=now/2;
    }
    return;
}
int del()//删除并返回堆顶元素
{
    int res=heap[1];
    heap[1]=heap[heap_size];
    heap_size--;
    int now=1,next,tmp;
    while(now*2<=heap_size)
    {
        next=now*2;
        if(next<heap_size&&heap[next+1]<heap[next]) next++;
        if(heap[now]<=heap[next]) return res;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=next;
    }
    return res;
}






堆操作++
typedef struct node{
    int height;
    int num;
}LNode,*linklist;
LNode heap[3000000];
int heap_size=0;
void insert(int height,int num)//加入堆，下标从1开始
{
    heap_size++;
    heap[heap_size].height=height;
    heap[heap_size].num=num;
    int now=heap_size,next;
    LNode tmp;
    while(now>1)
    {
        next=now/2;
        if(heap[now].height>=heap[next].height) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=now/2;
    }
    return;
}
void del()//删除堆顶元素
{
    heap[1]=heap[heap_size];
    heap_size--;
    int now=1,next;
    LNode tmp;
    while(now*2<=heap_size)
    {
        next=now*2;
        if(next<heap_size&&heap[next+1].height<heap[next].height) next++;
        if(heap[now].height<=heap[next].height) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=next;
    }
    return ;
}
void delk(int k)//删除第 k 个种植的绿藤
{
	int i,goal;
	for(i=1;i<=heap_size;i++)
	{
		if(heap[i].num==k)
		{
			goal=i;
		}
	}	
    heap[goal]=heap[heap_size];
    heap_size--;
    int now=goal,next;
    LNode tmp;
    while(now>1)//往上比较 
    {
        next=now/2;
        if(heap[now].height>=heap[next].height) break;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=now/2;
    }
    while(now*2<=heap_size)//往下比较 
    {
        next=now*2;
        if(next<heap_size&&heap[next+1].height<heap[next].height) next++;
        if(heap[now].height<=heap[next].height) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=next;
    }
    return ;
}
void fchange(int k,int x)//修改第 k 个种植的绿藤的高度，将其变为 x
{
	int i,goal;
	for(i=1;i<=heap_size;i++)
	{
		if(heap[i].num==k)
		{
			goal=i;
		}
	}
    heap[goal].height=x;
    int now=goal,next;
    LNode tmp;
    while(now>1)//往上比较 
    {
        next=now/2;
        if(heap[now].height>=heap[next].height) break;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=now/2;
    }
    while(now*2<=heap_size)//往下比较 
    {
        next=now*2;
        if(next<heap_size&&heap[next+1].height<heap[next].height) next++;
        if(heap[now].height<=heap[next].height) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=next;
    }
    return ;
}



堆+++ 返回第K小，建两个堆（前K个大顶堆，后面小顶堆））


求两数是否互质（返回最大公因数）
int judge(int a,int b)
{
	int tmp,c;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	while(b!=0)
	{
		c=a;
		a=b;
		b=c%b;
	}
	return a;//a为最大公约数 
}



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