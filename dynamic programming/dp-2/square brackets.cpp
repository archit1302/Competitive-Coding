#include <bits/stdc++.h>
using namespace std;

int brackets(int i,unordered_set<int> &s,int size,int x,int **dp) {
  
  if(size==i)
    return 1;
  if(dp[i][x]!=-1)
    return dp[i][x];
  
  if(x==0)
    dp[i][x]= brackets(i+1,s,size,x+1,dp);
  
  
  
  else if(x==size-i){
   
    if(s.count(i)>0)
      dp[i][x]= 0;
    else   
    dp[i][x]= brackets(i+1,s,size,x-1,dp);
  }
  else if(s.count(i)>0)
    dp[i][x]= brackets(i+1,s,size,x+1,dp);
  else
  dp[i][x]= brackets(i+1,s,size,x+1,dp)+brackets(i+1,s,size,x-1,dp);

return  dp[i][x];
  
}


int main()
{
  
  int t;
  cin >> t;
  
  while(t--) {
    int n,k;
    cin >> n >> k;
    
    int **dp = new int*[2*n+1];
    for(int i=0;i<=2*n;i++) {
      dp[i] = new int[2*n+1];
      for(int j=0;j<=2*n;j++) 
        dp[i][j] = -1;
    }
    
    unordered_set<int> s;
    for(int i=0;i<k;i++) {
      
      int x;
      cin >> x;
      s.insert(x-1);
     }
    
    int z = brackets(0,s,2*n,0,dp); 
    cout << z << endl;
      
  }
  
  
    return 0;
}
