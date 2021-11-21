#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
#define int long long
using namespace std;
const int maxm=1e6+5;
int a[maxm];
int n,x;
void solve(){
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    
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