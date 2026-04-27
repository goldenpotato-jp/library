// RangeFlipInv
struct RangeFlipInv{
    using S=tuple<ll,ll,ll>;
    using F=bool;
    static S e(){
        return{0,0,0};
    }static F id(){
        return 0;
    }static S op(S a,S b){
        return{get<0>(a)+get<0>(b),get<1>(a)+get<1>(b),get<2>(a)+get<2>(b)+get<1>(a)*get<0>(b)};
    }static S mapping(F f,S x){
        return(f?S{get<1>(x),get<0>(x),get<0>(x)*get<1>(x)-get<2>(x)}:x);
    }static F composition(F f,F g){
        return f^g;
    }
};