/*
���⣺һ��������1��2��3��̨�ף�����n��̨���ж������߷�

����ʽ��f(n)=f(n-1)+f(n-2)+f(n-3) 
1����������n-1��������һ����һ�����ɣ�������f(n-1)���߷� 
2����������n-2��������һ�����������ɣ�������f(n-2)���߷� 
3����������n-3��������һ�����������ɣ�������f(n-3)���߷� 
������������ǲ����ã��������߷�Ϊ�����������֮��
Ϊʲô������n-4���������Ϊ���һ����3����n-4��1,2��3���ֱ��Ӧ��������������Ѿ����������� 
*/ 
#include <iostream>
using namespace std;

//�ݹ��� 
int climbStairs(int n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else if(n==3)
		return 4;
	else 
		return climbStairs(n-1)+climbStairs(n-2)+climbStairs(n-3);
		
}

int main()
{
	//���� 
	int n;
	cout<<"������¥������"<<endl;
	cin>>n;
	
	//������
	cout<<"���е��߷���"<<climbStairs(n)<<endl; 
	
	return 0;
}
