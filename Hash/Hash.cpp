// Hash
struct Hash{
    static ull hash(ull x){
        x+=0x9e3779b97f4a7c15;
        x=(x^x>>30)*0xbf58476d1ce4e5b9;
        x=(x^x>>27)*0x94d049bb133111eb;
        return x^x>>31;
    }ull operator()(ull x)const{
        static const ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return hash(x+FIXED_RANDOM);
    }
};
struct PairHash{
    ull operator()(const pair<ll,ll>&p)const{
        static const ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return Hash::hash(Hash::hash((ull)p.first+FIXED_RANDOM)^Hash::hash((ull)p.second+FIXED_RANDOM)<<1);
    }
};