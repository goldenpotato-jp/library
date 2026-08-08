// PrefixSumMaxPos
struct PrefixSumMaxPos{
    using T=tuple<ll,ll,int>;
    static T e(){
        return{0,-INF,-1};
    }static T op(T a,T b){
        if(a==e())return b;
        if(b==e())return a;
        if(get<1>(a)<get<0>(a)+get<1>(b))return{get<0>(a)+get<0>(b),get<0>(a)+get<1>(b),get<2>(b)};
        return{get<0>(a)+get<0>(b),get<1>(a),get<2>(a)};
    }
};