/*
���⣺��һ���ַ�����������Ӵ��ĳ���

�����ַ������Ե�ǰ�ַ���������չ�Ƚϼ��ɣ���¼��ǰ��󳤶�
��Ҫע�����������չ�����������һ�����������ַ�����һ����ż�����ַ� 
*/ 
#include <iostream>
#include <string>
using namespace std;

int longPalindrome(string &s,int len)
{
	int i,j,max=0,temp;
	if(len<1)
		return 0;
	for(i=0;i<len;++i){//�����ַ� 
		for(j=0;(i-j>=0) && (i+j<len);++j){//�������ַ����Ե�ǰiΪ������չ 
			if(s[i-j]!=s[i+j])//�����в������break 
				break;
			temp=j*2+1;//�õ����� 
		}
		if(temp>max)
			max=temp;//�������ֵ 
		for(j=0;(i-j>=0) && (i+j+1<len);++j){//ż�����ַ������Ҷ���չһ�� 
			if(s[i-j]!=s[i+j+1])//��������˳� 
				break;
			temp=j*2+2;
		}
		if(temp>max)
			max=temp;//�������ֵ 
	}
	return max;
} 

int main()
{
	//���� 
	string s;
	cout<<"�������ַ���"<<endl;
	cin>>s;
	//������Ƚ��
	cout<<"�����"<<longPalindrome(s,s.length())<<endl;
	return 0;
} 
