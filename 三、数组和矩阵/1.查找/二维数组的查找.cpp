/*
���⣺һ����ά���飬ÿ�д������ҵ�����ÿ�д������µ���������һ�������ж�������Ƿ����������

�����½ǿ�ʼ�ң������������ң�����С������ 
*/ 
#include <iostream>
using namespace std;

bool isExist(int a[][4],int rowCount,int colCount,int number)//��ά�������β�Ҳ������(*a)[4]����ά����ָ������ 
{
	
	int i,j;
	for(i=rowCount-1,j=0;i>=0 && j<colCount;){//�����½ǿ�ʼ 
		if(number>a[i][j])//���� 
			++j;
		else if(number<a[i][j])//���� 
			--i;
		else//�ҵ�������true 
			return true; 
	} 
	return false;
}

int main()
{
	//��ʼ��ά���� 
	int a[3][4]={{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}};
	int n,rowCount,colCount; 
	cout<<"��ά����Ϊ��"<<endl;
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j)
			cout<<a[i][j]<<" ";
		cout<<endl; 
	}
	//������������
	rowCount=sizeof(a)/sizeof(a[0]);//sizeof(a)Ϊ����Ԫ���ֽ�����sizeof(a[0])Ϊһ��Ԫ���ֽ��� 
	colCount=sizeof(a[0])/sizeof(int);
	
	cout<<endl<<"������һ����:"<<endl; 
	cin>>n;
	
	//��� 
	cout<<"���:"<<isExist(a,rowCount,colCount,n)<<endl;
	
	return 0;
}
