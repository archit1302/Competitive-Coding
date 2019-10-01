#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

 
  ll n,m;
  cin >> n >> m;
  ll start[n+1];
  ll end[n+1];
  ll arr[n+1];
  ll arr2[n+1];
  ll arr3[n+1];
  
  memset(start,0,sizeof(start));
  memset(end,0,sizeof(end));
  memset(arr,0,sizeof(arr));
  memset(arr2,0,sizeof(arr2));
  memset(arr3,0,sizeof(arr3));
  
  
  while(m--) {
    ll l,r;
    cin >> l >> r;
    start[l]++;
    end[r]++;    
    
  }
  
  arr[1]=start[1];
  
  for(ll i=2;i<=n;i++)     
    arr[i]=arr[i-1]+start[i]-end[i-1];
 
  //EXACT
  for(ll i=1;i<=n;i++) {
    arr2[arr[i]]++;
  }
 
  //ATLEAST
  arr3[n]=arr2[n]; 
  for(ll i=n-1;i>=1;i--) {
    arr3[i]=arr2[i]+arr3[i+1];
  }
 
  ll x;
  cin >> x;
  while(x--) {
    
    ll q;
    cin >> q;
    
    cout << arr3[q] << endl;    
  }
  
   return 0;
}
