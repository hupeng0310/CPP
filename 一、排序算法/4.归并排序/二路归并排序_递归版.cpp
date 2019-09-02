/* 
�ݹ�����ǽ������򼯺�һ��Ϊ����ֱ�����򼯺Ͼ�ʣ��һ��Ԫ��Ϊֹ��Ȼ�󲻶ϵĺϲ������ź��������
*/
#include <iostream>
using namespace std;

//�ϲ� 
void merge(int *a,int *b,int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;//iָ����߿�ʼ��ߣ�jָ���ұ߿�ʼ���꣬k��¼�洢�û��ϲ���b����λ�� 
	while(i<=mid&&j<=right){//i��jͬʱ��ʼɨ�� 
		if(a[i]>=a[j])//������߲��ִ����ұ߲��֣�j����ƣ�����������С��Ԫ�طŵ�b�����У� 
			b[k++]=a[j++];
		else//����i����� 
			b[k++]=a[i++];
	}
	while(i<=mid)//�п���һ���ȱ����꣬Ȼ����һ��ʣ��ļ�������b���� 
		b[k++]=a[i++];
	while(j<=right)//ͬ�� 
		b[k++]=a[j++];
	for(i=left;i<=right;i++)//���ｫ�ϲ���b���鸴�Ƶ�a�����У���ʵ������Ҳ���ԣ�b����洢�ľ����ź���� 
		a[i]=b[i];
}
//�鲢����-�ݹ� 
void mergeSort(int *a,int *b,int left,int right)
{
	int mid;
	if(left<right){
		mid=(left+right)/2;//�����е� 
		mergeSort(a,b,left,mid);//�ݹ黮������ 
		mergeSort(a,b,mid+1,right);//�ݹ黮���Ұ�� 
		merge(a,b,left,mid,right);//�ϲ������� 
	} 
}

int main()
{
	int n=0,a[100],b[100],data,i;
	//����
	cout<<"��������������֣���-1��β��"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//����
	mergeSort(a,b,0,n-1);
	//���
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	for(i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
	return 0;
} 
