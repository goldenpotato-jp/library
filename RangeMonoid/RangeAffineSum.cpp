// RangeAffineSum
struct RangeAffineSum{
    using S=pair<ll,ll>;
    using F=pair<ll,ll>;
    static constexpr ll mod=998244353;
    static S e(){
        return{0,0};
    }static F id(){
        return{1,0};
    }static S op(S a,S b){
        return{(a.first+b.first)%mod,a.second+b.second};
    }static S mapping(F f,S x){
        return{(x.first*f.first+f.second*x.second)%mod,x.second};
    }static F composition(F f,F g){
        return{g.first*f.first%mod,(g.second*f.first+f.second)%mod};
    }
};