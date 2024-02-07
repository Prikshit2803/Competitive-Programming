//Code
void asquare()
{
    ll n;
    cin>>n;
    vll arr(n);
    cin>>arr;
    vll freq(26,0);
    string ans="";
    for(int i=0;i<n;i++){
        int x=arr[i];
        for(char ch='a';ch<='z';ch++){
            int indx=ch-'a';
            if(freq[indx]==x){
                ans+=ch;
                freq[indx]++;
                break;
            }
        }
    }
    cout<<ans<<"\n";
}
//Main
int main()
{
    Code By Asquare
    ll t;
    cin>>t;
    fl(i,t)
    {
        asquare();
    }
    return 0;
}
//End
