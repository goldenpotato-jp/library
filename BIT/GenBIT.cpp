// GenBIT
template<class G>
struct GenBIT{
    using T=typename G::T;
    int n;
    vector<T>bit;
    GenBIT(int n_=0):n(n_+1),bit(n,G::e()){}
    GenBIT(const vector<T>&v):n(v.size()+1),bit(n,G::e()){
        rep(i,n-1)add(i,v[i]);
    }void add(int i,T x){
        for(++i;i<n;i+=i&-i)bit[i]=G::op(bit[i],x);
    }T sum(int i)const{
        T s=G::e();
        for(++i;i>0;i-=i&-i)s=G::op(s,bit[i]);
        return s;
    }T query(int l,int r)const{
        return G::op(sum(r),G::inv(sum(l-1)));
    }T operator[](int i)const{
        return G::op(sum(i),G::inv(sum(i-1)));
    }int size()const{
        return n-1;
    }
};