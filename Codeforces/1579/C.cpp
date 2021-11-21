#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
const int maxm=2e6+5;
char s[22][22];
int a[22][22];
int mp[22][22];
int n,m,k;
int check(int i,int j){
    int d=0;
    while(1){
        if(i-d<1||j-d<1||j+d>m)break;
        if(a[i-d][j-d]&&a[i-d][j+d]){
            d++;
        }else break;
    }
    return d-1;
}
void mark(int i,int j,int d){
    for(int x=0;x<=d;x++){
        mp[i-x][j-x]=mp[i-x][j+x]=1;
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>(s[i]+1);
        for(int j=1;j<=m;j++){
            a[i][j]=(s[i][j]=='*');
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=0;
        }
    }
    //枚举中点,尽可能标记可能被画到的点.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int d=check(i,j);
            if(d>=k){
                mark(i,j,d);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<mp[i][j];
    //     }
    //     cout<<endl;
    // }
    int ok=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]&&!mp[i][j]){
                ok=0;
            }
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
}
void Main(){
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