// mod
ll mpow(ll x,ll n,ll m=998244353){
    ll r=1;
    while(n){
        if(n&1)r=r*x%m;
        x=x*x%m,n>>=1;
    }return r;
}ll minv(ll x,ll m=998244353){
    ll y=m,u=1,v=0;
    while(y){
        ll t=x/y;
        x-=t*y,swap(x,y),u-=t*v,swap(u,v);
    }u%=m;
    return u<0?u+m:u;
}ll mlog(ll a,ll b,ll m=998244353){
    ll sqrt_m=sqrt(m)+1,rem1=1,rem2=b;
    unordered_map<ll,ll>apow;
    rep(r,sqrt_m){
        if(!apow.count(rem1))apow[rem1]=r;
        (rem1*=a)%=m;
    }ll A=mpow(minv(a,m),sqrt_m,m);
    rep(q,sqrt_m){
        if(apow.count(rem2))return q*sqrt_m+apow[rem2];
        (rem2*=A)%=m;
    }return-1;
}