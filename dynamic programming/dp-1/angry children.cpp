#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
  ll n , k ;
  cin >> n >> k;
  ll arr[n+1];
  ll arr2[n+1];
  int c=0;
  
  for(ll i=1;i<=n;i++)
    cin >> arr[i];
  
  sort(arr+1,arr+n+1);
  
  ll sum=0;
  ll target=0;
  
  for(ll i=1;i<k;i++) {
    sum+=arr[i];
    target = target + (i*arr[i+1]) - sum;    
  }
   sum+=arr[k];
  arr2[c++]=target;
  ll newtarget=target;
  for(ll i=k+1;i<=n;i++) {
    sum = sum - arr[i-k];
    newtarget = newtarget - (2*sum) + ((k-1)*arr[i-k]) + ((k-1)*arr[i]);
    sum = sum + arr[i];
    arr2[c++] = newtarget;
    
  }
  ll mini=arr2[0];
  for(int i=0;i<c;i++) {
     // cout<<arr2[0]<<endl;
    if(arr2[i]<mini)
      mini = arr2[i];
  }
  
  cout << mini << endl;
  
    return 0;
}
