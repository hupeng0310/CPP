/*
�ж�A�ַ����Ƿ����B�ַ�����A��12,B��111ͬ����ʾ������ 

�����������������Ӷ�ΪO��m*n�� 
*/ 

#include <iostream>
#include <string>
using namespace std;

bool stringContain(string &a,string &b)
{
	int i,j;
	for(i=0;i<b.length();++i){//�ж�a�Ƿ����b�����ȱ���b��Ȼ�����a��������a��û���ҵ��ͷ���false 
		for(j=0;j<a.length() && b[i]!=a[j];++j);//b[i]!=a[j]���������ң� 
		if(j>=a.length())//û���ҵ��ͷ���false 
			return false;
	}
	return true;
} 

int main()
{
	string s1,s2;
	int n1=0,n2=0;
	//����
	cout<<"�������һ���ַ�����"<<endl;
	cin>>s1;
	cout<<"������ڶ����ַ���������0��β��"<<endl;
	cin>>s2;
	//����жϽ��
	cout<<"�����"<<stringContain(s1,s2)<<endl;
	return 0;
}
