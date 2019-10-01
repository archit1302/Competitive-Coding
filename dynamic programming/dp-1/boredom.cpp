int freq[1002],dp[1002];
int solve(int n,vector<int>A){
  
    for(int i=0;i<A.size();i++)
      freq[A[i]]++;
    
    dp[1]=freq[1];
  
    for(int i=2;i<=1000;i++) {
      dp[i] = max(dp[i-1],dp[i-2]+i*freq[i]);
    }
  return dp[1000];
}

int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}