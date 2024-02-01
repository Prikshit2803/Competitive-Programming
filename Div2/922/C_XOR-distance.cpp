//1st condition :a>b
//Binary propertu if kh bit set > sum of (0 to k-1th) bit set 
//Intuition : Minimize a and maximize b , such that a>b and minimum difference
//start from left and find first bit that is set in a but not in b (it exists as a>b), set flag true from here on every bit set in 1 but not in b
//we take x value =0 as it makes a bit 0 and b bit = 1 so that difference is minimized
//also set x bit 1 only if it is less than k/r as 1<=x<=r

//link :https://www.youtube.com/watch?v=amDG9gnk-6k
#include<iostream>
using namespace std;
#define int long long
 
 
 
 
 
 int find(int a,int b,int k){
    bool flag=false;
    
    int x=0;
    
    for(int i=63;i>=0;i--){
        int abit = ((a>>i) & 1);
        int bbit = ((b>>i) & 1);
        
        if(abit==1 && bbit==0){
            if(!flag){
                flag=true;
            }
            else{
                int nx=x+(1ll<<i);
                if(nx<=k)
                x+=(1ll<<i);
                else
                x+=0;
            }
        }
        
    }
    
    a^=x;
    b^=x;
    
    return abs(a-b);
}
 
 
void solve(){
   
   int a,b,k;
   
   cin>>a>>b>>k;
   
   if(a<b)
   swap(a,b);
   
   int ans=find(a,b,k);
   cout<<ans<<endl;
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
//https://www.youtube.com/watch?v=ptehfjBEOrU

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
