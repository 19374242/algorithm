点集中任意两点最大距离
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct P{
    double x,y;    
}p[200000],q[200000];
int n,top;
double ans=0;
double dis2(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double xmult(P a,P b,P o){
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double cmp(P a,P b){
    return xmult(a,b,p[1])>0||xmult(a,b,p[1])==0&&dis2(a,p[1])<dis2(b,p[1]);
}
void graham(){
    sort(p+2,p+1+n,cmp);
    q[1]=p[1],q[2]=p[2];
    top=2;
    for(int i=3;i<=n;i++){
        while(xmult(q[top],p[i],q[top-1])<=0&&top>1)top--;
        q[++top]=p[i];
    }
}
void qiake(){
    q[top+1]=q[1];
    int now=2;
    for(int i=1;i<=top;i++){
        while(xmult(q[i+1],q[now],q[i])<xmult(q[i+1],q[now+1],q[i]))
        {
            now++;
            if(now>top)now=1;
        }
        ans=max(ans,dis2(q[now],q[i]));
    }
}
int main() {
    scanf("%d",&n);
    int t=1;
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(p[t].y>p[i].y||p[t].y==p[i].y&&p[t].x>p[i].x)t=i;
    }
    swap(p[1],p[t]);
    graham();
    qiake();
    printf("%.6lf",sqrt(ans));
    return 0;
}