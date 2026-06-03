// RangeAddModsum
struct RangeAddModsum{
    using S=ll;
    using F=ll;
    static constexpr ll mod=998244353;
    static S e(){
        return 0;
    }static F id(){
        return 0;
    }static S op(S a,S b){
        return a+b<mod?a+b:a+b-mod;
    }static S mapping(F f,S x){
        return x+f<mod?x+f:x+f-mod;
    }static F composition(F f,F g){
        return f+g<mod?f+g:f+g-mod;
    }
};