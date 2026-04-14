// MaxMonoid
struct MaxMonoid{
    using T=ll;
    static constexpr T e=-INF;
    static T op(T a,T b){
        return max(a,b);
    }
};