#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
  ll row,col;
  cin >> row >> col;
  ll arr[row+1][col+1];
  ll dp[row+1][col+1];
  ll arr2[row+1];
  
  for(ll i=1;i<=row;i++) {
    for(ll j=1;j<=col;j++) 
      cin >> arr[i][j];
  }
  
  
  for(ll i=1;i<=col;i++)
    dp[1][i] = 1;
  
  for(ll i=2;i<=row;i++) {
    for(ll j=1;j<=col;j++) {
      
      if(arr[i][j]>=arr[i-1][j])
        dp[i][j]=dp[i-1][j];
      else
        dp[i][j] = i;  
      
    }
  }
  

    for(ll i=1;i<=row;i++) {
       ll mini = INT_MAX;
      for(ll j=1;j<=col;j++) {
        if(dp[i][j]<mini) {
          mini = dp[i][j];
        }      
      } 
      arr2[i]=mini;      
    }

    ll k;
    cin >> k;
    while(k--) {
      ll l,r;
      cin >> l >> r;
      
      
      if(arr2[r]<=l)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
     }
  
  
  
  
    return 0;
}
