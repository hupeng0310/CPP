/*
���⣺һ��������ֻ��һ�������������Σ��������������ż���Σ���������

������㣺1^1=0  0^0=0  1^0=1  0^1=1
���Խ����������Ļ�����ͬ������Ӧλ��ͬ�����֮��Ϊ0�����벻ͬ������������ǽ�� 
*/ 
#include <stdio.h>
#include <vector>
using namespace std;

int oddTimeNumber(int *a,int len)
{
	int i=0;//i���ڱ��� 
	int res=0;//res��¼�������ֵΪ0 
	while(i<len){
		res ^= a[i];//������� 
		i++;
	} 
	return res;
}


int main()
{
	int a[]={2,3,2,4,5,4,5,6,7,7,6};
	int len=sizeof(a)/sizeof(int);//�󳤶� 
	//���
	printf("���������εĽ��Ϊ��%d\n",oddTimeNumber(a,len)) ;
	return 0;
}
