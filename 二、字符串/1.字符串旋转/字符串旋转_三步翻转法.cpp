/*
���η�ת����
���磺abcdef==>defabc
1��abc==>cba
2��def==>fed
3��cbafed==>defabc
*/ 
#include <iostream>
using namespace std;

//��ת 
void reverseString(char *s,int low,int high)
{
	char temp;
	while(low<high){
		temp=s[low];
		s[low++]=s[high];
		s[high--]=temp;
	}
}
//�������η�ת 
void lowRotateString(char *s,int len,int m)
{
	m%=len;//����m�ƶ�����len���ȼ���m%len 
	reverseString(s,0,m-1);
	reverseString(s,m,len-1);
	reverseString(s,0,len-1);
}

int main()
{
	char s[100],data;
	int n=0,i;
	//����
	cout<<"���������ת�ַ�������0��β��"<<endl;
	while(cin>>data && data!='0'){
		s[n++]=data;
	}
	//��ת
	lowRotateString(s,n,3);
	//���
	cout<<"n="<<n<<endl;
	for(i=0;i<n;++i){
		cout<<s[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
