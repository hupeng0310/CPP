/*
���⣺��һ���Ǹ����������������ΪK����󳤶�

˼·��1����������ָ��left��right����ʼ��ָ�����鿪ʼ������left��right֮��ĺͣ� 
	  2����������ֹ������rightָ���ƶ������
	  3��sum��ǰ�ͣ����sum==k,��right-left+1��Ϊ������ĳ��ȣ���¼���ֵ��ͬʱsumҪ��ȥ��ߵ�ֵ����ָ��leftǰ��
	  				  ���sum <k, ��ָ��rightǰ�ƣ�ͬʱ��Ҫ�ж�һ���Ƿ�Խ�磨��Խ�磬ֱ��break����Ȼ��sum+a[right]
					  ���sum >k, sum��ȥ��ָ��ָ���ֵ��ͬʱǰ�� 
*/
#include <stdio.h>

int longestSubArrayK(int *a,int k,int len)
{
	int left=0;//��ָ�� 
	int right=0;//��ָ�� 
	int sum=a[0];//�洢�ۼӺ�
	int maxLen=0;//��¼��󳤶� 
	while(right<len){//��������ָ��right�Ƶ�ĩβ���� 
		if(sum==k){//��¼���ֵ��sum��ȥleftָ���ֵ��Ȼ��leftǰ�� 
			maxLen=maxLen>(right-left+1) ? maxLen : (right-left+1);
			sum-=a[left];
			++left;
		}
		else if(sum<k){//��ָ��ǰ�ƣ�ͬʱ�ж�һ��ǰ�ƺ��Ƿ�Խ�磬Ȼ������ۼ� 
			++right;
			if(right>=len)
				break;
			sum+=a[right]; 
		}
		else{//sum��ȥleftָ���ֵ��Ȼ��leftǰ��
			sum-=a[left];
			++left;
		}
	}
	
	return maxLen;
}

int main()
{
	int a[]={2,1,4,5,1,1,1,3,4,2,3,4,1};
	int len=sizeof(a)/sizeof(int);
	int k=3; 
	printf("��Ϊ %d ��������鳤��Ϊ��%d\n",k,longestSubArrayK(a,k,len)); 
	
	return 0;
}
