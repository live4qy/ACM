#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int ppow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}
    return ans;
}
int n,k;
void solve(){
    cin>>n>>k;
    //n进制数的地k大
    int ans=0;
    for(int i=0;i<=30;i++){
        if(k>>i&1){
            ans=(ans+ppow(n,i,mod))%mod;
        }
    }
    cout<<ans<<endl;
}
void Main(){
    #ifdef MULTI_CASE
    int T;cin>>T;while(T--)
    #endif
    solve();
}
void Init(){
    #ifdef SYNC_OFF
    ios::sync_with_stdio(0);cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
}
signed main(){
    Init();
    Main();
    return 0;
}