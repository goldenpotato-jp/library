// PrimeSieve
vector<bool>PrimeSieve(int n){
    vector<bool>v(n+1);
    for(int i=2;i<=n;++i)if(!v[i])for(int j=i+i;j<=n;j+=i)v[j]=1;
    return v;
}