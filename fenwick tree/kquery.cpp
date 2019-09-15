#include <bits/stdc++.h>
using namespace std;

struct element{
  int value , idx;
}arr[30001];

struct event{
  int left , right , value , index;
}query[200000];


int bit[30001];

bool compare2(event a , event b){
 
  return a.value > b.value;
}
bool compare(element a , element b){
  return a.value > b.value;
}

int qvalue(int index){
  
  int ans = 0;
  for(;index>0 ; index-=index&(-index)){
    ans+=bit[index];
  }
  return ans;
}

void update(int index, int n){
  for(; index <= n ; index+=index & (-index)){
    bit[index]++;
  }
}
int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
  cin>>n;
  for(int i = 1;i<=n ; i++){
    cin>>arr[i].value;
    arr[i].idx = i;
  }
  sort(arr+1 , arr+n+1 , compare);
  int q;
  cin>>q;
  for(int i = 0 ; i < q ; i++){
    cin>>query[i].left>>query[i].right>>query[i].value;
    query[i].index = i;
  }
  sort(query , query+q ,compare2);
  int z=1;
  int ans[q];
  for(int i = 0 ; i < q ; i++){
    while(query[i].value < arr[z].value){
      update(arr[z].idx , n);
      z++;
      
    }
    ans[query[i].index] = qvalue(query[i].right) - qvalue(query[i].left-1); 
    
  }
  for(int i = 0 ; i < q ; i++){
    cout<<ans[i]<<endl;
  }
  
  return 0;
}