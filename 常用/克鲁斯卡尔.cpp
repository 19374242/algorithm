��³˹�����㷨����С��������
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int x;
	int y;
	int value;
	struct node *next;
}LNode,*linklist;
int cmp(const struct node *p1,const struct node *p2)
{
	return (int)(p1->value-p2->value);
}
LNode edgelist[600000];
int ei=0;
int n,m;
long long int sum=0;
int father[500000];
void make()//��ʼ����ÿ���ڵ㸸�ڵ������Լ� ��ÿ�����ڵ���һ������ 
{
	int i;
    for(i=0;i<n;i++) father[i]=i;
}
 
int find_father(int x)//�Ҹ��ڵ� 
{
    if(x!=father[x])
    {
    	x=father[x];
    	x=find_father(x);
	}
    return x;
}      
/*int find_father(int x)//�Ҹ��ڵ� ���鼯·��ѹ����С�Ż�����ֻҪ1���ҵ����Ƚ�㣩
{
    if(x==father[x])
        return x;
    else
	{
        father[x]=find_father(father[x]);  //���ڵ���Ϊ���ڵ�
        return father[x];         //���ظ��ڵ�
    }
}*/                                 
void Union(int x, int y)//��x,y�ϲ���ͬһ������
{
    x=find_father(x);
    father[x]=find_father(y);
}
void Kruskal()
{
	int i;
    make();
    for(i=0;i<ei;i++)//���ߵ�˳�򰴴�С����ȡ����
    {
        if(find_father(edgelist[i].x)!=find_father(edgelist[i].y))    
		 //����������㲻��һ�������У��Ͳ���һ��������������ĳ��ȼ��������ߵĳ���
        {
            Union(edgelist[i].x,edgelist[i].y);  //�ϲ��������㵽һ������
            sum=sum+edgelist[i].value;
        }
    }
    return;
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)//����� 
	{
		scanf("%d%d%d",&x,&y,&z);
		edgelist[ei].x=x;edgelist[ei].y=y;edgelist[ei].value=z;ei++;
	}
	qsort(edgelist,ei,sizeof(struct node),cmp);//���ߵĳ������� 
    Kruskal(); 
	printf("%lld",sum);
	return 0;
}