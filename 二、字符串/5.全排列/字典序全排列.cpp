/*
���⣺��֪�ַ�������ַ��ǻ�����ͬ�ģ�����������ϣ�����ab�������aa��ab��ba��bb�������ֵ������� 

*/
#include <iostream>
using namespace std;

int count=0;//ȫ�ֱ�����ͳ�����и��� 

void notSimpleAllPermutation(char *result,char *s,int len,int resPos)
{
	int i;
	if(resPos>=len)//�������λ�õ���󣬾�����ַ��� 
		cout<<(++count)<<":"<<result<<endl;
	else{
		for(i=0;i<len;++i){//���� 
			result[resPos]=s[i];//result���ڴ洢��� 
			notSimpleAllPermutation(result,s,len,resPos+1);
		}
	}
}

int main()
{
	//���� 
	char *s,data,result[100];
	int n=0;
	cout<<"�������ַ�����0��β��"<<endl;
	while(cin>>data && data!='0'){
		s[n++]=data;
	}
	
	//������
	notSimpleAllPermutation(result,s,n,0); 
	return 0;
}
