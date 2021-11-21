#include<bits/stdc++.h>
// #define MULTI_CASE
#define SYNC_OFF
#define PI pair<int,int>
#define ll long long
// #define int long long
using namespace std;
// const int mod=998244353;
const int mod=1e9+7;
const int maxm=2e6+5;
struct Node{
    int pos,l,r;
};
int n;
void solve(){
    cin>>n;
    string ans;
    stack<Node>s;
    for(int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        s.push({(int)ans.size()+1,l,r});
        ans+='(';
        while(s.size()){
            Node x=s.top();
            int now=(ans.size()+1)-x.pos;
            if(now>=x.l&&now<=x.r){//能匹配则匹配
                ans+=')';s.pop();
            }else break;
        }
    }
    if(s.size())cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
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