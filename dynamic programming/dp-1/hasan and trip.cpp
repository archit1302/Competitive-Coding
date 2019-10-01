#include<bits/stdc++.h>
#define N 3005
using namespace std;

long long x[3030];
long long y[3030];
long long f[3030];
int n;
long double dp[3030];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>f[i];
	}
	dp[1]=f[1];
	for(int i=2;i<=n;i++){
		dp[i]=-1ll<<60;
		for(int j=1;j<i;j++){
			dp[i]=max(dp[i], dp[j]- sqrt((long double) ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]))));
		}
		dp[i]+=f[i];
	}
	cout<<fixed;
	cout.precision(6);
	cout<<dp[n]<<endl;
}

