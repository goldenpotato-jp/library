// gpf_sieve
vector<ll>gpf_sieve(int n){
    vector<ll>v(n+1);
    for(int i=2;i<=n;++i)if(!v[i])for(int j=i;j<=n;j+=i)v[j]=i;
    return v;
}