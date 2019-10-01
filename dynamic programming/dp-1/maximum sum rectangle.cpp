#include <bits/stdc++.h>
using namespace std;

int kadane(int* temp, int* start, int* finish, int n) 
{ 
    int sum = 0, maxSum = INT_MIN, i; 
 
    *finish = -1; 
 
    int local_start = 0; 
  
    for (i = 0; i < n; ++i) 
    { 
        sum += temp[i]; 
        if (sum < 0) 
        { 
            sum = 0; 
            local_start = i+1; 
        } 
        else if (sum > maxSum) 
        { 
            maxSum = sum; 
            *start = local_start; 
            *finish = i; 
        } 
    } 
  
    if (*finish != -1) 
        return maxSum; 

    maxSum = temp[0]; 
    *start = *finish = 0; 
 
    for (i = 1; i < n; i++) 
    { 
        if (temp[i] > maxSum) 
        { 
            maxSum = temp[i]; 
            *start = *finish = i; 
        } 
    } 
    return maxSum; 
} 

void findMaxSum(int **arr,int rows,int col) 
{ 
    int maxSum = INT_MIN; 
  
    int left, right, i; 
    int temp[rows], sum, start, finish; 
 
    for (left = 0; left < col; ++left) 
    { 
        memset(temp, 0, sizeof(temp)); 
  
        for (right = left; right < col; ++right) 
        { 
            for (i = 0; i < rows; ++i) 
                temp[i] += arr[i][right]; 
  
            sum = kadane(temp, &start, &finish, rows); 
  
            if (sum > maxSum) 
            { 
                maxSum = sum; 
               
            } 
        } 
    } 
  cout << maxSum << endl;
}

int main()
{
  
  int rows,col;
  cin >> rows >> col;
  
  int** arr = new int*[rows];
  for(int i = 0; i < rows; i++)
       arr[i] = new int[col];
  
  for(int i=0;i<rows;i++) {
    for(int j=0;j<col;j++) 
      cin >> arr[i][j];
  }
  
  findMaxSum(arr,rows,col);
  
    return 0;
}
