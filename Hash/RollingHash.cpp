// RollingHash
struct RollingHash{
    static constexpr ull mask1=(1ULL<<30)-1,mask2=(1ULL<<31)-1,mod=(1ULL<<61)-1;
    inline static vector<ull>pow={1};
    vector<ull>hash;
    static ull add(ull a,ull b){
        a+=b;
        if(a>=mod)a-=mod;
        return a;
    }static ull sub(ull a,ull b){
        return add(a,mod^b);
    }static ull mul(ull a,ull b){
        ull au=a>>31,ad=a&mask2,bu=b>>31,bd=b&mask2,m=ad*bu+au*bd,mu=m>>30,md=m&mask1,x=(au*bu<<1)+mu+(md<<31)+ad*bd;
        x=(x>>61)+(x&mod);
        if(x>=mod)x-=mod;
        return x;
    }static ull base(){
        static const ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return FIXED_RANDOM%(mod^1<<20)+(1<<20);
    }static void expand(int n){
        if(pow.size()>n)return;
        int m=pow.size();
        pow.resize(n+1);
        for(int i=m;i<=n;++i)pow[i]=mul(pow[i-1],base());
    }RollingHash(const string&s):hash(s.size()+1){
        expand(s.size());
        rep(i,s.size())hash[i+1]=add(mul(hash[i],base()),s[i]);
    }ull get(int l,int r)const{
        return sub(hash[r+1],mul(hash[l],pow[r-l+1]));
    }int lcp(int a,int b)const{
        int l=0,r=hash.size()-max(a,b);
        while(r-l>1){
            int m=(l+r)>>1;
            if(get(a,a+m-1)==get(b,b+m-1))l=m;
            else r=m;
        }return l;
    }
};