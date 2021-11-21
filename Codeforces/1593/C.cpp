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
int a[maxm];
int n,k;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+k);
    int ans=0;
    int time=0;
    for(int i=k;i;i--){
        if(time>=a[i])break;
        int dif=n-a[i];
        time+=dif;
        ans++;
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