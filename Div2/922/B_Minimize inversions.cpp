#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long

 
 

 
 
 
void solve(){
    int n;
        cin>>n;
        
        vector<int> a(n);
        map<int,int> mp;
        
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        int b;
        
        for(int i=0;i<n;i++){
            cin>>b;
            mp[a[i]]=b;
        }
        
        sort(a.begin(),a.end());
        
         for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        
        for(int i=0;i<n;i++){
            cout<<mp[a[i]]<<" ";
        }
        
        cout<<endl;
        
        
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
