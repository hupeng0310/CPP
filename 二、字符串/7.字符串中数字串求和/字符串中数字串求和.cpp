/*
���⣺�����ַ����������е����ִ����������֮��
Ҫ�󣺣�1������С����
	  ��2�������������ַ���-����������������ʱ��������ż������������
	  		eg:a-1bc--12  ===>   -1+12=11 

1����������������result����ǰ�ۼӺͣ�number����ǰ���֣�posiΪbool�ͣ��жϵ�ǰ�������� 
2�������ַ������жϵ�ǰ�ַ������������֣����㣬��number��Ϊ0���ж��Ƿ�Ϊ'-',�����ǻ���true��
	�ж�ǰһ���ַ��Ƿ�Ϊ'-'�����Ǹı�posi������posiΪfalse 
3��number�ļ���Ϊ number=number*10+(posi ? current : -current)
4������ÿ���������������ֵ��ַ����㣬���������ֽ�β�����Ļ��ټ��㣬��������ټ��� 
*/
#include <iostream>
#include <string> 
using namespace std;

int calResult(string &str)
{
	if(str.empty())
		return 0;
	int result=0;//�洢��ǰ�ۼӺ� 
	int number=0;//��ǰ�ռ���������  
	bool posi=true;//�ж����� 
	
	int current;//��ǰ������ַ���Ӧ������ 
	
	for(int i=0;i<str.length();++i){//�����ַ��� 
		current=str[i]-'0';//�õ���ǰ�ַ���Ӧ������ֵ 
		if(current<0 || current>9){//���������� 
			result+=number;//�Ƚ��� 
			number=0;//��number���� 
			if(str[i]=='-'){//1���ж��Ƿ�Ϊ��-�� 
				if(i-1>=0 && str[i-1]=='-')//3���ж�ǰһ���Ƿ�Ϊ'-' 
					posi=!posi;//���ǣ���ȡ�� 
				else
					posi=false;//4������Ϊfalse 
			}
			else	//2������posi����true 
				posi=true;
		}
		else
			number=number*10+(posi ? current : -current);//��ǰ�ռ������� 
	}
	result+=number;//������һ�Σ���ֹ�����ֽ�βû�н��� 
	
	return result;
}

int main()
{
	//���� 
	cout<<"�������ַ�����"<<endl; 
	string str;
	cin>>str;
	
	//������
	cout<<"������Ϊ��"<<calResult(str)<<endl; 
	return 0;
}
