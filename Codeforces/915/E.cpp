#include<bits/stdc++.h>
using namespace std;
#define type bool
#define It set<Node>::iterator
struct Node{
    int l,r;
    mutable type x;
    Node(int a,int b=0,type c=0){
        l=a,r=b,x=c;
    }
    bool operator<(const Node& a)const {
        return l<a.l;
    }
};
set<Node>s;
int n,m;
int ans;
It split(int pos){
    auto it=s.lower_bound(Node(pos));//不能用upper_bound,因为要找最左边的一个
    if(it!=s.end()&&it->l==pos){
        return it;
    }
    it--;
    int l=it->l,r=it->r;
    type x=it->x;
    s.erase(it);
    s.insert(Node(l,pos-1,x));
    return s.insert(Node(pos,r,x)).first;
}
void assign(int l,int r,type val){//区间赋值
    auto it2=split(r+1),it1=split(l);//要先找r,再找l
    for(auto temp=it1;temp!=it2;temp++){
        if(temp->x){
            ans-=temp->r-temp->l+1;
        }
    }
    s.erase(it1,it2);
    s.insert(Node(l,r,val));
    ans+=(r-l+1)*val;
}
void solve(){
    scanf("%d%d",&n,&m);
    s.insert(Node(1,n,1));
    ans=n;
    while(m--){
        int l,r,op;scanf("%d%d%d",&l,&r,&op);
        if(op==1){//[l,r]修改为0
            assign(l,r,0);
        }else if(op==2){//[l,r]修改为1
            assign(l,r,1);
        }
        printf("%d\n",ans);
    }
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    solve();
    return 0;
}
