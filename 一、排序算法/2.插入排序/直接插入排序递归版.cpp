#include <iostream>
using namespace std;

void insertSortRecursion(int *a,int index,int len)
{
	if(index>=len)//�ݹ���� 
		return;
	int key=a[index];//��¼��ǰ�������Ԫ�� 
	int i;
	for(i=index-1;i>=0&&key<a[i];i--){//Ԫ�غ��� 
		a[i+1]=a[i];
	}
	a[i+1]=key;//��Ԫ�ز��뵽��Ӧλ�� 
	insertSortRecursion(a,index+1,len);//�ݹ鴦��֮��� 
}

int main()
{
	int n=0,a[100],i,data;
	//����
	cout<<"��������������֣���-1��β��"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//����
	insertSortRecursion(a,1,n);
	//���
	cout<<"n="<<n<<endl; 
	for(i=0;i<n;i++){
		cout<<a[i]<<" "; 
	} 
	cout<<endl;
	return 0;
} 
