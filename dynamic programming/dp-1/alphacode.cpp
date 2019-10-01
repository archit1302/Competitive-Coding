#include <bits/stdc++.h>
#define m 1000000007
using namespace std;

long long num_codes_i(long long * input, long long size) {
	long long* output = new long long[size + 1];
	output[0] = 1;
	output[1] = 1;

	for (long long i = 2; i <= size; i++) {
		//output[i] = output[i - 1];
      
      output[i] = 0; 
      
      if(input[i-1]==0)
        output[i]=0;
  
        if (input[i-1] > 0) 
            output[i] = output[i-1]; 
      
     
    if (input[i-2] == 1 || (input[i-2] == 2 && input[i-1] < 7) ) 
            output[i] = (output[i] +output[i-2])%m; 
    } 
    
    
	long long ans = output[size];
	delete [] output;
	return ans;
}


int main()
{
 string s;
  cin >> s;
  int t = s[0]-'0';
  while(t) {
    
    long long n = s.length();
    long long input[n];
    
    for(long long i=0;i<n;i++) {
      input[i]=s[i]-'0';
    }
    
   long long ans = num_codes_i(input,n);
    
    cout << ans%m << endl;
    
    
    
  //string s;
  cin >> s;
    t=s[0]-'0';
    
    
  }
  
  return 0;
}
