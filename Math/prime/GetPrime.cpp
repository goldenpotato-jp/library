// GetPrime
vector<ll>GetPrime(int n){
    vector<bool>v(n+1);
    vector<ll>res;
    for(int i=2;i<=n;++i)if(!v[i]){
        res.emplace_back(i);
        for(int j=i+i;j<=n;j+=i)v[j]=1;
    }return res;
}