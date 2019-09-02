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

˵������leetcode��ͨ��
*/ 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//����һ���ȽϷ�����stl�Դ�������Ը����ƶ��Ĺ������� 
static bool judgeFirst(const pair<int,int> a, const pair<int,int> b) 
{
	if(a.first==b.first)//��X��ȵ������£���Y�Ӵ�С 
		return a.second>b.second;
	else return a.first<b.first;//���ڰ�X��С���� 
}


int maxEnvelopes(vector<pair<int, int> >& envelopes) 
{
    int len=envelopes.size();
    if(len<1)
        return 0;
    sort(envelopes.begin(),envelopes.end(),judgeFirst);//����stl�������㷨 
  	//����������е�O��NlogN���Ľⷨ���� 
	int end[len];
	end[0]=envelopes[0].second;
	int right=0;
	int l=0;
	int m=0;
	int r=0;
	for(int i=0;i<len;++i){
		l=0;
		r=right;
		while(l<=r){
			m=(l+r)/2;
			if(end[m]<envelopes[i].second)
				l=m+1;
			else
				r=m-1;
		}
		end[l]=envelopes[i].second;
		right=right>l?right:l;
	}
	return right+1;
}


int main()
{
	vector<pair<int, int> > list;
	list.push_back(make_pair<int,int>(1,3)); 
	list.push_back(make_pair<int,int>(3,5)); 
	list.push_back(make_pair<int,int>(6,7)); 
	list.push_back(make_pair<int,int>(6,8)); 
	list.push_back(make_pair<int,int>(8,4)); 
	list.push_back(make_pair<int,int>(9,5)); 
	printf("���������ĸ�����%d\n",maxEnvelopes(list));
	return 0;
}
