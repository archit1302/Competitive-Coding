
#include<bits/stdc++.h>
using namespace std;

int knapsack(int *wt, int *val, int n, int W) 
{ 
    // matrix to store final result 
    int mat[2][W+1]; 
    memset(mat, 0, sizeof(mat)); 
  
    // iterate through all items 
    int i = 0; 
    while (i < n) // one by one traverse each element 
    { 
        int j = 0; // traverse all wieghts j <= W 
  
        // if i is odd that mean till now we have odd 
        // number of elements so we store result in 1th 
        // indexed row 
        if (i%2!=0) 
        { 
            while (++j <= W) // check for each value 
            { 
                if (wt[i] <= j) // include element 
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]], 
                                    mat[0][j] ); 
                else           // exclude element 
                    mat[1][j] = mat[0][j]; 
            } 
  
        } 
  
        // if i is even that mean till now we have even number 
        // of elements so we store result in 0th indexed row 
        else
        { 
            while(++j <= W) 
            { 
                if (wt[i] <= j) 
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
                                     mat[1][j]); 
                else
                    mat[0][j] = mat[1][j]; 
            } 
        } 
        i++; 
    } 
  
    // Return mat[0][W] if n is odd, else mat[1][W] 
    return (n%2 != 0)? mat[0][W] : mat[1][W]; 
} 



int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}
