/*
������Ծ��
���⣺ 
-  һ���Ǹ����飬��ǰ�����ʾ�ܹ��������������ӿ�ʼ��ĩβ����С��Ծ����
- eg: A = [2,3,1,1,4] , ��Ҫ2������ 
������
- dp��H[i]��ʾindex��0��i���������� 
*/
#include <bits/stdc++.h>
using namespace std;
#define N 1000

int minJump(vector<int> data)
{
	int len = data.size();
	vector<int> dp(len, 0);  //��ʼ��len��0ֵ��vector
	for(int i=0;i<len-1;i++){
		for(int j=1;j<=data[i];j++){
			if(dp[i+j]>dp[i]+1 || dp[i+j]==0)
				dp[i+j] = dp[i]+1;
		}
	}	
	return dp[len-1];
}

int main()
{
	int n,d;
	cin>>n;
	vector<int> data;
	while(n--){
		cin>>d;
		data.push_back(d);
	}
	cout<<minJump(data)<<endl;
	return 0;
} 
