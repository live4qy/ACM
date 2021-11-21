#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = (1<<20)+10;
ll seg[2][maxn*4],ans[2][21];

void modify(int id,int o,int l,int r,int deep,int x){
	if(l == r){
		seg[id][o] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(id,o<<1,l,mid,deep+1,x);
	else modify(id,o<<1|1,mid+1,r,deep+1,x);
	if(seg[id][o] != -1) ans[id][deep]--;
	if(seg[id][o<<1] == seg[id][o<<1|1]) seg[id][o] = seg[id][o<<1];
	else seg[id][o] = -1;
	if(seg[id][o] != -1) ans[id][deep]++;
}
inline void read(int& x){
	char ch = getchar();
	x = 0;
	for(;ch < '0' || ch > '9';ch = getchar());
	for(;ch >= '0' && ch <= '9';ch = getchar()) x = x*10+(ch-'0');
}
inline void write(ll x){
	char ch = x%10+'0';
	if(x >= 10) write(x/10);
	putchar(ch);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int n,m,sz;
	ll sum = 0;
	read(sz);read(m);
	n = (1 << sz);
	for(int i = 0;i < sz;i++){
		ans[0][i+1] = ans[1][i+1] = (1 << i);
		sum += (1ll << (i * 2)); 
	}
	for(int i = 0;i < m;i++){
		int id, x;
		read(id);read(x);
		modify(id,1,1,n,1,x);
		ll tmp = 0;
		for(int i = 1;i <= sz;i++){
			tmp += 1ll*ans[0][i] * ans[1][i];
		}
		write(4ll * (sum - tmp) + 1);puts("");
	}
	return 0;
}
