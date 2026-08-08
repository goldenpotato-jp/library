// get_fact
vector<ll>get_fact(int n,ll mod=998244353){
    vector<ll>v(n+1);
    v[0]=1;
    rep(i,n)v[i+1]=v[i]*(i+1)%mod;
    return v;
}