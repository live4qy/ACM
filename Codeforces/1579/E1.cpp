#include<bits/stdc++.h>
#define MULTI_CASE
#define PI pair<int,int>
// #define int long long
using namespace std;
const int maxm=2e6+5;
int a[maxm];
int n;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    deque<int>q;
    for(int i=1;i<=n;i++){
        if(!q.size())q.push_back(a[i]);
        else{
            if(a[i]>q.front())q.push_back(a[i]);
            else q.push_front(a[i]);
        }
    }
    while(q.size()){
        cout<<q.front();q.pop_front();
        cout<<' ';
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