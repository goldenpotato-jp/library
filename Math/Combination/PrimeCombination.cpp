// PrimeCombination
struct PrimeCombination{
    ll mod;
    vector<ll>fact,inv,fact_inv;
    PrimeCombination(int N,ll mod=998244353):mod(mod),fact(N+1),inv(N+1),fact_inv(N+1){
        fact[0]=inv[1]=fact_inv[0]=1;
        rep(i,N)fact[i+1]=fact[i]*(i+1)%mod;
        for(int i=2;i<=N;++i)inv[i]=mod-mod/i*inv[mod%i]%mod;
        rep(i,N)fact_inv[i+1]=fact_inv[i]*inv[i+1]%mod;
    }ll operator()(int n,int r){
        return n<r||n<0||r<0?0:fact[n]*fact_inv[r]%mod*fact_inv[n-r]%mod;
    }
};