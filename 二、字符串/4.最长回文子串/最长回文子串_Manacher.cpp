/*
���⣺��һ���ַ�����������Ӵ��ĳ���

Manacher�㷨 ����ʱ�临�Ӷ�O��n��
1������ͨ����ÿ���ַ������߶�����һ������ķ��ţ������п��ܵ�������ż�����ȵĻ����Ӵ���ת�������������ȡ�
   ���� abba ��� #a#b#b#a#�� aba��� #a#b#a#�������Ͳ��ÿ�������ż���������ˡ� 

2��Ϊ�˽�һ�����ٱ���ĸ��Ӷȣ��������ַ����Ŀ�ʼ������һ�������ַ��������Ͳ������⴦��Խ�����⣬����$#a#b#a#����ʵ��ǰ�������ַ���ѡ��������⣬����Ӱ��������� 

3����һ������ P[i] ����¼���ַ�S[i]Ϊ���ĵ�������Ӵ�������������ŵĳ��ȣ�����S[i]����P[i]-1������ԭ�ַ���������Ĵ����ܳ��� 

4������������������id��mx������id��ʾ�������Ӵ����ĵ�λ�ã�mx��Ϊid+P[id]��Ҳ�����������Ӵ��ı߽硣�õ�һ������Ҫ�Ľ��ۣ�
   ���mx > i����ôP[i] >= Min(P[2 * id - i], mx - i) 
   ���� mx <= i ���������Ϊ�޷��� P[i]������ļ��裬ֻ����P[i] = 1��Ȼ����ȥƥ��	
*/
#include <iostream>
#include <string>
using namespace std;

//�õ�С���� 
int minNum(int a,int b)
{
	if(a>b)
		return b;
	return a;
}

//�����ַ��� 
string handleString(string &s){
	int i;
	string sTemp="$#";//�����ַ���Ϊ$# 
	for(i=0;i<s.length();++i){//����ÿ���ַ� 
		sTemp+=s[i];
		sTemp+="#";//ÿ�β���һ��#�ַ� 
	}
	return sTemp;
} 
//������Ĵ����� 
int longestPalindrome(string &s)
{
	//cout<<s<<endl;
	int p[100],mx=0,id=0,i,max=0;
	for(i=1;i<s.length();++i){
		p[i]=mx>i ? minNum(p[2*id-i],mx-i) : 1;//��Ϊ����P[i] >= Min(P[2 * id - i], mx - i)������ȡ�Ⱥţ��������������жϣ����� mx <= i ���������Ϊ�޷��� P[i]������ļ��裬ֻ����P[i] = 1��Ȼ����ȥƥ�� 
		while(s[i+p[i]]==s[i-p[i]]){//���������ж� 
			p[i]++;
		}
		if(i+p[i]>mx){//��������߽����mx�����±߽磬����id 
			mx=i+p[i];
			id=i;
		}
	}
	for(i=1;i<s.length();i++){//����p[]���飬�ҵ�����ֵ 
		if(max<p[i])
			max=p[i];
	}
	return max-1;
}

int main()
{
	//���� 
	string s;
	cout<<"�������ַ�����"<<endl;
	cin>>s;
	//�����ַ���
	string s0=handleString(s); 
	//������ 
	cout<<"�����"<<longestPalindrome(s0)<<endl;
	return 0;
} 
