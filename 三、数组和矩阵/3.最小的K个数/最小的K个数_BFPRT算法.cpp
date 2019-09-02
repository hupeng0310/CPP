/*
���⣺����n�����������������С��k�� 

һ��ⷨ������O(nlogn)����ά������Ϊk�����飨O(n*k)������ά��һ��k��Ԫ�صĶѣ�O(n*logk)�� 

�������BFPRT�㷨��O(n)�����

 
*/
#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
} 

//�������� 
void insertSort(int *a,int begin,int end)
{
	int i,j,t;
	for(i=begin+1;i<end;++i){
		if(a[i]<a[i-1]){
			t=a[i];
			for(j=i-1;j>=0 && a[j]>t;--j)
				a[j+1]=a[j];
			a[j+1]=t;
		}
	}
} 

//�õ���λ�� 
int getMedian(int *a,int begin,int end)
{
	insertSort(a,begin,end);//���� 
	int sum=end+begin;
	int mid=(sum/2)+(sum%2);//��λ��λ�ã���Ϊ������5��Ԫ��ʱ��ȡ����λ��������+sum%2 
	return a[mid];
}
int select(int *a,int begin,int end,int i);
//�õ���λ������λ�� 
int medianofMedians(int *a,int begin,int end)
{
	int num=end-begin+1;//�ܹ����ĸ��� 
	int offset=num%5==0 ? 0 : 1;//�������������5�ı�����ƫ����Ϊ0������Ϊ1 
	int len=num/5+offset;//Ҫ�����λ������ĳ��� 
	int mArr[len];
	
	for(int i=0;i<len;++i){//�������� 
		int beginI=begin+i*5;//ÿ���5������ʼλ�� 
		int endI=beginI+4;//����Ľ���λ�� 
		mArr[i]=getMedian(a,beginI,end>endI?endI:end);//������λ��<����Ľ���λ�ã���Ϊʵ�ʵĽ���λ�� 
	}
	
	return select(mArr,0,len-1,len/2);//����select������λ������λ��������mArr�е�len/2С���� *** 
}

//a�������ҵ���iС���� 
int select(int *a,int begin,int end,int i)
{
	if(begin==end)//�ݹ����1 
		return a[begin];
	
	int pivot=medianofMedians(a,begin,end);//�õ���λ������λ������Ϊ����Ԫ�� 
	
	//����һ�δ����൱��һ��partition�Ĺ��̣�����rangA��rangB��Ҫ���������� pivot��λ�������Դ˸��Ӽ��ٵݹ��� 
	int small=begin-1;
	int cur=begin;
	int big=end+1;
	while(cur<big){
		if(a[cur]<pivot)
			swap(a+(++small),a+(cur++));
		else if(a[cur]>pivot)
			swap(a+cur,a+(--big));
		else
			cur++; 
	}
	int rangA=small+1;//��������pivot����߽� 
	int rangB=big-1;//��������pivot���ұ߽� 
	//partition���� 
	
	if(i>=rangA && i<=rangB)//���i����ΪK����λ�����䣬��a[i]Ϊ��kС��Ԫ�� 
		return a[i];//�ݹ����2
	else if(i<rangA)//�ݹ�������� 
		return select(a,begin,rangA-1,i);
	else//�ݹ��ұ���������Ϊʲô����i,������i-rangB,��Ϊ����ʼ��ʹ�õ���a���飬iλ�û��ǵ�iС��Ԫ�� 
		return select(a,rangB+1,end,i);
}

//��õ�kС��Ԫ�� 
int getMinKthByBFPRT(int *a,int k,int len)
{
	int copyA[len];
	for(int i=0;i<len;++i){
		copyA[i]=a[i];
	}
	 
	return select(copyA,0,len-1,k-1);//����select����õ�KС���� 
} 

void getMinKNumsByRFPRT(int *a,int k,int len)
{
	if(k<1 || k>len)//������Ҫ�󣬷��� 
		return;
		
	int minKth=getMinKthByBFPRT(a,k,len);//�õ���kС���� 
	int res[k];
	int index=0;
	for(int i=0;i<len;++i)//�������飬���ֱȵ�kС��Ԫ�ؾͷ���res�����У���kС��Ԫ�ؿ����ж���� 
		if(a[i]<minKth)
			res[index++]=a[i];
	
	for(;index<k;++index)//��Ϊ��kС��Ԫ�ؿ����ж������������û����ȫk����������λ�ö���minKth 
		res[index]=minKth;
	
	for(int i=0;i<k;i++)//������ 
		cout<<res[i]<<" ";
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
	getMinKNumsByRFPRT(a,k,n);
	
	return 0;
}
