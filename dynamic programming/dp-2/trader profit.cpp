#include <bits/stdc++.h>
using namespace std;

int profit(int *arr,int k,int size,int i,int **dp) {
  
  if(i==size)
  return 0;
  
  if(k==0)
    return 0;
    
  if(dp[i][k]!=-1)
    return dp[i][k];
    
    if(k%2==0)      
  {
    
    int val1 = profit(arr,k,size,i+1,dp);
    int val2 = profit(arr,k-1,size,i+1,dp)-arr[i];
    
    dp[i][k]= max(val1,val2);
  }
        
   else{
    int val3 = profit(arr,k,size,i+1,dp);
    int val4 = profit(arr,k-1,size,i+1,dp)+arr[i];
    
    dp[i][k]= max(val3,val4);
   }
  
  return dp[i][k];
  
  
}


int main()
{
  
  int q;
  cin >> q;
  while(q--) {
    
    float k;
    int n;
    cin >> k >> n;
    int p = 2*k ;
    int *arr=new int[n];
    
    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++) {
      dp[i] = new int[p+1];
    for(int j=0;j<=2*k;j++)
      dp[i][j]=-1;    
    }
    
    for(int i=0;i<n;i++)
      cin >> arr[i];
    
    
   cout<< profit(arr,p,n,0,dp)<<endl;
    
    
    
  }
  
    return 0;
}
