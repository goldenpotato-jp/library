// MinMonoid
struct MinMonoid{
    using T=ll;
    static constexpr T e=INF;
    static T op(T a,T b){
        return min(a,b);
    }
};