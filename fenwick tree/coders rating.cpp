#include<bits/stdc++.h>
using namespace std;

class coder{
	public:
	int x , y , index;
};

bool compare(coder A , coder B){
    if(A.x == B.x){
    	  return A.y < B.y;
    }
    return A.x < B.x;
}
int query(int value , int* BIT){
	int count = 0;
	 for(; value >0 ; value -= (value&(-value))){
  			count+= BIT[value];
	 }
	 return count;
}
void update(int value , int* BIT){
	     for(;value<= 100000 ; value += ((value)&(-value))){
	     	  BIT[value]++;
	     }
}

int main(){
	  int n;
	  cin >> n;
	  coder* arr = new coder[n];
	  for(int i = 0 ; i < n ; i++){
	  	  cin >> arr[i].x >> arr[i].y;
	  	  arr[i].index = i;
	  }
	  sort(arr , arr+ n , compare);
	  int* BIT = new int[100001]();
       int * ans = new int[n];
       for(int i = 0 ; i < n ;){
       	  int endIndex = i;
       	  while(endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y){
       	  	    endIndex++;
       	  }
       	    //query
       	  for(int j = i ; j < endIndex ; j++){
       	  	 ans[arr[j].index] = query(arr[j].y , BIT);
              // update rating
          }
           for(int j = i ; j < endIndex ; j++){
            update(arr[j].y , BIT);
              
       	  }
           i = endIndex;
          
  			
       }
    for(int i = 0 ; i < n ; i++){
           cout<<ans[i]<<endl;
    }

}