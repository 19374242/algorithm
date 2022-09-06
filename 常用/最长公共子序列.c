题目二十五 最长公共子序列
#include<stdio.h>
#include<string.h>
//if(i==0||j==0) a[i][j]=0;
//else if(x==y) a[i][j]=a[i-1][j-1]+1;
//else if(x!=y) a[i][j]=max(a[i-1][j],a[i][j-1]);
int max(int aa,int bb)
{
	if(aa>=bb) return aa;
	else return bb;
}
int a[2000][2000];
int b[2000][2000];
char x[2000];
char y[2000];
char ans[2000];
int ans_i=0;
int main()
{
	int i,k,j,len1,len2,mmax=0;
	scanf("%d",&k);
	scanf("%s",x);
	scanf("%s",y);
	len1=strlen(x);len2=strlen(y);
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(x[i-1]==y[j-1])
			{
				a[i][j]=1+a[i-1][j-1];
				b[i][j]=3;
			}
			else
			{
				a[i][j]=max(a[i-1][j],a[i][j-1]);
				if(a[i-1][j]>a[i][j-1]) b[i][j]=2;
				else b[i][j]=1;
			}
		}
	}
	if(k==0) printf("%d",a[len1][len2]);
	if(k==1)
	{
		i=len1;j=len2;
		while(b[i][j]!=0)
		{
			if(b[i][j]==2) i--;
			else if(b[i][j]==1) j--;
			else if(b[i][j]==3)
			{
				ans[ans_i]=x[i-1];
				ans_i++;
				i--;j--;
			}
		}
		for(i=ans_i-1;i>=0;i--) printf("%c",ans[i]);
	}
	return 0;
}