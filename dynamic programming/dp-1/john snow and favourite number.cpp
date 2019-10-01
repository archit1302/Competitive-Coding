#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin >> n >> k >> x;
    int strengths[n];
    for(int i=0;i<n;i++)
        cin >> strengths[i];
    
    int arr[10001]={0};
    int copy_arr[10001]={0};
    for(int i=0;i<n;i++) {
        arr[strengths[i]]++;
        copy_arr[strengths[i]]++;
    }
    for(int i=0;i<k;i++){
        int num_entries = 0;
        for(int j=0 ; j<10001 ; j++){
            
            if(arr[j]== 0)
            continue;
            if(num_entries%2==0){
               int temp = (arr[j]+1)/2;
                    copy_arr[j] -= temp;//arr[j]/2;
                    copy_arr[j^x] += temp;//copy_arr[j^x] + (arr[j]/2);
                }
                else{
                        copy_arr[j] -= arr[j]/2;
                        copy_arr[j^x] = copy_arr[j^x] + (arr[j]/2);
                    }
                  
                num_entries += arr[j];
            }
      
        for(int i=0;i<10001;i++)
            arr[i] = copy_arr[i];
    }
    //MAXIMUM
    for(int i = 10000; i>=0;i--){
        if(arr[i] > 0){
            cout << i << " ";
            break;
        }
    }
    //MINIMUM
    for(int i = 0; i< 10001;i++){
        if(arr[i] > 0){
            cout << i;
            break;
        }
    }
    
    return 0;
}
