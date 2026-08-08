// RangeChminPoint
struct RangeChminPoint{
    using S=ll;
    using F=ll;
    static S e(){
        return INF;
    }static F id(){
        return INF;
    }static S op(S a,S b){
        return(a==e()?b:a);
    }static S map(F f,S x){
        return min(x,f);
    }static F com(F f,F g){
        return min(g,f);
    }
};