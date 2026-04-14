// RangeAddModsum
struct RangeAddModsum{
    using S=ll;
    using F=ll;
    static constexpr ll mod=998244353;
    static constexpr S e=0;
    static constexpr F id=0;
    static S op(S a,S b){
        return a+b<mod?a+b:a+b-mod;
    }static S mapping(F f,S x){
        return x+f<mod?x+f:x+f-mod;
    }static F conposition(F f,F g){
        return f+g<mod?f+g:f+g-mod;
    }
};