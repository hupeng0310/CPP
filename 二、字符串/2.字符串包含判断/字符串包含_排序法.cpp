/*
���⣺�ж�A�ַ����Ƿ����B�ַ�����A��12,B��111ͬ����ʾ������ 
 
���Ƚ��ַ������п�������Ȼ����б����ж�,��Ϊ���򣬱���ʱA�Ͳ���Ҫÿ�δ�ͷ��ʼ������ 
ʱ�临�Ӷ�Ϊ��O��mlogm��+O��nlogn��+O��m+n�� 
*/ 
#include <iostream>
#include <string> 
using namespace std;

//�������� 
void quickSort(string &s,int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	char key=s[low];
	while(i<j){
		while(i<j && s[j]>=key)
			--j;
		s[i]=s[j];
		while(i<j && s[i]<=key)
			++i;
		s[j]=s[i];
	}
	s[i]=key;
	quickSort(s,low,i-1);
	quickSort(s,i+1,high);
} 
//�ж��Ƿ���� 
bool stringContain(string &s1,string &s2)
{
	quickSort(s1,0,s1.length()-1);
	quickSort(s2,0,s2.length()-1);//���� 
	//cout<<s1<<"   "<<s2<<endl;
	int i,j;
	for(i=0,j=0;j<s2.length();++j){//����s2�ַ��� 
		while(i<s1.length() && s1[i]<s2[j])//����s1�����û��ƥ��s1λ�þ�++ 
			++i;
		if(i>=s1.length() || s1[i]>s2[j])//���û���ҵ������������һ����i��λ��Խ�磬���ǵ�ǰλ���ַ�����s1��ǰλ�õ�ֵ���ͷ���false
			return false;
	}
	return true;
}

int main()
{
	//���� 
	string s1,s2;
	cout<<"�������ַ���a:"<<endl;
	cin>>s1;
	cout<<"�������ַ���b:"<<endl;
	cin>>s2;
	//������ 
	cout<<"�����"<<stringContain(s1,s2)<<endl; 
	return 0;
}
