/*
1��������������i��j������ʼ��ʱ��i=0��j=n-1��
2���Ե�һ������Ԫ����Ϊ�ؼ����ݣ���ֵ��key����key=a[0]��
3����j��ʼ��ǰ���������ɺ�ʼ��ǰ����(j--)���ҵ���һ��С��key��ֵa[j]����a[j]��a[i]������
4����i��ʼ�������������ǰ��ʼ�������(i++)���ҵ���һ������key��a[i]����a[i]��a[j]������
5���ظ���3��4����ֱ��i=j��
*/ 
#include <iostream>
using namespace std;


void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp; 
} 

void quickSort(int *a,int left,int right)
{
	if(left>=right)//�ݹ���� 
		return;
	int i=left;
	int j=right; //i,j�൱����ͷָ�룬�ƶ� 
  	int key=a[left];//��һ��Ԫ����Ϊ���� 
	while(i<j){
		while(i<j&&key<=a[j])
			j--;//ǰ�� 
		a[i]=a[j];//���ȵ�һ��С���Ƶ��Ͷ�,���ﻻΪ����������Ҳ�ǿ��Եģ�Ϊʲôֱ�ӽ�a[j]��ֵ����a[i]Ҳ�ǿ��Եģ���Ϊkey=a[left]������˵�ֵ��¼���ˣ�����a[i]���Ա����ǣ���Ҳ��Ϊʲô�Ӻ���ǰ������j--�����Ϳ��Խ�С��key�ķ���a[i]�� 
		//swap(&a[i],&a[j]);
		while(i<j&&key>=a[i])
			i++;//���� 
		a[j]=a[i];//���ȵ�һ������Ƶ��߶�
		//swap(&a[i],&a[j]);
	}
	a[i]=key;
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
}

int partition(int *a, int left, int right){
	int p = left;
	for(int i=left; i<=right; i++){
		if(a[i]<a[left]){
			p++;
			swap(a+p, a+i);
		}
	}
	swap(a+left, a+p);
	return p;
}

void quickSort2(int* a, int left, int right){
	if(left>=right)
		return;
	int p = partition(a, left, right);
	quickSort2(a, left, p-1);
	quickSort2(a, p+1, right);
}

int main()
{
	int n=0,data,a[100],i;
	//����
	cout<<"��������������֣���-1��β"<<endl;
	while(cin>>data&&data!=-1){
		a[n++]=data;
	} 
	//����
	quickSort2(a,0,n-1);//n��Ԫ�أ�ĩλΪa[n-1]
	//���
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
 
