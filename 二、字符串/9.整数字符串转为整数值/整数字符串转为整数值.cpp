/*
���⣺�������ַ���תΪ����ֵ
	Ҫ�󣺣�1��023 ==>����0
		  ��2��-0123==>����0
		  ��3��Խ��==>����0
		  ��4���������ַ�==>����0
		   
��Ҫ��Խ��ǰ�жϳ������Ƿ���Լ����������Խ��ͱ����ˡ�** 

1���ж��ַ����Ƿ�Ϸ�
2��ͳһ�����������������Ͳ���Ҫ������ˣ���Ϊ����������ֵ��������1��������posi���أ�'0'-str[i]��Ϊ��Ӧ�ĸ����ˡ� 
3��bool��posi��¼������result��¼�����minq=INT_MIN/10,minr=INT_MIN%10,�����������ж��Ƿ�Խ��
	����Խ�粻��Ҫ���������ˡ�����ж��أ������ǰresult<minq����Ϊ����������ģ�����res==minq ����minr>��ǰ��������֣���Ӻ�Ҳ�϶�Խ�� 
4���ж�һ������posiΪtrue����������result=INT_MIN������0 
5������ж�����posiΪfalse���򷵻�result����Ϊ����������ģ������򷵻�true 
*/
#include <iostream>
//#include <limits.h>
using namespace std;
#define INT_MIN (-2147483647 - 1)//�궨�壬����int����Сֵ��limits.hͷ�ļ���Ҳ���ж���ģ� 

//�ж��ַ����Ƿ�Ϸ� 
bool isValide(string &str)
{
	if(str[0]!='-' && (str[0]<'0' || str[0]>'9'))//��λΪ�����ַ� 
		return false;
	
	if(str[0]=='-' && (str.length()==1 || str[1]=='0'))//��λΪ-,���ǳ���Ϊ1��ڶ�λΪ0 
		return false;
	
	if(str[0]=='0' && str.length()>1)//��λΪ0�ҳ��ȴ���1 
		return false;
	
	for(int i=1;i<str.length();++i)//�������ֻ�ܱ����ж��� 
		if(str[i]<'0' || str[i]>'9')
			return false;
	
	return true; 
}

int convert(string &str)
{
	if(str.empty() || str=="")//Ϊ�գ�����0 
		return 0;
		
	if(!isValide(str))//�ж��Ƿ�Ϸ� 
		return 0;
		
	bool posi=str[0]=='-' ? false : true;//posi��¼������falseΪ�� 
	int minq=INT_MIN/10;//����Խ��ǰλ������ 
	int minr=INT_MIN%10;//����Խ��ǰλ��������໹�ܼӶ��� 
	int result=0;//�洢��� 
	int current=0;//��ǰ������ 
	
	for(int i=posi ? 0 : 1;i<str.length();++i){//�������ӷ�-λ�ÿ�ʼ���� 
		current='0'-str[i];//�õ���ǰ����Ӧ�ĸ��� 
		if((result<minq) || (result==minq && current<minr))//�жϵ�ǰ�Ƿ�Խ�� 
			return 0;
		result=result*10+current;//�޸Ľ�� 
	}
	if(posi && result==INT_MIN)//�ж��Ƿ����תΪ���� 
		return false;
	
	return posi ? -result:result;//����posi���ؽ�� 
	
} 

int main()
{
	//����
	cout<<"�������ַ�����"<<endl;
	string str;
	cin>>str;
	
	//������
	cout<<"���Ϊ:"<<convert(str)<<endl; 
	
	return 0;
} 
