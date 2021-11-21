#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
int a[maxm];
int m,t,r;
void solve(){
    cin>>m>>t>>r;
    // cout<<m<<' '<<t<<' '<<r<<endl;
    if(t<r){//无解
        cout<<-1<<endl;return ;
    }
    for(int i=1;i<=m;i++)cin>>a[i];
    sort(a+1,a+1+m);
    queue<int>q;
    int ans=0;
    for(int i=1;i<=m;i++){
        while(q.size()&&q.front()+t-1<a[i])q.pop();
        int need=r-q.size();
        for(int j=a[i]-need+1;j<=a[i];j++){
            q.push(j);
            ans++;
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