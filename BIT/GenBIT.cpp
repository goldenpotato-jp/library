// GenBIT
template<class G>
struct GenBIT{
    using T=typename G::T;
    int n;
    vector<T>bit;
    GenBIT(int n_):n(n_+1),bit(n,0){}
    GenBIT(const vector<T>&v):n(v.size()+1),bit(n,0){
        rep(i,n-1)add(i,v[i]);
    }void add(int i,T x){
        for(++i;i<n;i+=i&-i)bit[i]=G::op(bit[i],x);
    }T sum(int i){
        T s=0;
        for(++i;i>0;i-=i&-i)s=G::op(s,bit[i]);
        return s;
    }T query(int l,int r){
        return G::op(sum(r),G::inv(sum(l-1)));
    }T operator[](int i){
        return G::op(sum(i),G::inv(sum(i-1)));
    }
};