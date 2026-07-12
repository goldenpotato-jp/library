// PrefixSumMax
struct PrefixSumMax{
    using T=pair<ll,ll>;
    static T e(){
        return{0,-INF};
    }static T op(T a,T b){
        return{a.first+b.first,max(a.second,a.first+b.second)};
    }
};