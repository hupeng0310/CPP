/*
����������� 
- ���������ַ��������ͷβ�ַ���ͬ����ô�ַ�����������е���ȥ����β���ַ�����������м�����β��
- �����β�ַ���ͬ����������е���ȥ��ͷ���ַ�����������к�ȥ��β���ַ�����������еĽϴ��ߡ�
- ���ַ���Ϊstr������Ϊn��p[i][j]��ʾ��i����j���ַ���������еĸ�����i<=j������
  - ״̬��ʼ������dp[i][i]=1 ��i=0��n-1�� 
  - ״̬ת�Ʒ��̣�dp[i][j]=dp[i+1][j-1] + 2  if��str[i]==str[j]��
                  dp[i][j]=max(dp[i+1][j],dp[i][j-1])  if ��str[i]!=str[j]��
*/


#include <bits/stdc++.h>
using namespace std;
#define N 100

//����һ����������dp 
int dfs(string s, vector<vector<int> > dp, int left, int right)
{
	if(left>right)
		return 0;;
	if(left==right){
		dp[left][right] = 1;
		return 1;
	}
	dp[left][right] = max(dfs(s, dp, left+1, right), dfs(s, dp, left, right-1));
	if(s[left]==s[right]){
		dp[left][right] = dfs(s, dp, left+1, right-1) + 2;
	}
	return dp[left][right];
}

//������: ֱ��dp 
int longestPalindrom(string s)
{
	int len = s.length();
    vector<vector<int> > dp(N, vector<int>(N));
	for(int j=0;j<len;j++){
		dp[j][j]=1;
		for(int i=j-1;i>=0;i--){
			dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			if(s[i]==s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}
		}
	}	
	return dp[0][len-1];
}

int main()
{
	string s;
	vector<vector<int> > dp(N, vector<int>(N));
	while(cin>>s){
		cout<<dfs(s,dp, 0,s.length()-1)<<endl; 
		cout<<longestPalindrom(s)<<endl;
	}
	return 0;
} 
