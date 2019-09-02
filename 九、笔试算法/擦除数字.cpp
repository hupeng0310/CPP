/*
��Ŀ������ 
- ��� Steph ���д�ںڰ��ϵ����� 816����ôÿ�β���ǰ�ڰ��ϵ�����816��81��8�����ռ������еĽ���� 816 + 81 + 8 = 905�� 
  - �������һ���� S (1 <= S <= 10^18)��Steph ��֪���ܷ��ҵ�һ���� x����д�� x �ںڰ��Ϻ�ִ�в������̺�������еõ��Ľ���� S�� 
  - ������ܵõ������ -1������ܵõ��������С�� x��
������
- 816Ϊ������������������֣�����һλ8���Ǽ���3�Σ�һ������ 8*(100+1+1)+1*(10+1)+6*1=905
- ���Ծ�����111*X+11*Y+Z=S ��ö��X��Y��Z���� 

*/

#include <bits/stdc++.h>
using namespace std;
#define N 10000

// �������(1,9)�������9
// �������(2,9)�������99
// �������(3,9)�������999
long count(int times, int num)
{
	long p = 1;
	long sum = 0;
	while(times--){
		sum += num*p; 
		p *= 10;
	}
	return sum;
}

long solution(long num)
{
	int len = 0;
	long temp = num;
	while(temp){
		len++;
		temp /= 10;
	}
	int res[len];
	
	//Ѱ��0-9���ʵ����� 
	int i,j;
	for(i=len-1; i>=0; i--){  //ѭ�����ٴ� 
		long sum = 0;
		for(j=9;j>=0;j--){
			long tmp = count(i+1, j);
			if(sum+tmp<=num){
				sum += tmp;
				break;
			}
		}
		res[i] = j;
		num -= sum;
	}
	if(num != 0)
		return -1;
	
	//������
	long p = 1;
	long result = 0;
	for(int i=0;i<len;i++){
		result += res[i] * p;
		p *= 10;
	} 
	return result;
}
 
int main()
{
	long num;
	while(cin>>num){
		cout<<solution(num)<<endl; 
	} 
	return 0;
}
