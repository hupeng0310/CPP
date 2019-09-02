/**
problem�� n������m������k������������ɫ��ͬ��������ϸ��� 
solution1: ���һ������Ҫn 
           ���һ������Ҫm
           ���һ������Ҫk
solution2: ֱ�ӵݹ�ʱ�临�Ӷ���ָ�����ģ���ΪһЩ����ظ����㣬 ����ʹ�������ݴ���           
		    
**/ 

#include <iostream>
#include <memory.h> 
using namespace std;
#define MAX 100
long long dp[MAX][MAX][MAX][3];

////solution1 
//long long countWays(long long n, long long m, long long k, long long last){   // last������Ҫ�����ĸ���0����n, 1����m, 2����k 
//	if(n<0 || m<0 || k<0)   
//		return 0;
//	if(n==1 && m==0 && k==0 && last==0)         // ��Ҫn, ��n==1������Ϊ0, ֻ��һ������ 
//		return 1;
//	if(n==0 && m==1 && k==0 && last==1)         // ͬ�� 
//		return 1;
//	if(n==0 && m==0 && k==1 && last==2)
//		return 1;
//	
//	if(last==0)                                //��Ҫn����ʣ��Ϊn-1, m, k, ��Ҫ����1�� 2���֮�� 
//		return countWays(n-1, m, k, 1) + countWays(n-1, m, k, 2);
//	if(last==1) 
//        return countWays(n, m-1, k, 0) + countWays(n, m-1, k, 2); 
//    if(last==2) 
//        return countWays(n, m, k-1, 0) + countWays(n, m, k-1, 1); 	
//}

//solution2
long long countWays(long long n, long long m, long long k, long long last){   // last������Ҫ�����ĸ���0����n, 1����m, 2����k 
	if(n<0 || m<0 || k<0)   
		return 0;
	if(n==1 && m==0 && k==0 && last==0)         // ��Ҫn, ��n==1������Ϊ0, ֻ��һ������ 
		return 1L;
	if(n==0 && m==1 && k==0 && last==1)         // ͬ�� 
		return 1L;
	if(n==0 && m==0 && k==1 && last==2)
		return 1L;
	
	if(dp[n][m][k][last] != -1)
		return 	dp[n][m][k][last];
	
	if(last==0)                                //��Ҫn����ʣ��Ϊn-1, m, k, ��Ҫ����1�� 2���֮�� 
		dp[n][m][k][last] = countWays(n-1, m, k, 1) + countWays(n-1, m, k, 2);
	if(last==1) 
        dp[n][m][k][last] = countWays(n, m-1, k, 0) + countWays(n, m-1, k, 2); 
    if(last==2) 
        dp[n][m][k][last] = countWays(n, m, k-1, 0) + countWays(n, m, k-1, 1); 	
	return dp[n][m][k][last]; 
}



long long countAll(long long n, long long m, long long k){
	memset(dp, -1L, sizeof(dp));
	return countWays(n, m, k, 0) +
	       countWays(n, m, k, 1) +
	       countWays(n, m, k, 2);
}

int main(){
	long long n, m, k;
	cin>>n>>m>>k;
	cout<< countAll(n, m, k)<<endl;
	
	return 0; 
} 
