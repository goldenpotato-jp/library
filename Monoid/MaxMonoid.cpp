// MaxMonoid
struct MaxMonoid{
    using T=ll;
    static T e(){
        return -INF;
    }static T op(T a,T b){
        return max(a,b);
    }
};