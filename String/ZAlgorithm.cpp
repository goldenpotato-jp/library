// ZAlgorithm
struct ZAlgorithm{
    int n;
    vector<int>z;
    ZAlgorithm(const string&s):n(s.size()),z(n){
        vector<int>v(n);
        rep(i,n)v[i]=s[i]-'a';
        build(v);
    }template<class T>ZAlgorithm(const vector<T>&v):n(v.size()),z(n){
        build(v);
    }template<class T>void build(const vector<T>&v){
        z[0]=n;
        int l=0,r=0;
        for(int i=1;i<n;++i){
            if(i<r)z[i]=min(z[i-l],r-i);
            while(i+z[i]<n&&v[z[i]]==v[i+z[i]])++z[i];
            if(i+z[i]>r)l=i,r=i+z[i];
        }
    }int operator[](int i){
        return z[i];
    }
};