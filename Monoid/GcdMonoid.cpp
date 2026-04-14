// GcdMonoid
struct GcdMonoid{
    using T=ll;
    static constexpr T e=0;
    static T op(T a,T b){
        return gcd(a,b);
    }
};