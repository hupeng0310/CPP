/*
���������еĸ���
- ���������ַ��������ͷβ�ַ�����ȣ����ַ����Ļ��������и����͵���ȥ��ͷ���ַ����Ļ��������и���+ȥ��β���ַ����Ļ��������и���-ȥ��ͷβ���ַ����Ļ��������и�����
- ���ͷβ�ַ���ȣ����ַ����Ļ��������и����͵���ȥ��ͷ���ַ����Ļ��������и���+ȥ��β���ַ����Ļ��������и���+1��
- ��dp[i][j]��ʾ��i����j���ַ��������������еĳ��ȣ�i<=j������״̬ת�Ʒ���Ϊ��
  - dp[i][j]=dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] �� if��s[i]��=s[j]��
  - dp[i][j]=dp[i+1][j] + dp[i][j-1] +1 �� if ��s[i]==s[j]�� 
*/

#include <bits/stdc++.h>
using namespace std;
#define N 59


void coutDP(vector<vector<int> > dp, int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}


//����һ�����仯����dp
int dfs(string s, vector<vector<int> > dp, int left, int right)
{
	if(left>right)
		return 0;
	if(left==right){
		dp[left][right] = 1;
		return dp[left][right];
	}
	if(dp[left][right]!=0){
		return dp[left][right];
	}
	dp[left][right] = dfs(s,dp,left+1,right)+dfs(s,dp,left,right-1)-dfs(s,dp,left+1,right-1);
	if(s[left]==s[right]){
		dp[left][right] += dfs(s,dp,left+1,right-1)+1;
	}
	return dp[left][right];
}


// ��������ֱ��dp 
int allPalindrome(string s)
{
	int len = s.length();
	vector<vector<int> > dp(N, vector<int>(N));
	for(int j=0;j<len;j++){
		dp[j][j] = 1;
		for(int i=j-1; i>=0; i--){
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if(s[i]==s[j])
				dp[i][j] += dp[i+1][j-1]+1;
		}
	}
	//coutDP(dp, len);
	return dp[0][len-1];
} 


int main()
{
	string s;
	vector<vector<int> > dp(N, vector<int>(N)); 
	while(cin>>s){
		cout<<allPalindrome(s)<<endl; 
		cout<<dfs(s,dp,0,s.length()-1)<<endl;
	}
	return 0; 
} 
