͹���ܳ�
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
double crossProd(point A,point B,point C) //���� 
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
//�������µĵ�Ϊ��׼�㣬�������㣨��ʱ�뷽���Լ��Ǵ�С������������
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
    double k=crossProd(p[0],*c,*d);//���Ǵ�Сת��Ϊ����
    if (k<1e-8||iszero(k)&&dis(p[0],*c)>dis(p[0],*d)) return 1;
    return -1;
}
void Graham(int n) 
{
	int x,y,min=0,i;
    x=p[0].x;
    y=p[0].y;
    for(i=1;i<n;i++) //�ҵ������µ�һ����
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
    for(i=3;i<=n;i++) //����һ�����,����ƫ�ջ��ߣ�����һ���㲻��͹���ڣ���--top���ù���ֱ��������ƫ�ջ�û�����㹲�ߵĵ� 
	{
        while(crossProd(stack[top-1],stack[top],p[i])<=1e-8&&top>=2) top--;
        stack[++top]=p[i];//�ڵ�ǰ����·���͹���ĵ㣬��ջ
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