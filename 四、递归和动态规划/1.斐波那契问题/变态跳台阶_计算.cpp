/*
���⣺һֻ���ܿ�����1��n��̨�ף�������n��̨�׵������� 

f(1)=1;
f(2)=f(1)+f(0);
f(3)=f(2)+f(1)+f(0);
......
f(n-1)=f(n-2)+f(n-3)+...+f(0)
f(n)=f(n-1)+f(n-2)+...+f(0)
	=f(n-1)+f(n-1)
	=2*f(n-1)
 ���Եõ�����ʽ��
 	f(n)=2*f(n-1)=2*2*f(n-2)=...=2^(n-1) 
*/
#include <iostream>
using namespace std;

int climbStairs(int n)
{
	return 1<<--n;//1����n-1λ�൱��2��n-1�η� 
} 

int main()
{
	//���� 
	int n;
	cout<<"������̨������"<<endl;
	cin>>n;
	
	cout<<"������Ϊ��"<<climbStairs(n)<<endl; 
	
	return 0;
} 
