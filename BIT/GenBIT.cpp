// GenBIT
template<class G>
struct GenBIT{
    using T=typename G::T;
    int n;
    vector<T>bit;
    GenBIT(int N=0):n(N+1),bit(n,G::e()){}
    GenBIT(const vector<T>&v):n(v.size()+1),bit(n,G::e()){
        rep(i,n-1)add(i,v[i]);
    }void add(int i,T x){
        for(++i;i<n;i+=i&-i)bit[i]=G::op(bit[i],x);
    }T sum(int i){
        T s=G::e();
        for(++i;i>0;i-=i&-i)s=G::op(s,bit[i]);
        return s;
    }T get(int l,int r){
        return G::op(sum(r),G::inv(sum(l-1)));
    }T operator[](int i){
        return G::op(sum(i),G::inv(sum(i-1)));
    }int size(){
        return n-1;
    }
};