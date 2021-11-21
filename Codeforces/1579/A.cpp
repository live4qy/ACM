#include<bits/stdc++.h>
#define PI pair<int,int>
// #define int long long
using namespace std;


void solve(){
    string s;cin>>s;
    map<char,int>mp;
    for(auto i:s)mp[i]++;
    if(mp['A']+mp['C']==mp['B']){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}
void Main(){
    int T;cin>>T;while(T--)
    solve();
}
void Init(){
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