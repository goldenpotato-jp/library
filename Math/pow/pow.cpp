// pow
ll pow(ll x,ll n){
    ll r=1;
    while(n){
        if(n&1)r*=x;
        x*=x;
        n>>=1;
    }return r;
}