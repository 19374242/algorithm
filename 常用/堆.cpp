
С����
int heap[3000000],heap_size=0;
void insert(int d)//����ѣ��±��1��ʼ
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
int del()//ɾ�������ضѶ�Ԫ��
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






�Ѳ���++
typedef struct node{
    int height;
    int num;
}LNode,*linklist;
LNode heap[3000000];
int heap_size=0;
void insert(int height,int num)//����ѣ��±��1��ʼ
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
void del()//ɾ���Ѷ�Ԫ��
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
void delk(int k)//ɾ���� k ����ֲ������
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
    while(now>1)//���ϱȽ� 
    {
        next=now/2;
        if(heap[now].height>=heap[next].height) break;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=now/2;
    }
    while(now*2<=heap_size)//���±Ƚ� 
    {
        next=now*2;
        if(next<heap_size&&heap[next+1].height<heap[next].height) next++;
        if(heap[now].height<=heap[next].height) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=next;
    }
    return ;
}
void fchange(int k,int x)//�޸ĵ� k ����ֲ�����ٵĸ߶ȣ������Ϊ x
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
    while(now>1)//���ϱȽ� 
    {
        next=now/2;
        if(heap[now].height>=heap[next].height) break;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=now/2;
    }
    while(now*2<=heap_size)//���±Ƚ� 
    {
        next=now*2;
        if(next<heap_size&&heap[next+1].height<heap[next].height) next++;
        if(heap[now].height<=heap[next].height) return;
        tmp=heap[now];heap[now]=heap[next];heap[next]=tmp;
        now=next;
    }
    return ;
}



��+++ ���ص�KС���������ѣ�ǰK���󶥶ѣ�����С���ѣ���


�������Ƿ��ʣ��������������
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
	return a;//aΪ���Լ�� 
}



һ�������k�Σ��������ֵ�����ֵ ��С�Ƕ��٣����ַ���������������Σ�
#include<stdio.h>
int a[200000];
int judge(int mid,int divided_num,int n)
{
	int i,num=1,sum=0;
    for(i=0;i<n;i++)
    {
        sum=a[i]+sum;
        if(sum>mid)                //�����ҽ�����Ԫ��֮����mid�Ƚϣ����Ǵ���������һ�Σ���󿴶εĴ�С
        {
            sum=a[i];
            num++;
        }
    }
    if(num>divided_num)            //���Ƕδ��ڶ��������Ȼ��������
        return 0;
    else
        return 1;

}
int merge(int left,int right,int divided_num,int n)//divided_numΪ�ֶθ�����nΪ������� 
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
		if(a[i]>min) min=a[i];//�����Minָ���ǵ��������ֵ 
	}
	int ans=merge(min,max,divided_num,n);
	printf("%d",ans);
	return 0;
}