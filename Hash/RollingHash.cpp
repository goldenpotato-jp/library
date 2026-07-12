// RollingHash
struct RollingHash{
    static constexpr ull mod=(1ULL<<61)-1;
    inline static vector<ull>pow={1};
    vector<ull>hash;
    static ull add(ull a,ull b){
        return(a+b>=mod?a+b-mod:a+b);
    }static ull sub(ull a,ull b){
        return add(a,mod^b);
    }static ull mul(__uint128_t a,__uint128_t b){
        __uint128_t x=a*b;
        x=(x>>61)+(x&mod);
        if(x>=mod)x-=mod;
        return x;
    }static ull base(){
        static ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return FIXED_RANDOM%(mod^1<<20)+(1<<20);
    }static void expand(int n){
        if(pow.size()>n)return;
        int m=pow.size();
        pow.resize(n+1);
        for(int i=m;i<=n;++i)pow[i]=mul(pow[i-1],base());
    }RollingHash(const string&s):hash(s.size()+1){
        expand(s.size());
        rep(i,s.size())hash[i+1]=add(mul(hash[i],base()),s[i]);
    }template<class T>
    RollingHash(const vector<T>&v):hash(v.size()+1){
        expand(v.size());
        rep(i,v.size())hash[i+1]=add(mul(hash[i],base()),v[i]);
    }ull get(int l,int r){
        return sub(hash[r+1],mul(hash[l],pow[r-l+1]));
    }int lcp(int a,int b){
        int l=0,r=hash.size()-max(a,b);
        while(r-l>1){
            int m=(l+r)>>1;
            if(get(a,a+m-1)==get(b,b+m-1))l=m;
            else r=m;
        }return l;
    }
};