#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int nbst(int n,long long *arr)
{   
    if(n==0||n==1)
    {
      return 1;  
    }
    if(arr[n]!=0)
    {
        return arr[n];
    }
   long long sum=0;
    for(int k=0;k<n;k++)
    { int temp=(int)(nbst(k,arr)*nbst(n-k-1,arr))%1000000007;
      sum= (sum + temp)%1000000007;
 
    }
    sum=sum%1000000007;
    arr[n]=sum;
    return sum;
 
}
    int countBST( int n)
{
    long long arr[n+1]={};
    return nbst(n,arr);
 
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
