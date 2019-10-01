#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> a;
  
    string s,out="";
    vector<string> vect;
    getline(cin,s);
    int l = s.length();
  
    int c=0;
  
   for(int i=0;i<=l;i++) {
     if(s[i]!='\0'&&s[i]!='\n'&&s[i]!=' ') {
       out=out+s[i];
     }
     else {
       vect.push_back(out);// out;
       a[vect[c++]]++;
       out="";
     }
       
   }
  

  int d=0;
  for(int i=0;i<c;i++) {
    if(a[vect[i]]==1) {
       d++;
    }
    if(a[vect[i]]>1) {
      cout << vect[i] << " " << a[vect[i]] << endl;
      a[vect[i]]=0;
     
    }
  }
  
  if(c==d)
    cout << "-1" ;
  
  
	return 0;
}
