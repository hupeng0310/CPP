/*
���⣺�������������������λ�������ܸ���Ϊ������������λ������Ϊż��������(x1+x2)/2 
		eg��nums1 = [1, 2]
			nums2 = [3, 4]
			��λ��Ϊ(2 + 3)/2 = 2.5 
		Leetcode 4. Median of Two Sorted Arrays��Accepted�� 
˼·������㷨˵������������ǿ�� 

ʱ�临�Ӷȣ�O��log(min(m,n))�� 
*/ 
#include <stdio.h>
#include <limits.h>

int min(int a,int b)
{
	return a > b ? b : a;	
}
int max(int a,int b)
{
	return a > b ? a : b;
}

double findMedianSortedArrays(int* a, int n, int* b, int m) 
{
    if(n>m)	//���ֽ�С������ 
		return  findMedianSortedArrays(b,m,a,n);
	
	int l1;		//a�и�����ߣ���������ֵ 
	int l2;		//b�и�����ߣ���������ֵ 
	int r1;		//a�и����ұߣ����ұ����ֵ 
	int r2;		//b�и����ұߣ����ұ����ֵ 
	int c1;		//a�и���λ�� 
	int c2; 	//b�и���λ�� 
	int low=0;	//a�п�ʼ 
	int high=2*n;	//a����������#��Ľ�β 
	
	while(low<=high){	//���ֽ϶̵����鿪ʼ 
		c1=(low+high)>>1;	//a�и��λ�� 
		c2=n+m-c1;			//b�и��λ�� 
		l1=(c1==0) ? INT_MIN : a[(c1-1)>>1];//a�и������ 
		r1=(c1==2*n) ? INT_MAX : a[c1>>1];	//a�и����ұ� 
		l2=(c2==0) ? INT_MIN : b[(c2-1)>>1];//b�и������ 
		r2=(c2==2*m) ? INT_MAX : b[c2>>1];	//b�и����ұ� 
		
		if(l1>r2)		//����left����
			high=c1-1;
		else if(l2>r1)	//����right���� 
			low=c1+1;
		else			//�ҵ��������l1<r2,��l2<r1 
			break;
	}
	
	return (max(l1,l2)+min(r1,r2))/2.0;//������������������ֵ���ұ���������Сֵ��1/2 
}

int main()
{
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(int);
	int b[]={3,4,5,6};
	int m=sizeof(b)/sizeof(int);
	
	printf("��λ��Ϊ��%f",findMedianSortedArrays(a,n,b,m));
	
	return 0;
} 
