#include<bits/stdc++.h>
#define ll long long
#define re register
#define cs const

using std::cerr;
using std::cout;

cs int mod=1e9+7;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(int a,int b){return a-b<0?a-b+mod:a-b;}
inline int mul(int a,int b){ll r=(ll)a*b;return r>=mod?r%mod:r;}
inline void Inc(int &a,int b){a+=b-mod;a+=a>>31&mod;}
inline void Dec(int &a,int b){a-=b;a+=a>>31&mod;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline int po(int a,int b){int r=1;for(;b;b>>=1,Mul(a,a))if(b&1)Mul(r,a);return r;}
inline void ex_gcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return;}ex_gcd(b,a%b,y,x);y-=a/b*x;
}inline int inv(int a){int x,y;ex_gcd(mod,a,y,x);return x+(x>>31&mod);}

namespace DEBUG {
	void debug_out() { cerr << '\n'; }
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) { cerr << ' ' << H, debug_out(T...); }
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
} using namespace DEBUG;
cs int N=1.5e3+7,K=1e5+7;
int n,m,a,b,k;
int P[N],Pr[N],iv[N];
int s[2][N],ss[2][N],sp[2][N];

void init_p(){
	int p=mul(a,inv(b)),q=dec(1,p);
	int dlt=mul(p,inv(q));P[0]=Pr[0]=po(q,k);
	for(int i=1;i<=m;++i){
		iv[i]=i==1?1:mul(mod-mod/i,iv[mod%i]);
		P[i]=mul(P[i-1],mul(dlt,mul(k-i+1,iv[i])));
		Pr[i]=add(Pr[i-1],P[i]);
	}
}

void Main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
	init_p();int t=1;
	s[0][m]=ss[0][m]=1;sp[0][m]=P[m];
	for(int re i=1;i<=n;++i,t^=1)
		for(int re j=1;j<=m;++j){
			s[t][j]=mul(P[m-j],dec(mul(dec(ss[t^1][m],ss[t^1][m-j]),Pr[j-1]),sp[t^1][j-1]));
			ss[t][j]=add(ss[t][j-1],s[t][j]);
			sp[t][j]=add(sp[t][j-1],mul(ss[t][j],P[j]));
		}
	cout<<ss[t^1][m]<<"\n";
}

inline void file(){
#ifdef zxyoi
	freopen("camp.in","r",stdin);
#else
#ifndef ONLINE_JUDGE
	freopen("camp.in","r",stdin);
	freopen("camp.out","w",stdout);
#endif
#endif
}
signed main(){file();Main();return 0;}
