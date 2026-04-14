// ModAddGroup
struct ModAddGroup{
    using T=ll;
    static constexpr T e=0,mod=998244353;
    static T op(T a,T b){
        return a+b<mod?a+b:a+b-mod;
    }static T inv(T a){
        return a?mod-a:0;
    }
};