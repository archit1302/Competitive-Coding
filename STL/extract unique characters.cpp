#include<bits/stdc++.h>
using namespace std;


char* uniqueChar(char *str){
    // Write your code here
  unordered_map<char,int> a;
  int l=strlen(str);
  
  char* output;
  
  for(int i=0;i<l;i++) {
    a[str[i]]++;
  }
  int c=0;
  for(int i=0;i<l;i++) {
    if(a[str[i]]>0) {
      output[c++]=str[i];
      a[str[i]]=0;
    }
  }
    return output;
  

}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
