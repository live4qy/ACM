#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int d[11111][2222];
int a[maxm];
int n;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=2000;j++){
            d[i][j]=mod;    //inf
        }
    }
    d[0][0]=0;
    for(int i=0;i<n;i++){
        int x=a[i+1];
        for(int j=0;j<=2000;j++){
            if(d[i][j]==mod)continue;
            //ed向左扩展
            if(j>=x){
                d[i+1][j-x]=min(d[i+1][j-x],d[i][j]+x);
            }else{
                d[i+1][0]=min(d[i+1][0],x+d[i][j]);
            }
            //ed向右扩展
            if(d[i][j]>=x){
                d[i+1][j+x]=min(d[i+1][j+x],d[i][j]-x);
            }else{
                //如果超过2000肯定不是最优解,忽略
                if(j+x<=2000){  
                    d[i+1][j+x]=min(d[i+1][j+x],0);
                }
            }
        }
    }
    int ans=mod;
    for(int j=0;j<=2000;j++){
        ans=min(ans,j+d[n][j]);
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