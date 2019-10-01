#include<bits/stdc++.h>
using namespace std;


bool compare(pair<string,pair<int,int>> p1,pair<string,pair<int,int>> p2) {
  
  if(p1.second.first==p2.second.first)
    return p1.second.second<p2.second.second;
  
  return p1.second.first > p2.second.first ;
}

int main()
{
  int n;
  cin >> n;
  
  pair<string,pair<int,int>> p[n];
  
  for(int i=0;i<n;i++) {
    
    string s;
    cin>>s;
    int a,b,c;
    cin>>a>>b>>c;
    int sum=a+b+c;
    
    p[i].first=s;
    p[i].second.first=sum;
    p[i].second.second=i;
    
  }
  
    sort(p,p+n,compare);
  
  for(int i=0;i<n;i++) {
    cout << (i+1) << " " << p[i].first << endl;
  }
  
    
	return 0;
}
