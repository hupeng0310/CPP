/*
���������������ַ��������ַ���ǰ�������ַ��ƶ����ַ������� 

��������ÿ�ν���һ���ַ��ƶ���ĩβ������m�μ���ǰmλƽ�Ƶ����� 
*/ 
#include <iostream>
using namespace std;

//ʵ��ÿ�ν���ǰ���һ����ĸ�Ƶ���� 
void lowShiftOne(char *s,int len) 
{
	int i;
	char temp=s[0];//��¼��һ���ַ� 
	for(i=1;i<len;++i)//������ַ�ǰ��һλ 
		s[i-1]=s[i];
	s[len-1]=temp;//����¼�ĵ�һ���ַ��������λ�� 
}
//��ǰm����ĸƽ�Ƶ����� 
void lowRotateString(char *s,int len,int m)
{
	while(m--)//�ƶ�m�� 
		lowShiftOne(s,len);
}

int main()
{
	char s[100],data;
	int n=0,i;
	//�����ַ��� 
	cout<<"���������ת�ַ�������0��β��"<<endl;
	while(cin>>data && data!='0'){
		s[n++]=data;
	}
	//��ת 
	lowRotateString(s,n,3);
	//���
	cout<<"n="<<n<<endl; 
	for(i=0;i<n;++i)
		cout<<s[i]<<" ";
	cout<<endl;
	return 0;
}
 
