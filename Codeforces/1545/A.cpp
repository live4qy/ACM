#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
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
    //每次交换,下标奇偶性变化
    //要保证每个数最后,下标的奇偶性不变.
    //统计每个数排序之前的奇偶个数
    //统计每个数排序之后的奇偶个数
    //如果某个数的奇偶性不相同则无解
    map<int,int>mp[2];
    for(int i=1;i<=n;i++){
        mp[i%2][a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        mp[i%2][a[i]]--;
    }
    for(int x=0;x<2;x++){
        for(auto i:mp[x]){
            if(i.second){
                cout<<"NO"<<endl;return ;
            }
        }
    }
    cout<<"YES"<<endl;
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