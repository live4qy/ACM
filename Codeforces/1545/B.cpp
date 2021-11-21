#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
const int mod=998244353;
// const int mod=1e9+7;
const int maxm=2e6+5;
char s[maxm];
int n;
int fac[maxm],inv[maxm];
int ppow(int a,int b,int mod){
int ans=1%mod;a%=mod;
while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}
return ans;
}
int C(int n,int m){
   if(m<0||m>n)return 0;
   return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void C_init(){
   fac[0]=1;
   for(int i=1;i<maxm;i++)fac[i]=1ll*fac[i-1]*i%mod;
   inv[maxm-1]=ppow(fac[maxm-1],mod-2,mod);
   for(int i=maxm-2;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
void solve(){
    cin>>n;
    cin>>(s+1);
    for(int i=1;i<=n;i++)s[i]-='0';
    int c0=0,c2=0;
    for(int i=1;i<=n;i++){
        if(s[i]){
            if(i+1<=n&&s[i+1]){
                c2++;
                i++;
            }
        }else{
            c0++;
        }
    }
    int ans=C(c2+c0,c2);
    cout<<ans<<endl;
}
void Main(){
    C_init();
    #ifdef MULTI_CASE
    int T;cin>>T;while(T--)
    #endif
    solve();
}
void Init(){
    ios::sync_with_stdio(0);cin.tie(0);
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