#include <bits/stdc++.h>
using namespace std;

int magrid(int **input,int rows,int col) {
  
  int** dp = new int*[rows];
  for(int i = 0; i < rows; i++)
       dp[i] = new int[col];
  dp[rows-1][col-1] = 1;
                           ////////////// MY DOUBT IS PUTTING 1 IN THE CELL TOP AND LEFT OF THE LAST CELL{=1}
  
  for(int i=rows-2;i>=0;i--) {
    int x = dp[i+1][col-1] - input[i][col-1];
    if(x>0)
    dp[i][col-1] = dp[i+1][col-1] - input[i][col-1];
    else
      dp[i][col-1]=1;
  }
  
  for(int j=col-2;j>=0;j--) {
    int x =  dp[rows-1][j+1] - input[rows-1][j];
    if(x>0)
    dp[rows-1][j] = dp[rows-1][j+1] - input[rows-1][j];
    else
      dp[rows-1][j] = 1;
  }
  
  for(int i=rows-2;i>=0;i--) {
    for(int j=col-2;j>=0;j--) {
      int x =  min(dp[i+1][j],dp[i][j+1]) - input[i][j];
      if(x>0)
      dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - input[i][j];
      else
        dp[i][j] = 1;
    }
  }
  
  int ans = dp[0][0];
  //delete []dp;
  return ans;
  
  
}

int main()
{
  
  int t;
  cin >> t;
  
  while(t--) {
    int rows,col;
    cin >> rows >> col ;
    //int arr[rows][col];
    int** arr = new int*[rows];
  for(int i = 0; i < rows; i++)
       arr[i] = new int[col]; 
    
    for(int i=0;i<rows;i++) {
      for(int j=0;j<col;j++) 
        cin >> arr[i][j];
    }
    
    cout << magrid(arr,rows,col) << endl;
    
    
  }
  
    return 0;
}
