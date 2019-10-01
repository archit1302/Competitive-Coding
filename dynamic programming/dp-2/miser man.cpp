#include <bits/stdc++.h>
using namespace std;


int fun(int **arr,int i,int j,int n,int m,int **dp) {
  if(i==n)
    return 0;
  
  if(dp[i][j]!=-1)
    return dp[i][j];
  
  if(j==0)
    dp[i][j]= arr[i][j]+min(fun(arr,i+1,j+1,n,m,dp),fun(arr,i+1,j,n,m,dp));
  else if(j==m-1)
    dp[i][j]= arr[i][j]+min(fun(arr,i+1,j-1,n,m,dp),fun(arr,i+1,j,n,m,dp));
  else
  dp[i][j]= arr[i][j]+min(min(fun(arr,i+1,j-1,n,m,dp),fun(arr,i+1,j+1,n,m,dp)),fun(arr,i+1,j,n,m,dp));

  return dp[i][j];
}

int main()
{
  
  int n,m;
  cin >> n >> m;
  int **arr=new int*[n];
  for(int i=0;i<n;i++) {
    arr[i] = new int[m];
    for(int j=0;j<m;j++) {
      cin >> arr[i][j];
    }
  }
  int **dp=new int*[n+1];
  for(int i=0;i<=n;i++) {
    dp[i]=new int[m+1];
    for(int j=0;j<=m;j++)
      dp[i][j]=-1;
  }
  
  
  int mini=INT_MAX;
  for(int i=0;i<m;i++) {
  	int temp=fun(arr,0,i,n,m,dp);
    if(temp<mini)
      mini=temp;
  }
  
  
cout << mini<<endl;  
  
    return 0;
}
