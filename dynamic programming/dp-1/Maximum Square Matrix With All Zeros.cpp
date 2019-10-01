#include<bits/stdc++.h>
using namespace std;


int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
   
    int i , j ; 
    int** output = new int*[row];
    for(int i = 0; i < row; i++)
        output[i] = new int[col];   
  
  int maxi=1;
  
  for(i=0;i<row;i++) {
    output[i][0] = arr[i][0] ;    
  }
  
  for(j=0;j<col;j++) {
    output[0][j] = arr[0][j];
  }
  
  for(i=1;i<row;i++) {
    
    for(j=1;j<col;j++) {
      
     if(arr[i][j]==0) {
       
       output[i][j] = min(output[i][j-1] , min(output[i-1][j] , output[i-1][j-1] ) ) + 1 ;
       
  
      if(output[i][j] > maxi )
        maxi = output[i][j] ;
     }
       
    }
    
  }
  
  return maxi;
  
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}