// MaxMonoid
template<typename S=ll>
struct MaxMonoid{
    using T=S;
    static T e(){
        return -INF;
    }static T op(T a,T b){
        return max(a,b);
    }
};