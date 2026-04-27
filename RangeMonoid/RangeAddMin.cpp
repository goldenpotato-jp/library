// RangeAddMin
struct RangeAddMin{
    using S=ll;
    using F=ll;
    static S e(){
        return INF;
    }static F id(){
        return 0;
    }static S op(S a,S b){
        return min(a,b);
    }static S mapping(F f,S x){
        return x+f;
    }static F composition(F f,F g){
        return g+f;
    }
};