//https://www.youtube.com/watch?v=ZfqWLxBG-Ow


#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int hi=0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        hi += a[i];
    }
    vector<int> pre(n+2);
    for (int i = 0; i <= n; i++) {
        pre[i+1] = pre[i]+a[i];
    }
    vector<int> dp(n+3);

    function<bool(int)> check = [&](int mid)->bool {
        dp[0]=0;
        deque<int>q;
        for (int i = 0; i <= n; i++) {
            while (q.size()>0 && dp[q.back()]>= dp[i]){
                q.pop_back();
            }
            q.push_back(i);
            while (pre[i] - pre[q.front()]>mid){
                q.pop_front();
            }
            dp[i+1] = dp[q.front()]+a[i];
        }
        return dp[n+1]<=mid;
    };

    int low = 1, ans = hi;
    while (low<=hi){
        int mid = low + (hi-low)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
