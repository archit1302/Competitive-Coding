int longestBitonicSubarray(int *input, int n) {
		
	
      int inc[n]; 
      int dec[n]; 
      int i, max; 
  
      inc[0] = 1; 
      dec[n-1] = 1;
  
      for (i = 1; i < n; i++) {
       inc[i] = 1;//(arr[i] >= arr[i-1])? inc[i-1] + 1: 1;
      for(int j=i-1;j>=0;j--) {
        if(input[j]>=input[i])
          continue;
        int ans = inc[j] + 1;
        if(ans>inc[i])
          inc[i]=ans;
      }
      
      }
  
  
      for (i = n-2; i >= 0; i--) {
       dec[i] = 1;// (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;
      for(int j=i+1;j<n;j++) {
        if(input[j]>=input[i])
          continue;
        int ans = dec[j] + 1;
        if(ans>dec[i])
          dec[i]=ans;
      }
            
      }
        max = inc[0] + dec[0] - 1; 
        for (i = 1; i < n; i++) 
              if (inc[i] + dec[i] - 1 > max) 
                    max = inc[i] + dec[i] - 1; 
  
    return max;  
  
     	
}


#include<iostream>
using namespace std;
#include "solution.h"

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}


