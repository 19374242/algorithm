
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