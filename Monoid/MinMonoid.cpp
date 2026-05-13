// MinMonoid
template<typename T>
struct MinMonoid{
    static T e(){
        return INF;
    }static T op(T a,T b){
        return min(a,b);
    }
};