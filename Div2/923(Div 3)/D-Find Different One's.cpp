#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long
 
 
 
 
 
 
 
void solve(){
        int n;
        cin>>n;
        
        vector<int> arr;
        
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        
        vector<int> diff; //stores index that have different elements
        
        for(int i=0;i<n-1;i++){
            if(arr[i]!=arr[i+1]){
                diff.push_back(i);
            }
        }
        
        int q;
        cin>>q;
        
        while(q--){
            int l,r;
            
            cin>>l>>r;
            
            l=l-1;
            r=r-1; //0-based indexing
            
            int lb=lower_bound(diff.begin(),diff.end(),l)-diff.begin();
            
            if(lb<diff.size() && diff[lb]<r){
                cout<<diff[lb]+1<<" "<<diff[lb]+2<<endl;
            }
            else{
                cout<<-1<<" "<<-1<<endl;
            }
            
            
        }
}
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
 
 
    int t=1;
    cin>>t;
    while(t--){
         solve();
    }
 
 
    return 0;
}
