#include<bits/stdc++.h>
#define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
/*
T组数据,T<=1e5
1<=s,n,k<=1e18,
n<=s

只能O(1)或者O(log)或者O(log*log)
*/
int s,n,k;//s个动物,n个格子,条件k
//需要满足任意放都至少有一个子区间满足区间和为k
void solve(){
    cin>>s>>n>>k;
    if(s==k){
        cout<<"YES"<<endl;return ;
    }else if(s<k){
        cout<<"NO"<<endl;return ;
    }
    int cnt=s/(2*k)*k;//能放多少个格子
    int rm=s%(2*k);//多余的格子
    if(n>=cnt+min(rm+1,k)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
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