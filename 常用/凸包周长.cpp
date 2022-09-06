凸包周长
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct point 
{
    double x;
    double y;
}p[300000],stack[300000];
int top=2;
double crossProd(point A,point B,point C) //极角 
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
//以最左下的点为基准点，其他各点（逆时针方向）以极角从小到大的排序规则
double dis(point A,point B) 
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
bool iszero(double x)
{
    return (x>0?x:-x)<1e-8;
}
int cmp(const void *a, const void *b) 
{
    point *c=(point*)a;
    point *d=(point*)b;
    double k=crossProd(p[0],*c,*d);//极角大小转化为求叉乘
    if (k<1e-8||iszero(k)&&dis(p[0],*c)>dis(p[0],*d)) return 1;
    return -1;
}
void Graham(int n) 
{
	int x,y,min=0,i;
    x=p[0].x;
    y=p[0].y;
    for(i=1;i<n;i++) //找到最左下的一个点
	{
        if(p[i].x<x||(p[i].x==x&&p[i].y<y))
		{
            x=p[i].x;
            y=p[i].y;
            min=i;
        }
    }
    point tmp=p[min];
    p[min]=p[0];
    p[0]=tmp;
    qsort(p+1,n-1,sizeof(point),cmp);
    p[n]=p[0];
    stack[0]=p[0];
    stack[1]=p[1];
    stack[2]=p[2];
    for(i=3;i<=n;i++) //加入一个点后,向右偏拐或共线，则上一个点不在凸包内，则--top，该过程直到不向右偏拐或没有三点共线的点 
	{
        while(crossProd(stack[top-1],stack[top],p[i])<=1e-8&&top>=2) top--;
        stack[++top]=p[i];//在当前情况下符合凸包的点，入栈
    }
    return;
}

int main() 
{
    int n,i;
    double len;
    cin>>n;
    for(i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    Graham(n);
    for(i=0;i<top;i++) len=len+sqrt((stack[i].x-stack[i+1].x)*(stack[i].x-stack[i+1].x)+(stack[i].y-stack[i+1].y)*(stack[i].y-stack[i+1].y));
    printf("%.2lf\n",len);
    return 0;
}