/*
1����ȡһ��С��n������d1��Ϊ��һ��������ͨ��ϣ������Ϊ{N/2, (N/2)/2, ..., 1}��NΪԪ�ظ����������ļ���ȫ����¼���顣���о���Ϊd1�ı����ļ�¼����ͬһ������,�ڸ����ڽ���ֱ�Ӳ�������
2��ȡ�ڶ�������d2<d1�ظ������ķ��������ֱ����ȡ������dt=1��(dt< ��<d2<d1)�������м�¼����ͬһ���н���ֱ�Ӳ�������Ϊֹ��
*/ 

#include <iostream>
using namespace std;
 
void swapNum(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void shellSort(int *a,int len)
{
	if(len<=1||a==NULL)
		return;
	int div,i,j;
	for(div=len/2;div>=1;div/=2){//ϣ�������������� 
		for(i=div;i<len;i++){//i����ÿ���������������� 
			for(j=i;(j-div>=0)&&(a[j]<a[j-div])&&j>=0;j-=div){//�ض������������Ǻ���ı�ǰ���С���򽻻�,�м��ж�������Ҫ�ж�j-div>=0����Ϊֻ��j>=0������j-div����Խ�� 
				swapNum(&a[j],&a[j-div]);
				//swapNum(a+j,a+j-div);//����Ҳ�ǿ��Եģ�a�Ǵ���������׵�ַ��+j��ʾƫ��j��λ�ã���Ϊa[j]�ĵ�ַ 
			}
		}
	}
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
	shellSort(a,n); 
	//���
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
	return 0;
} 
