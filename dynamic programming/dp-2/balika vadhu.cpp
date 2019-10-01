#include <bits/stdc++.h>
using namespace std;

int lcsI(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	int** dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <=n ;i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j<= n; j++) {
			if (s1[m - i] == s2[n - j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}	else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int ans =  dp[m][n];
	// delete 2d array
	for (int i =0; i <=  m; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}



int fun(string s,string t,int k,int i,int j,int ***dp) {
  //base case
  if(i==s.size()||j==t.size()) {
    if(k==0)
      return 0;
    else
      return INT_MIN;
  }
  if(k==0)
    return 0;
  if(dp[i][j][k]!=-1)
    return dp[i][j][k];
  if(s[i]!=t[j])
 		dp[i][j][k]= max(fun(s,t,k,i+1,j,dp),fun(s,t,k,i,j+1,dp));
  else {
  int val1=fun(s,t,k-1,i+1,j+1,dp)+s[i];
  int val2=max(fun(s,t,k,i+1,j,dp),fun(s,t,k,i,j+1,dp));
  
  dp[i][j][k]= max(val1,val2);
  }
  return dp[i][j][k];
}

int main()
{
    
  int t;
  cin >> t;
  while(t--) {
    
    string s1,s2;
    cin >> s1 >> s2;
    int k;
    cin >> k;
    int val1=lcsI(s1,s2);
    if(val1<k)
      cout<<0<<endl;
    
    else {
      int ***dp=new int**[s1.size()+1];
      for(int i=0;i<s1.size()+1;i++) {
        dp[i]=new int*[s2.size()+1];
        for(int j=0;j<s2.size()+1;j++) {
          dp[i][j]=new int[k+1];
          for(int z=0;z<k+1;z++)
            dp[i][j][z]=-1;
        }
      }
      cout<<fun(s1,s2,k,0,0,dp)<<endl;
    }
    
    
    
  }
  
  return 0;
}
