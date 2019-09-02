/*
���⣺�ַ���ƥ�䣬�����ַ���s�в����ַ���m�Ƿ���ڣ�����ƥ�����s�е���λ�ã����򷵻�-1 
		leetcode28(Accepted). Implement strStr()
		 
KMP�㷨��
*/ 
#include <iostream>
using namespace std;

//��next���� 
void getNext(string &m,int *next,int len)
{
	if(m.length()==1){//��mֻ��һλ��ֱ������next[0]Ϊ-1�����أ������ж��� 
		next[0]=-1;
		return;
	}
	
	next[0]=-1;//��ʼnext[0]=-1,next[1]=0 
	next[1]=0;
	int pos=2;//�����ĵ�ǰ�ַ�λ�� 
	int cn=0;//��¼ÿ����ǰ�����ַ�λ�� 
	while(pos<len){//���� 
		if(m[pos-1]==m[cn])//���ǵ�ǰ����ǰһ���ַ���cnλ���ַ���ȣ�next��Ӧֵ++��ͬʱpos++��++cn 
			next[pos++]=++cn;
		else if(cn>0)//����Ļ�cnû������ǰ�棬�ͽ�����ǰ�� 
			cn=next[cn];
		else
			next[pos++]=0;//�����Ϊ-1,ͬʱpos++ 
	}
		
}
//ƥ�� 
int strStr(string &s,string &m)
{
	if(m.length()>s.length())
		return -1;
		
	int len=m.length();
	int next[len];
	getNext(m,next,len); //��next���� 
	
	int si=0;
	int mi=0;
	while(si<s.length() && mi<m.length()){//����s��m 
		if(s[si]==m[mi]){//�����ȣ���Ӧλ�ö�++ 
			++si;
			++mi;
		}
		else if(next[mi]==-1)//�����Ӧ��mi��nextֵΪ-1������s����һ��λ�� 
			++si;
		else
			mi=next[mi];//�������ǰ��m 
	}
	
	return mi==m.length() ? si-mi : -1; //���m��������󣬷���ƥ��Ŀ�ʼλ�ã����򷵻�-1 
} 

int main()
{	
	string s,m;
	cout<<"�����������ַ�����"<<endl;
	cin>>s>>m;
	//s="";
	//m="";
	cout<<"ƥ��Ŀ�ʼλ��Ϊ��"<<strStr(s,m)<<endl; 
	
	return 0;
}
