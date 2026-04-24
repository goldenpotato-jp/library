// GcdMonoid
struct GcdMonoid{
    using T=ll;
    static T e(){
        return 0;
    }static T op(T a,T b){
        return gcd(a,b);
    }
};