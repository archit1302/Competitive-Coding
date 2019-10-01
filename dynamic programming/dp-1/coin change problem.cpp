int coin_change(int n, int* d, int numD, int** output) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	if (numD == 0) {
		return 0;
	}
	if (output[n][numD] > -1) {
		return output[n][numD];
	}
	int first = coin_change(n - d[0], d, numD,output);
	int second = coin_change(n, d + 1, numD - 1,output);
	output[n][numD] = first + second;
	return first + second;
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){

   int** output = new int*[value+1];
for(int i = 0; i < value+1; ++i)
    output[i] = new int[numDenominations+1];
  
  
  for(int i=0;i<value+1;i++) {
    for(int j=0;j<numDenominations+1;j++) 
      output[i][j]=-1;
  }
  
  return coin_change(value,denominations,numDenominations,output);
  

}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


