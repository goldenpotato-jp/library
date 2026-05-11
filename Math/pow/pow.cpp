// pow
template<typename T>
T pow(T x,ll n){
    T r=1;
    while(n){
        if(n&1)r*=x;
        x*=x;
        n>>=1;
    }return r;
}