/*
1.��ʼʱ��a[0]�Գ�1����������������Ϊa[1..n-1]����i=1
2.��a[i]���뵱ǰ��������a[0��i-1]���γ�a[0��i]���������䡣
3.i++���ظ��ڶ���ֱ��i==n-1��������ɡ�
*/ 

#include <iostream>
using namespace std;

void StraightInsertSort(int *a,int len)
{
	int i,j,temp;
	for(i=1;i<len;i++){
		if(a[i]<a[i-1]){
			temp=a[i];//��¼Ҫ��������� 
			for(j=i-1;j>=0&&a[j]>temp;j--){//Ԫ�غ��� 
				a[j+1]=a[j];
			} 
			a[j+1]=temp;//�����Ӧ��λ�� 
		}
	}
}

int main()
{
	int n=0,a[100],data,i;
	//����
	cout<<"��������������֣���-1��β��"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//����
	StraightInsertSort(a,n);
	//���
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
} 
