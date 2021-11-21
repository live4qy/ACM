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
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int a[maxm];
int n;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //eq
    int eq=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            eq=0;break;
        }
    }
    if(eq){
        cout<<-1<<endl;return ;
    }
    //mi肯定不变
    int mi=1e9;
    for(int i=1;i<=n;i++){
        mi=min(mi,a[i]);
    }
    //(a[i]-mi)%k=0
    int g=0;
    for(int i=1;i<=n;i++){
        g=gcd(a[i]-mi,g);
    }
    cout<<g<<endl;
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