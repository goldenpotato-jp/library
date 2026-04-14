// mpow
ll mpow(ll x,ll n,ll m){
    ll r=1;
    while(n){
        if(n&1)r=r*x%m;
        x=x*x%m;
        n>>=1;
    }return r;
}