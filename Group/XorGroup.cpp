// XorGroup
template<class S=ll>
struct XorGroup{
    using T=S;
    static T e(){
        return 0;
    }static T op(T a,T b){
        return a^b;
    }static T inv(T a){
        return a;
    }
};