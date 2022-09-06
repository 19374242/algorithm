//N条直线交点多少个
#include<iostream>
using namespace std;
struct node
{
    double x1,y1,x2,y2;
	int cnt;//第cnt条线段	
}line[40000];
int cnt=0;
int n;
double direction(double x,double y,double x1,double y1,double x2,double y2)  //叉积  
{  
    double a1=x1-x;  
    double b1=y1-y;  
    double a2=x2-x;  
    double b2=y2-y;  
    return a1*b2-a2*b1;  
}  
int on_segment(double x1,double y1,double x2,double y2,double x,double y)  //判断共线  
{      
    if((min(x1,x2)<=x && x<=max(x1,x2)) && (min(y1,y2)<=y && y<=max(y1,y2)))  return 1;  
    return 0;  
}  
int cross(int v,int t)//是否交叉，根据算法导论写的 
{    
    double d1,d2,d3,d4;  
    d1=direction(line[t].x1,line[t].y1,line[t].x2,line[t].y2,line[v].x1,line[v].y1);    //算叉积  
    d2=direction(line[t].x1,line[t].y1,line[t].x2,line[t].y2,line[v].x2,line[v].y2);  
    d3=direction(line[v].x1,line[v].y1,line[v].x2,line[v].y2,line[t].x1,line[t].y1);  
    d4=direction(line[v].x1,line[v].y1,line[v].x2,line[v].y2,line[t].x2,line[t].y2);  
    if(d1*d2<0 && d3*d4<0) return 1;   
    if(!d1 && on_segment(line[t].x1,line[t].y1,line[t].x2,line[t].y2,line[v].x1,line[v].y1)) return 1;  
    if(!d2 && on_segment(line[t].x1,line[t].y1,line[t].x2,line[t].y2,line[v].x2,line[v].y2)) return 1;  
    if(!d3 && on_segment(line[v].x1,line[v].y1,line[v].x2,line[v].y2,line[t].x1,line[t].y1)) return 1;  
    if(!d4 && on_segment(line[v].x1,line[v].y1,line[v].x2,line[v].y2,line[t].x2,line[t].y2)) return 1;  
    return 0;  
}
int main()
{
	int i,j,sum=0;
	cin>>n;
	while(n--)
	{
		cin>>line[cnt].x1>>line[cnt].y1>>line[cnt].x2>>line[cnt].y2;
		for(i=0;i<cnt;i++)
		{
			if(cross(i,cnt)==1) sum++;
		}
		cnt++;
	}
	cout<<sum<<endl;
	return 0;
} 