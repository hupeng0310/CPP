/*
���⣺��n��2*1��С���κ��Ż����Ÿ���2*n�Ĵ���Σ����ж����ַ�����

1�����ǵ�Ϊn-1ʱ�����ŷ�һ�����ɣ�Ϊf(n-1)��
2����Ϊn-2ʱ��Ϊ��n-1���ظ������Ժ��ŷ��������ɣ�Ϊf(n-2)�֣�
3������f(n)=f(n-1)+f(n-2)

Ϊʲôn-3�������ƣ���Ϊn-3ʱ�ٷ�1����2���ͺ�n-2��n-1�ظ��� 
*/
#include <iostream>
using namespace std;

int allRectCover(int n)
{
	if(n<1)
		return 0;
	else if(n==1||n==2)//��n=1��Ϊ1�ַ�������n=2ʱΪ���ַ���  
		return n;
	else 
		return  allRectCover(n-1)+allRectCover(n-2);
} 

int main()
{
	//����
	int n;
	cout<<"������n��ֵ"<<endl;
	cin>>n;
	
	cout<<"�ܷ�����Ϊ��"<<allRectCover(n)<<endl; 
	
	return 0;
} 
