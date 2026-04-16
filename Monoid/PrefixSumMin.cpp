// PrefixSumMin
struct PrefixSumMin{
    using T=pair<ll,ll>;
    static constexpr T={0,INF};
    static T op(T a,T b){
        return{a.first+b.first,min(a.second,a.first+b.second)};
    }
};