
#include <bits/stdc++.h>
using namespace std;

//x->difference  n->no. of elements

int fun(int *A,int *C,int n,int x,int **ans) {
  if(n==0)
    return 0;
  if(ans[n][x]!=-1)
    return ans[n][x];
  
  int ans1;
  if(x==0)
    ans1=fun(A+1,C+1,n-1,x+1,ans)+A[0];
  else if(x==n)
    ans1=fun(A+1,C+1,n-1,x-1,ans)+C[0];
  else
  ans1=min(fun(A+1,C+1,n-1,x-1,ans)+C[0],fun(A+1,C+1,n-1,x+1,ans)+A[0]);
  
  ans[n][x]=ans1;
  return ans1;
}

int main()
{
  int n;
  cin>>n;
  int *A=new int[n];
  int *C=new int[n];
  for(int i=0;i<n;i++) 
    cin>>C[i]>>A[i];
  int **ans=new int*[n+1];
  for(int i=0;i<n+1;i++) {
    ans[i]=new int[(n/2)+1];
    for(int j=0;j<(n/2)+1;j++)
      ans[i][j]=-1;
  }
  
  cout<<fun(A,C,n,0,ans)<<endl;
    return 0;
}