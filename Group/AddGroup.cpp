// AddGroup
struct AddGroup{
    using T=ll;
    static constexpr T e=0;
    static T op(T a,T b){
        return a+b;
    }static T inv(T a){
        return-a;
    }
};