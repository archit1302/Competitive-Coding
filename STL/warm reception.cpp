#include<bits/stdc++.h>
using namespace std;

int main() {

	unordered_map<int,int> a;
  int n;
  cin >> n;
  int arr1[n];
  int arr2[n];
          
  for(int i=0;i<n;i++) {
    cin >> arr1[i];
  }
  for(int i=0;i<n;i++) {
    cin >> arr2[i];
  }
  for(int i=0;i<n;i++) {
    
    for(int j=arr1[i];j<=arr2[i];j++) {
      a[j]++;
    }
  }
  int max=0;//loc=0;
  for(int i=0000;i<2400;i++) {
    if(a[i]>max) {
      max=a[i];
      //loc=a[i];
    }
  }
  cout << max;
  return 0;
}