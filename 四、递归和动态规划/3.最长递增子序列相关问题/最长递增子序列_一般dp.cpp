/*
���⣺��һ������������������

O��n^2���Ľⷨ��
1����dp���飬dp[i]������a[i]��β������������������еĳ��ȣ�dp[i]���Ը���dp[i-1]����� 
2������dp[i]ʱ����Ҫ����dp[0..i-1]��j���������ǰa[i]����a[j],dp[i]=max{dp[j]+1} 

���dp��������ɵõ���󳤶��Ƕ��٣���������󳤶ȶ�Ӧ������
1���Ӻ���ǰ�����������dp[i]������ǰ����
2������dp[j]=dp[i]-1 ��a[j]<a[i]����Ϊ����
3��...... 
 
*/
#include <stdio.h>
#include <stack>
using namespace std;

//��dp���� 
void getdp(int *a,int *dp,int len)
{
	for(int i=0;i<len;++i){//���� 
		dp[i]=1;//������Ϊ1 
		for(int j=0;j<i;++j)//����0..i-1 
			if(a[i]>a[j])//�����ǰa[i]>a[j],dp[i]ȡ��������������dp��ֵ+1 
				dp[i]=dp[i]>(dp[j]+1) ? dp[i] : (dp[j]+1);//��Ϊj�ڱ䶯������dp[i]Ҳ�Ǳ仯�ģ�������dp[i]=max(dp[i],dp[j]+1) 
	}
}

//�������Ԫ�� 
void getLongestList(int *a,int len)
{
	int dp[len];
	getdp(a,dp,len);//�õ�dp���� 
	
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
	//���� 
	printf("������һ�������֣���-1��β����");
	int n=0,a[100],data;
	while(scanf("%d",&data) && data!=-1){
		a[n++]=data;
	} 
	
	getLongestList(a,n);

	return 0;
} 
