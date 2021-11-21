#include <bits/stdc++.h>

using namespace std;
const int maxm=2e5+5;
const int sq=300;
int pre[maxm*sq],idx;
int val[maxm*sq];
int L[sq],R[sq];
int rt[sq][101];
int bel[maxm];
int a[maxm];
int block,num;
int n,q;
int ffind(int x){
    return pre[x]==x?x:pre[x]=ffind(pre[x]);
}
inline int newNode(int c){
    idx++;pre[idx]=idx;val[idx]=c;return idx;
}
void init(){
    idx=n;
    block=sqrt(n)*3;
    block=min(block,n);
    num=n/block;
    assert(num<=sq);//
    if(n%block)num++;
    for(int i=1;i<=num;i++){
        L[i]=(i-1)*block+1;
        R[i]=i*block;
    }
    R[num]=n;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=100;j++){
            rt[i][j]=newNode(j);
        }
        for(int j=L[i];j<=R[i];j++){
            bel[j]=i;
            pre[j]=rt[i][a[j]];
        }
    }
}
void cal(){
    int l,r,x,y;scanf("%d%d%d%d",&l,&r,&x,&y);
    if(x==y)return ;
    if (bel[l]==bel[r]){
        int &ny=rt[bel[l]][y];
        for(int i=l;i<=r;i++){
            int c=val[ffind(i)];
            if (c==x){
                pre[i]=ny;
            }
        }
    }
    else{
        //中间块
        for (int i=bel[l]+1;i<bel[r];i++){
            pre[rt[i][x]]=rt[i][y];
            rt[i][x]=newNode(x);
        }
        //左边缘块
        int &nyL=rt[bel[l]][y];
        for (int i=l;i<=R[bel[l]];i++){
            int c=val[ffind(i)];
            if (c==x){
                pre[i]=nyL;
            }
        }
        //右边缘块
        int &nyR=rt[bel[r]][y];
        for (int i=L[bel[r]];i<=r;i++){
            int c=val[ffind(i)];
            if(c==x){
                pre[i]=nyR;
            }
        }
    }
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    init();
    scanf("%d",&q);
    while(q--){
        cal();
    }
    for(int i=1;i<=n;i++){
        int c=val[ffind(i)];
        printf("%d ",c);
    }
    puts("");
}
int main(){
    // ios::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    #endif
    solve();
    return 0;
}