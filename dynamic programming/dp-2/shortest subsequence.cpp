#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int solve(string S,string V)
{
	// Write your code here.

  int i,j,prev,n=S.size(),m=V.size();
  int dp[n+1][m+1],next[n+1][m+1];
  
  for(int i=0;i<n;i++) {
    prev=-1;
    for(int j=0;j<m;j++) {
      if(S[i]==V[j])
        prev = j;
      next[i+1][j+1] = prev;
    }
  }

  for(int i=1;i<=n;i++) 
    dp[i][0] = 1;
  for(int i=0;i<=m;i++)
    dp[0][i] = INF;
  
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      if(next[i][j]==-1)
        dp[i][j]=1;
      else
        dp[i][j]=min(dp[i-1][j],1+dp[i-1][next[i][j]]);
    }
  }

return dp[n][m];
}

int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}