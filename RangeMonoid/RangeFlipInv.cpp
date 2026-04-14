// RangeFlipInv
struct RangeFlipInv{
    using S=tuple<ll,ll,ll>;
    using F=bool;
    static constexpr S e={0,0,0};
    static constexpr F id=0;
    static S op(S a,S b){
        return{get<0>(a)+get<0>(b),get<1>(a)+get<1>(b),get<2>(a)+get<2>(b)+get<1>(a)*get<0>(b)};
    }static S mapping(F f,S x){
        return(f?S{get<1>(x),get<0>(x),get<0>(x)*get<1>(x)-get<2>(x)}:x);
    }static F conposition(F f,F g){
        return f^g;
    }
};