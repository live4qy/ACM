#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
char s[maxm];
int d[30][30];
int n;
void solve(){
    cin>>(s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)s[i]-='0';
    for(int i=0;i<=n;i++){
        for(int j=0;j<25;j++){
            d[i][j]=1e9;
        }
    }
    d[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<25;j++){
            if(d[i][j]==1e9)continue;
            //删
            d[i+1][j]=min(d[i+1][j],d[i][j]+1);
            //不删
            int nt=(j*10+s[i+1])%25;
            d[i+1][nt]=min(d[i+1][nt],d[i][j]);
        }
    }
    int ans=d[n][0];
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