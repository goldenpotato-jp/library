// Combination
struct Combination{
    ll mod;
    vector<ll>fact,fact_inv;
    Combination(int n,ll mod_):mod(mod_),fact(n+1),fact_inv(n+1){
        fact[0]=1,fact_inv[0]=1;
        for(int i=1;i<=n;++i){
            fact[i]=fact[i-1]*i%mod;
            fact_inv[i]=inv(fact[i]);
        }
    }ll inv(ll x){
        ll n=mod-2,r=1;
        while(n){
            if(n&1)r=r*x%mod;
            x=x*x%mod;
            n>>=1;
        }return r;
    }ll get(int n,int r){
        return fact[n]*fact_inv[r]%mod*fact_inv[n-r]%mod;
    }
};