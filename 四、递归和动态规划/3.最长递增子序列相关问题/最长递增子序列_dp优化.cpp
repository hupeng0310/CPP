/*
���⣺��һ������������������

O��NlogN���Ľⷨ(������dp�����ʱ�临�Ӷ�,��Ҫ���ö��ֽ����Ż�)��
1��ʹ�ø�������end[]��end[i]��¼i+1���ȵĵ������е���Сĩβ����ά��һ�����������У����Կ��Զ��ֲ��� 
2��dp[i]��ֵ��Ϊ����end����λ�ö�Ӧ�ĳ��ȣ���Ϊǰ�涼��С�ģ� 


���dp��������ɵõ���󳤶��Ƕ��٣���������󳤶ȶ�Ӧ������
1���Ӻ���ǰ�����������dp[i]������ǰ����
2������dp[j]=dp[i]-1 ��a[j]<a[i]����Ϊ����
3��...... 
*/ 
#include <stdio.h>
#include <stack>
using namespace std;

//�õ�dp���� 
void getdp(int *a,int *dp,int len)
{
	int end[len];//����end�������� 
	end[0]=a[0];//��һλΪa[0] 
	dp[0]=1;//dp��һλΪ1 
	int right=0;//end��Ч��λ�� 
	int l=0;//��Ч����� 
	int r=0;//��Ч���ұ� 
	int m=0;//��Ч���м� 
	for(int i=0;i<len;++i){
		l=0;//ÿ��l������� 
		r=right;//r�����ұ� 
		while(l<=r){//���ֲ���end����,������<=������û�ҵ�l=right+1,��Ч������һλ**** 
			m=(l+r)/2; 
			if(a[i]>end[m])
				l=m+1;
			else
				r=m-1;
		}
		right=right>l ? right:l;//�޸���Ч��λ�� 
		end[l]=a[i];//Ҫ�����λ�� 
		dp[i]=l+1;//dp[i]Ϊ��Ч���ĳ��ȣ���Ϊl+1 
	} 
}

void getLongestList(int *a,int len)
{
	int dp[len];
	getdp(a,dp,len);
	
	int maxLen=0;
	int index=0;
	for(int i=0;i<len;++i)//����dp������ֵ 
		if(dp[i]>maxLen){
			maxLen=dp[i];
			index=i;
		}
	printf("����������г���Ϊ:%d\n",maxLen);
	
	stack<int> list;//����ջ������������У���Ϊ�ǴӺ���ǰ���������У� 
	list.push(a[index]);//�Ƚ�������ջ 
	for(int i=index;i>=0;--i)//�Ӻ���ǰ���� 
		if(a[i]<a[index] && dp[i]==dp[index]-1){//���ǰ��ıȵ�ǰС����dp��������С1��ϵ����ջ 
			list.push(a[i]);
			index=i;//ͬʱ��index�޸�Ϊ��������λ�� 
		}
	printf("�����������Ϊ��");
	while(!list.empty()){//��� 
		printf("%d ",list.top());
		list.pop();
	}			
	printf("\n");
}


int main(int argc,char *argv[])
{
	printf("���������У���-1��β����"); 
	int n=0,data,a[100];
	while(scanf("%d",&data) && data!=-1){
		a[n++]=data;
	}
	
	getLongestList(a,n);
	
	return 0;
} 
