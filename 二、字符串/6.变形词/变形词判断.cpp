/*
���⣺�����ַ���str1,str2, ��str1��str2���ֵ��ַ�����һ����ÿ���ַ����ֵĴ���Ҳһ������Ϊ��Ϊ���δ�
	eg:str1="123",str2="213" 

1���ж��ַ����Ƿ���ȣ����ȷ���false
2������map���飬����Ԫ��Ϊ0
3������str1����Ӧ�ַ�λ��map������ֵ++
4������str2�����Ƕ�Ӧ�ַ�λ��mapλ����ֵ<=0�򷵻�false,�����Ӧ�ַ�λ��map������ֵ-- 
*/ 
#include <iostream>
#include <string>
using namespace std;

bool isdDeformation(string &str1,string &str2)
{
	if(str1.length()<1 || str2.length()<1 || str1.length()!=str2.length())
		return false;
		
	int map[256]={0},i;//map�����ʼΪ0 
	
	for(i=0;i<str1.length();++i)//����str1����Ӧ���ַ�����mapλ��+1 
		map[str1[i]]++;
	
	for(i=0;i<str2.length();++i)//����str2����Ӧ���ַ�����mapλ��-1������map[i]<=0�򷵻�false 
		if(map[str2[i]]--<=0)//����map[i]--���ǱȽϣ��ȽϺ�Ȼ��--(��ʹ�ã���--) 
			return false; 
		
	return true;
}

int main()
{
	//���� 
	string str1,str2;
	cout<<"������str1��"<<endl;
	cin>>str1;
	cout<<"������str2��"<<endl;
	cin>>str2;
	
	//���
	cout<<"�����"<<isdDeformation(str1,str2)<<endl; 
	return 0;
} 
