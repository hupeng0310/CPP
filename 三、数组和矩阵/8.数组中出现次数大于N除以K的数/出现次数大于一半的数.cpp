/*
���⣺�����г��ִ�������һ�����
		leetcode169. Majority Element

˼·��1������ѡ�����ܳ���һ�������Ȼ���ٱ���һ���жϼ���
		�����Ǵ��ڴ���һ����������໥����������ͬ�������ʣ��ļ�Ϊ����� 
	  2��count��������ʼֵ0����res���洢���������������countΪ0��������resΪ��ǰ��
	  	ͬʱcount++�����������ǰ��������res���������count--������count++
      3��Ȼ�����һ��ͳ��res���ֵĴ��� ����Ϊ�п����������ǽ�����������ˣ�������һ����ȷ�� 
*/ 
#include <stdio.h>

void majorityNumber(int *a,int len)
{
	if(len<1)
		return;
	
	int count=0;//��¼������ǰ�����ִ��� 
	int res;	//��¼���ܽ�� 
	for(int i=0;i<len;++i){//���� 
		if(count==0){//���countΪ0��������resΪ��ǰ����ͬʱcount=1 
			res=a[i];
			count=1;
		}
		else if(res!=a[i])//�����������ȣ��������count-- 
			--count;
		else
			++count;//��ȣ�count++ 
	}
	//������Ϊcount�����ͻ�����Ϊ1������--���Ϊ0���ٴα��������ֻ�����Ϊ1,����count����С��0 
	
	//������Ϊ�ٱ���һ���ж��Ƿ����һ�루��Ϊ�п����������ǽ�����������ˣ�������һ����ȷ�� 
	count=0;
	for(int i=0;i<len;++i)
		if(a[i]==res)
			++count;
	if(count>len/2)
		printf("%d\n",res);
	else
		printf("�����ڴ�������һ�����"); 
}

int main()
{
	int a[]={3,4,2,5,1,2,2,3,4,2,2,1,2,2,2,2};
	int len=sizeof(a)/sizeof(int);
	
	majorityNumber(a,len); 
	
	return 0;
} 
