include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long p = 256;
 #define mod 1000000007



ll dist(string s) {
  
 // unordered_map<char,int> m;
  vector<ll> v(p,-1);
  
  
  ll n = s.size();
  ll *dp=new ll[n+1];
  
  dp[0]=1;
  //m[s[0]]++;
  
  for(ll i=1;i<=n;i++) {
    
    dp[i]=(2*dp[i-1])%mod;
    
    if(v[s[i-1]]!=-1)
      dp[i]=(dp[i]-dp[v[s[i-1]]]+mod)%mod;
    
     v[s[i-1]] = (i-1); 
    
     // v[i] = dp[v[i-1]];
  }
  
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  while(n--) {
    
    string s;
    cin >> s;
    
    cout << dist(s) << endl;
    
  }
  
  
    return 0;
}

