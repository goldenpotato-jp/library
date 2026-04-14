// RangeAddMin
struct RangeAddMin{
    using S=ll;
    using F=ll;
    static constexpr S e=INF;
    static constexpr F id=0;
    static S op(S a,S b){
        return min(a,b);
    }static S mapping(F f,S x){
        return x+f;
    }static F conposition(F f,F g){
        return g+f;
    }
};