// MaxMonoid
template<typename T>
struct MaxMonoid{
    static T e(){
        return -INF;
    }static T op(T a,T b){
        return max(a,b);
    }
};