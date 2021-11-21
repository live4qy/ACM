#include<bits/stdc++.h>
#define MULTI_CASE
// #define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
const int mod=998244353;
// const int mod=1e9+7;
const int maxm=2e6+5;
int ppow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}
    return ans;
}
int d[11];
char s[maxm];
int r[maxm];
int n;
void solve(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=0;i<=n+1;i++){
        r[i]=0;
    }
    for(int i=n;i>=1;i--){
        r[i]=r[i+1]+(s[i]=='a');
    }
    for(int j=0;j<10;j++)d[j]=0;
    int ans=0;
    //nunhehheh
    //n,1,3
    //u,2
    //h,4,6,7,9
    //e,5,8
    for(int i=1;i<=n;i++){
        if(s[i]=='n'){
            d[3]=(d[3]+d[2])%mod;
            d[1]=(d[1]+1)%mod;
        }else if(s[i]=='u'){
            d[2]=(d[2]+d[1])%mod;
        }else if(s[i]=='h'){
            ans=(ans+1ll*d[8]*(ppow(2,r[i+1],mod)-1)%mod)%mod;
            d[9]=(d[9]+d[8])%mod;
            d[7]=(d[7]+d[6])%mod;
            d[6]=(d[6]+d[5])%mod;
            d[4]=(d[4]+d[3])%mod;
        }else if(s[i]=='e'){
            d[8]=(d[8]+d[7])%mod;
            d[5]=(d[5]+d[4])%mod;
        }
    }
    ans=(ans%mod+mod)%mod;
    printf("%d\n",ans);
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