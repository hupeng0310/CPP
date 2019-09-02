/*
���⣺���ļ����Ŷ��뵹�Ŷ�һ��������12321

ǰ������ָ������Ƚϼ��� 
*/
#include <iostream>
#include <string>
using namespace std;
//�ж��ַ��� 
bool isPalindromeString(string &s,int len)
{
	if(len<1)
		return false;
	int low=0,high=len-1;//lowָ��ͷ��highָ��β 
	while(low<high){//ֱ��ǰ������ 
		if(s[low]!=s[high])//����Ⱦͷ���false 
			return false;
		++low;
		--high; 
	}
	return true;
}
//�ж��ַ�����
bool isPalindromeChars(char *c,int len)
{
	if(c==NULL || len<1)
		return false;
	char *front,*back;//����ǰ������ָ�� 
	front=c;//frontָ��ͷ 
	back=c+len-1;//backָ��β 
	while(front<back){
		if(*front != *back)//ȡ���ַ����бȽϣ�����ȷ��� 
			return false;
		++front;
		--back;
	}
	return true;
}
int main()
{
//===�ַ��� 
	//����
	string s;
	cout<<"�������ַ���:"<<endl;
	cin>>s;
	//������ 
	cout<<"�ַ������1:"<<isPalindromeString(s,s.length())<<endl;
	
//===�ַ����� 
	//����
	char c[100],data,n=0;
	cout<<"�������ַ����飨��0��β��"<<endl;
	while(cin>>data && data!='0'){
		c[n++]=data;
	}
	//������ 
	cout<<"�ַ�������2:"<<isPalindromeChars(c,5)<<endl;
	return 0;
}
