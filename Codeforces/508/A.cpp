#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int a[1111][1111];
int n,m,k;
bool check(int x,int y){
    for(int i=x-1;i<=x&&i+1<=n;i++){
        for(int j=y-1;j<=y&&j+1<=m;j++){
            if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        a[x][y]=1;
        if(check(x,y)){
            cout<<i<<endl;return ;
        }
    }
    cout<<0<<endl;
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