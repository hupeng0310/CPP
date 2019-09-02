/*
���⣺ȥ���ַ�������������K����0. eg:a00b  ==>  a  b

1��count����ͳ������0�ĸ�������ֵΪ0��start���ڼ�¼ÿ���״γ���0��λ�ã���ֵΪ-1
2�������ַ�������str[i]=='0', start=start==-1 ? i : start,��Ϊ��start==-1,��֮ǰû�г���0
	����Ϊ��ǰλ��i������start����
3����str[i]!='0'���ж�count�Ƿ����k�����ǣ���0λ����Ϊ�ո�
4������ÿ�ε� str[i]!='0'ʱ���㣬����������0��β����Ҫ����ж�һ�� 
*/
#include <iostream>
#include <string>
using namespace std;

string removeKZeros(string &str,int k)
{
	if(str.empty() || k<1)
		return str;
	
	int count=0;//ͳ��ÿ��0�ĸ��� 
	int start=-1;//ÿ�δ�0��ʼ��λ�� 
	
	for(int i=0;i<str.length();++i){//�����ַ��� 
		if(str[i]=='0'){//��Ϊ0 
			++count;
			start = start == -1 ? i : start;//����start��λ��**������Ϊ-1,��startΪi,���򲻱䣬����start 
		}
		else{//�����ж��Ƿ���� 
			if(count==k){
				while(count--)
					str[start++]=0;//��λ����Ϊ�ո�0��ASCIIΪ�ո� 
			}
			count=0;//���� 
			start=-1;
		}
	}
	if(count==k)//������ж�һ�� 
		while(count--)
			str[start++]=0;
			
	return str;
}

int main()
{
	//���� 
	cout<<"�������ַ�����"<<endl; 
	string str;
	cin>>str;
	cout<<"������K��"<<endl;
	int k;
	cin>>k;
	
	//������
	cout<<removeKZeros(str,k); 
	
	return 0;
}
