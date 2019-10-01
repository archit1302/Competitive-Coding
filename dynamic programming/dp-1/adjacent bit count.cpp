#include <bits/stdc++.h>
#define m 1000000007
#define MAX 1000 
using namespace std;
typedef long long ll;

ll ways(int dp[][MAX][2], int n, int k, int ci, int ajb, int lastBit) 
{ 
  
  if(n==1) {
    if(k==0)
      return 1;
    return 0;
  }
  if(k<0)
    return 0;
    
    if (ci == n) {          ///////////ci = current index ; ajb = adjacent bit;  
   
        if (ajb == k) 
            return 1; 
        return 0; 
    } 
  
    if (dp[ci][ajb][lastBit] != -1) { 
  
        return dp[ci][ajb][lastBit]; 
    } 
  
    ll noOfWays = 0; 
    
    if (lastBit == 1) { 
        
        noOfWays = (noOfWays+ways(dp, n, k, ci + 1,ajb + 1, 1))%m; 
        noOfWays = (noOfWays+ways(dp, n, k, ci + 1,ajb, 0))%m; 
    } 
  
    else  { 
        noOfWays =(noOfWays+ ways(dp, n, k,  ci + 1,ajb, 1))%m; 
  
        noOfWays =(noOfWays+ways(dp, n, k, ci + 1,ajb, 0))%m; 
    } 
  
    dp[ci][ajb][lastBit] = noOfWays; 
  
    return noOfWays%m; 
} 


int main()
{
  
  ll p;
  cin >> p;
  while(p--) {
    int dp[MAX][MAX][2]; 
    memset(dp, -1, sizeof(dp));
    ll a,n,k;
    cin >> a >> n >> k;
    
    ll totalWays = (ways(dp, n, k, 1, 0, 1) + ways(dp, n, k, 1, 0, 0))%m;
    cout << a << " " << totalWays << endl;
    //cout << a << " " << countStrings(n,k) << endl;
    
  }
  
    return 0;
}
