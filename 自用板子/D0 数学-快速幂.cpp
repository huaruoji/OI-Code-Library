ll fpm(ll a,ll b,ll p) {
	ll ans=1;
	for(;b;b>>=1,a=(a*a)%p) if(b&1) ans=(ans*a)%p;
	return ans%p;
}
