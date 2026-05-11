// RangeUpdateModsum
struct RangeUpdateModsum{
    using S=pair<ll,ll>;
    using F=ll;
    static constexpr ll mod=998244353;
    static S e(){
        return{0,0};
    }static F id(){
        return-1;
    }static S op(S a,S b){
        return{a.first+b.first<mod?a.first+b.first:a.first+b.first-mod,a.second+b.second};
    }static S mapping(F f,S x){
        return{f==-1?x.first:f*x.second%mod,x.second};
    }static F composition(F f,F g){
        return f==-1?g:f;
    }
};