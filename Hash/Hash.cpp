// Hash
struct Hash{
    static ull hash(ull x){
        x+=0x9e3779b97f4a7c15;
        x=(x^x>>30)*0xbf58476d1ce4e5b9;
        x=(x^x>>27)*0x94d049bb133111eb;
        return x^x>>31;
    }static ull rng(){
        static const ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return FIXED_RANDOM;
    }ull operator()(ull x)const{
        return hash(x+rng());
    }ull operator()(const pair<ll,ll>&p)const{
        return hash(hash((ull)p.first+rng())^hash((ull)p.second+rng())<<1);
    }
};