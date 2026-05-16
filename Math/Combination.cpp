// Combination
struct Combination{
    ll mod;
    vector<ll>fact,inv,fact_inv;
    Combination(int n,ll mod_=998244353):mod(mod_),fact(n+1),inv(n+1),fact_inv(n+1){
        fact[0]=inv[1]=fact_inv[0]=1;
        for(int i=1;i<=n;++i)fact[i]=fact[i-1]*i%mod;
        for(int i=2;i<=n;++i)inv[i]=mod-mod/i*inv[mod%i]%mod;
        for(int i=1;i<=n;++i)fact_inv[i]=fact_inv[i-1]*inv[i]%mod;
    }ll operator()(int n,int r)const{
        return fact[n]*fact_inv[r]%mod*fact_inv[n-r]%mod;
    }
};