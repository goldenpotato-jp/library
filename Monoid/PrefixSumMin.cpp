// PrefixSumMin
struct PrefixSumMin{
    using T=pair<int,ll>;
    static T e(){
        return{0,INF};
    }static T op(T a,T b){
        return{a.first+b.first,min(a.second,a.first+b.second)};
    }
};