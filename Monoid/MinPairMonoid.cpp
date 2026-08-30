// MinPairMonoid
struct MinPairMonoid{
    using T=pair<ll,ll>;
    static T e(){
        return{INF,INF};
    }static T op(T a,T b){
        return min(a,b);
    }
};