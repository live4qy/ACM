#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int a[maxm];
int n;

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //删掉两个数使得数据平均值不变
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    int ans=0;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        ans+=mp[2*sum-n*a[i]];
        mp[n*a[i]]++;
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