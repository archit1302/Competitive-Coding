#include <bits/stdc++.h>
using namespace std;

pair<int,int> partyREC(int *fee,int *fun, int n , int bud,pair<int,int> **dp) {
  
  if(n==0) {
 return make_pair(bud,0); 
  }
  if(bud==0)
    return make_pair(bud,0);
  
  if(dp[n][bud].second!=-1)
    return dp[n][bud];
  
  if(fee[n-1]<=bud){
    pair<int,int> val1 = partyREC(fee,fun,n-1,bud,dp);
    pair<int,int> val2 = partyREC(fee,fun,n-1,bud-fee[n-1],dp);
    
    val2.second+=fun[n-1];
    
    if(val1.second==val2.second) {
      if(val1.first>val2.first)
        dp[n][bud]=val1;
      else
        dp[n][bud]=val2;
    }
   else{ 
    if(val1.second>val2.second)
      dp[n][bud]=val1;
     else
     dp[n][bud]=val2;
   }
  }
  else
   dp[n][bud]=partyREC(fee,fun,n-1,bud,dp);

  
  return dp[n][bud];
}



int main()
{
  
  while(true) {
    
    int budget,n;
    cin>>budget>>n;
    if(budget==0&&n==0)
      break;
    
    int fee[n];
    int fun[n];
    
    for(int i=0;i<n;i++) {
      cin >> fee[i] >> fun[i];
    }
    
    pair<int,int>**dp=new pair<int,int>*[n+1];
    for(int i=0;i<=n;i++) {
      dp[i]=new pair<int,int>[budget+1];
      for(int j=0;j<=budget;j++)
        dp[i][j].second=-1;
    }
    
    pair<int,int> ans = partyREC(fee,fun,n,budget,dp);
    cout << budget-ans.first <<' '<<ans.second<< endl;
  }
    return 0;
}
