克鲁斯卡尔算法（最小生成树）
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
void make()//初始化，每个节点父节点是他自己 ，每个父节点是一个集合 
{
	int i;
    for(i=0;i<n;i++) father[i]=i;
}
 
int find_father(int x)//找父节点 
{
    if(x!=father[x])
    {
    	x=father[x];
    	x=find_father(x);
	}
    return x;
}      
/*int find_father(int x)//找父节点 并查集路径压缩的小优化（都只要1步找到祖先结点）
{
    if(x==father[x])
        return x;
    else
	{
        father[x]=find_father(father[x]);  //父节点设为根节点
        return father[x];         //返回父节点
    }
}*/                                 
void Union(int x, int y)//将x,y合并到同一个集合
{
    x=find_father(x);
    father[x]=find_father(y);
}
void Kruskal()
{
	int i;
    make();
    for(i=0;i<ei;i++)//将边的顺序按从小到大取出来
    {
        if(find_father(edgelist[i].x)!=find_father(edgelist[i].y))    
		 //如果两个顶点不在一个集合中，就并到一个集合里，生成树的长度加上这条边的长度
        {
            Union(edgelist[i].x,edgelist[i].y);  //合并两个顶点到一个集合
            sum=sum+edgelist[i].value;
        }
    }
    return;
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)//输入边 
	{
		scanf("%d%d%d",&x,&y,&z);
		edgelist[ei].x=x;edgelist[ei].y=y;edgelist[ei].value=z;ei++;
	}
	qsort(edgelist,ei,sizeof(struct node),cmp);//按边的长度排序 
    Kruskal(); 
	printf("%lld",sum);
	return 0;
}