// MinMonoid
struct MinMonoid{
    using T=ll;
    static T e(){
        return INF;
    }static T op(T a,T b){
        return min(a,b);
    }
};