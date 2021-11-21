#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
#define int long long
using namespace std;
const int mod=998244353;
// const int mod=1e9+7;
const int maxm=3e3+5;
int d[maxm][maxm];
int temp[maxm];
int a[maxm];
int b[maxm];
int n;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    //dp[i][j]表示前i个数,末尾为j的方案数
    d[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=3e3;j++){
            temp[j]=0;
        }
        int l=a[i+1],r=b[i+1];
        for(int j=0;j<=3e3;j++){
            if(!d[i][j])continue;
            if(j<l){
                temp[l]=(temp[l]+d[i][j])%mod;
                temp[r+1]=(temp[r+1]-d[i][j])%mod;
            }else if(j<=r){
                temp[j]=(temp[j]+d[i][j])%mod;
                temp[r+1]=(temp[r+1]-d[i][j])%mod;
            }
        }
        for(int j=0;j<=3e3;j++){
            temp[j+1]=(temp[j+1]+temp[j])%mod;
            d[i+1][j]=temp[j];
        }
    }
    int ans=0;
    for(int i=0;i<=3e3;i++){
        ans=(ans+d[n][i])%mod;
    }
    ans=(ans%mod+mod)%mod;
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