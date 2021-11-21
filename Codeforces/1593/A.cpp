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

void solve(){
    int s=0;
    for(int i=1;i<=3;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=3;i++){
        int ma=0;
        for(int j=1;j<=3;j++){
            if(i==j)continue;
            ma=max(ma,a[j]);
        }
        cout<<max(0,ma-a[i]+1)<<' ';
    }
    cout<<endl;

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