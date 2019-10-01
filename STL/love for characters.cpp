#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
  cin >> n;
  int c=0,d=0,e=0;
  string s;
  cin >> s;
  for(int i=0;i<n;i++) {
    if(s[i]=='a')
      c++;
    else if(s[i]=='s')
      d++;
    else if(s[i]=='p')
      e++;
      
      
  }
  cout << c << " " << d << " " << e;
  return 0;
}
