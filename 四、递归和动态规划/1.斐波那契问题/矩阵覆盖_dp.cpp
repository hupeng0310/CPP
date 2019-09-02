/*
���⣺��n��2*1��С���κ��Ż����Ÿ���2*n�Ĵ���Σ����ж����ַ�����

1�����ǵ�Ϊn-1ʱ�����ŷ�һ�����ɣ�Ϊf(n-1)��
2����Ϊn-2ʱ��Ϊ��n-1���ظ������Ժ��ŷ��������ɣ�Ϊf(n-2)�֣�
3������f(n)=f(n-1)+f(n-2)

Ϊʲôn-3�������ƣ���Ϊn-3ʱ�ٷ�1����2���ͺ�n-2��n-1�ظ��� 
*/
#include <iostream>
using namespace std;

//ʹ���������� 
int allRectCover1(int n)
{
	int result,a[n];
	a[1]=1;//n=1ʱ��1�ַ��� 
	a[2]=2;//n=2ʱ��2�ַ��� 
	for(int i=3;i<=n;++i){//��3��ʼ���� 
		result=a[i-1]+a[i-2];//����result 
		a[i]=result;//������һ�� 
	} 
	
	return result;
} 

//ʹ�ñ������� 
int allRectCover2(int n)
{
	int result=2;//��ʼֵΪn=2ʱ��2�ַ��� 
	int pre=1;//��ʼֵǰһ��Ϊ1 
	int temp;//��¼��ǰ�������ʱ���� 

	for(int i=3;i<=n;++i){//��3��ʼ���� 
		temp=result;//��¼�µ�ǰresult 
		result+=pre;//������ 
		pre=temp;	//��ǰһ����Ϊ����Ľ�� 
	}
	
	return result;
} 

int main()
{
	//����
	int n;
	cout<<"������n��ֵ"<<endl;
	cin>>n;
	
	//cout<<"�ܷ�����Ϊ(ʹ����������)��"<<allRectCover1(n)<<endl; 
	cout<<"�ܷ�����Ϊ(ʹ�ü�����������)��"<<allRectCover2(n)<<endl; 
	return 0;
} 
