/*
���⣺����һ���ַ�������ӡ�����ַ������ַ����������С�

��ȫ���У������ڽ�������λ�ã���abcΪ��
1���̶�a�������bc�����У�abc��acb����ú�a��b�������õ�bac
2���̶�b�������ac�����У�bac��bca����ú�c�ŵ���һλ�ã��õ�cba
3���̶�c�������ba�����У�cba��cab�� 
*/
#include <iostream>
using namespace std;

int count=0;//ȫ�ֱ�����ͳ��ȫ���и��� 

//�������� 
void swapNum(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

void allPermutation(char *c,int low,int high)
{
	if(high<=1)//Ԫ�ظ���С��1��ֱ�ӷ��� 
		return;
	int i,j;
	if(low==high){//lowһֱ���󣬵�low����highʱ���ӡ������ 
		cout<<(++count)<<":";
		for(i=0;i<=high;++i)
			cout<<c[i];
		cout<<endl;
	}
	else{
		for(j=low;j<=high;++j){
			swapNum(c+j,c+low);//�������� 
			allPermutation(c,low+1,high);//�ݹ鴦������� 
			swapNum(c+j,c+low);//�ָ��ϴε��������� 
		}
	}
} 

int main()
{
	//���� 
	char c[100],data;
	int n=0;
	cout<<"�������ַ�������0��β��"<<endl;
	while(cin>>data && data!='0'){
		c[n++]=data;
	}
	//ȫ���� 
	cout<<"ȫ���н����"<<endl;
	allPermutation(c,0,n-1);
	return 0;
}
