// MinMonoid
template<typename S=ll>
struct MinMonoid{
    using T=S;
    static T e(){
        return INF;
    }static T op(T a,T b){
        return min(a,b);
    }
};