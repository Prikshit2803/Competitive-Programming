#include <bits/stdc++.h>

using namespace std;

#define ll long long int 

void solve(ll ii,ll tt){ 
    
    ll a,b,r; cin >> a >> b >> r;
 
    if(b > a) swap(a,b);
 
    ll maxbit = -1;
 
    
 
    ll start = 0;
 
    ll x = 0,y = 0,ok = 0;
 
    for(int j = 60; j >= 0; j--){
        ll abit = 0,bbit = 0;
        if((a & (1ll << j))) abit = 1;
        if((b & (1ll << j))) bbit = 1;
 
        if(abit == bbit && (r & (1ll << j))) ok = 1;
 
        if(abit == bbit) continue;
 
        if(start == 0){
            start = 1;
            x += (1ll << j);
            if((r & (1ll << j))) ok = 1;
           
        }else{
            if(abit == 0 && bbit == 1) {
                y += (1ll << j);
                if((r & (1ll << j))) ok = 1;
                
            }
            else {
                if((r & (1ll << j)) || ok) y += (1ll << j);
                else {
                    x += (1ll << j);
                    if((r & (1ll << j))) ok = 1;
                }
                
 
            }
        }
        
    }
 
    // debug(x)
    // debug(y)
 
    cout << x - y << endl;
 
} 
 
 
 
 

int main(){
    
    // pre();
    ll t=1;
    cin>>t;
 
 
 
 
    
 
 
    //cout<<setprecision(3);
    for(int i=1; i<=t; i++){
        // cout<<"Case "<<i<<": ";
        
       solve(i,t);
    }
    
    return 0;
}
