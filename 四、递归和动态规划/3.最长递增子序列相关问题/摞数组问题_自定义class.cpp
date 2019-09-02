/*
���⣺ ����һ�� N*2 �Ķ�ά���飬������һ������Ԫ�飬����[[a1,b1],[a2,b2],[a3,b3]]��
		�涨��һ�������Ѷ�Ԫ��׷��ڶ�Ԫ�����ϣ����е� a ֵ����������е� a ֵ�����е� b
		ֵ����������е� b ֵ������ڶ�ά����������ѡ���Ԫ�飬���ʶ�Ԫ��������������
		������
		���磺[[5,4],[6,4],[6,7],[2,3]], ������������� 3 ����[2,3] => [5,4] => [6,7]

O��NlogN���ⷨ������������������е��㷨ԭ��****�� 
1������ά���鰴�յ�1��Ԫ�ص�������
2���ڵ�һ��Ԫ����ȵ�ǰ���£�����ά���鰴�յ�2��Ԫ�صݼ�����
3��������ά���飬���յ�2��Ԫ��ʹ�õ��������е��㷨���ɣ���Ϊ��һ��Ԫ���Ѿ������ˣ� 

Ϊʲô�����ǿ��Եģ�
��Ϊ��X��ȵ�ÿһ�������ѡһ��������ΪY�ǵ������Ե�����������ÿһ�����Ҳ��ѡһ�� 

 
˵������������һ����Dot����������Ԫ�ض�Ӧ��ά�����е�ֵ ����leetcode��ͨ���� 
*/ 
#include <stdio.h>
using namespace std;
class Dot{//����Dot�࣬�洢��ά���� 
	public:
		int x;
		int y;
};
//����X��С����������� 
void quickSortByX(Dot dots[],int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	int k=dots[low].x;
	Dot temp=dots[low];
	while(i<j){
		while(i<j && dots[j].x>=k)
			--j;
		dots[i]=dots[j];
		while(i<j && dots[i].x<=k)
			++i;
		dots[j]=dots[i];
	}
	dots[i]=temp;
	quickSortByX(dots,low,i-1);
	quickSortByX(dots,i+1,high);
}
//����Y�Ӵ�С�������� 
void quickSortByY(Dot dots[],int low,int high)
{
	if(low>=high)
		return;
	int i=low;
	int j=high;
	int k=dots[low].y;
	Dot temp=dots[low];
	while(i<j){
		while(i<j && dots[j].y<=k)
			--j;
		dots[i]=dots[j];
		while(i<j && dots[i].y>=k)
			++i;
		dots[j]=dots[i];
	}
	dots[i]=temp;
	quickSortByY(dots,low,i-1);
	quickSortByY(dots,i+1,high);
}
//�õ����յ�����������X��ȵ�ǰ���°�Y���� 
void sort(Dot dots[],int len){
	int indexLow=0;//���ڼ�¼X�������µĿ�ʼλ�� 
	int indexHigh=0;//����λ�� 
	for(int i=1;i<=len;++i){//����***��������i<=len,��Ϊ��������ڶ��������һ����ȵĻ����Ͳ���ִ�������ˣ� 
		if(dots[i].x==dots[i-1].x)//
			indexHigh=i;
		else{
			quickSortByY(dots,indexLow,indexHigh);
			indexLow=i;
		}
	}
}

//ʹ������������е�ԭ���㷨������Y�ļ��ɣ������뿴����������е�dp�Ż����֣� 
int maxEnvelope(Dot *dots,int len)
{
	quickSortByX(dots,0,len-1);
	sort(dots,len);
	int end[len];
	int dp[len];
	end[0]=dots[0].y;
	int right=0;
	int l=0;
	int m=0;
	int r=0;
	for(int i=0;i<len;++i){
		l=0;
		r=right;
		while(l<=r){
			m=(l+r)/2;
			if(end[m]<dots[i].y)
				l=m+1;
			else
				r=m-1;
		}
		end[l]=dots[i].y;
		right=right>l?right:l;
	}
	return right+1;
}

int main()
{
	//int a[8][2]={{1,2},{2,3},{3,4},{1,1},{5,7},{5,3},{2,8},{6,9}};
	//int a[][2]={1,3,3,5,6,7,6,8,8,4,9,5};
	int a[][2]={1,15,7,18,7,6,7,100,2,200,17,30,17,45,3,5,7,8,3,6,3,10,7,20,17,3,17,45};
	int len=sizeof(a)/sizeof(a[0]);
	Dot dots[len];
	for(int i=0;i<len;++i){
		dots[i].x=a[i][0];
		dots[i].y=a[i][1];
	}
	printf("���������ĸ�����%d",maxEnvelope(dots,len));

	return 0;
} 
