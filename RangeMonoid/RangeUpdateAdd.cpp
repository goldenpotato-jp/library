// RangeUpdateAdd
struct RangeUpdateAdd{
    using S=ll;
    using F=ll;
    static S e(){
        return 0;
    }static F id(){
        return 0;
    }static S op(S a,S b){
        return a+b;
    }static S mapping(F f,S x){
        return f;
    }static F composition(F f,F g){
        return f;
    }
};