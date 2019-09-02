/*
���⣺����n�����������������С��k�� 

һ��ⷨ������O(nlogn)����ά������Ϊk�����飨O(n*k)�� 
����
1�����ô���ѣ�
2������k��n������С�ڶѶ����򽫶Ѷ�Ԫ���滻�������µ���Ϊ�󶥶� 

0(n*logk)
*/
#include <iostream>
using namespace std;

//������ 
void adjustHeap(int *a,int i,int len)
{
	int temp=a[i];//��¼Ҫ�����Ľڵ� 
	int child=2*i+1;//�ڵ���������� 
	while(child<len){
		if(child+1<len&&a[child]<a[child+1]){//�ж������Ӵ����Һ��Ӵ� 
			child++;//�����Һ��Ӵ���λ���Һ��� 
		}
		if(a[i]<a[child]){//���ǽڵ�С�ڽϴ�ĺ��ӣ��򽫺������� 
			a[i]=a[child];
			i=child;//�������ýڵ����꣬Ϊ����ĵ�����׼�� 
			child=2*i+1;//�������������� 
		}
		else//���ǽڵ�����亢�ӽڵ㣬ֱ���˳�ѭ�� 
			break;
		a[i]=temp;//���ڵ���ڵ����ĺ��ӽڵ��� 
	} 
} 
//��ʼ���� 
void initHeap(int *a,int k)
{
	for(int i=(k-2)/2;i>=0;--i){//�к��ӵĽڵ�����λ����(k-2)/2����ǰ��,��(Ԫ���±�-1)/2Ϊ�丸�ڵ㣬����Ϊ(k-2)/2�� 
		adjustHeap(a,i,k); 
	}
} 
//����С��K���� 
void getTopK(int *a,int k,int len)
{
	initHeap(a,k);//����ǰK��Ԫ�صĶ� 
	for(int i=k;i<len;++i){//���������Ԫ�� 
		if(a[i]<a[0]){//�����бȶѶ�(a[0])С��Ԫ�� 
			a[0]=a[i];//���Ѷ��滻 
			adjustHeap(a,0,k); //������ 
		}
	}
	
	for(int i=0;i<k;++i)//���ǰK��Ԫ�أ���Ϊ��� 
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	//���� 
	int *a,n=0,data,k;
	cout<<"���������ݣ���-1��β����"<<endl; 
	while(cin>>data && data!=-1){
		a[n++]=data;
	} 
	cout<<"������Kֵ��"<<endl;
	cin>>k;
	
	//������
	cout<<"��С��"<<k<<"�����ֱ�Ϊ��";
	getTopK(a,k,n);
	return 0;
} 
