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
int n;
int check(int k){
    int ans=0;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[(a[i]%k+k)%k]++;
    }
    for(auto i:mp){
        if(i.second*2>=n)return 1;
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //inf
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[a[i]]++;
    }
    int INF=0;
    for(auto i:mp){
        if(i.second*2>=n){//至少有一半
            INF=1;
        }
    }
    if(INF){
        cout<<-1<<endl;return ;
    }
    //
    srand(time(NULL));
    int ans=0;
    for(int c=1;c<=1000;c++){//随机1000次
        int rd=rand()%n+1;//0.5的概率随机到答案数
        int rd2=rand()%n+1;//0.5的概率随机到答案数
        if(rd==rd2)continue;
        int x=abs(a[rd]-a[rd2]);
        //k是x的因子
        for(int j=1;j*j<=x;j++){//
            if(x%j==0){
                if(check(j))ans=max(ans,j);
                if(check(x/j))ans=max(ans,x/j);
            }
        }
    }
    //随机不到答案的概率为0.75^1000,约等于0
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