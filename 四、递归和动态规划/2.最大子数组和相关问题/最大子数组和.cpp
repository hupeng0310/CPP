/*
���⣺��һ����������������� 

1��sumΪ��ǰһ��������ĺͣ�max�洢���ֵ
2���������飬�ۼӵ�sum�ϣ���max��ȣ�������max������maxֵ������sum<0��������sum=0 

Ϊʲô���ּ�������ȷ�ģ�����һ�������������ģ���������ǰ׺�ز�Ϊ��������ΪҪ�Ǹ��������粻Ҫ���ǰ׺������������ 
*/
#include <iostream>
using namespace std;	

#define INT_MIN (-2147483647 - 1) 

int maxSubSum(int *a,int len)
{
	int sum=0;//�洢��ǰ���������� 
	int max=INT_MIN;//max��ʼȡ��С��ֵ 
	for(int i=0;i<len;++i){//�������� 
		sum+=a[i];//��� 
		if(sum>max)//��max�Ƚ� 
			max=sum;
		if(sum<0)//��sumΪ�������� 
			sum=0;
	}
	
	return max;
} 

int main()
{
	//����
	int *a,data,n=0;
	cout<<"����������Ԫ�أ���-1��β����"<<endl;
	while(cin>>data && data!=-1){
		a[n++]=data;
	} 
	
	//������
	cout<<"���Ϊ��"<<maxSubSum(a,n)<<endl; 
	return 0;
} 
