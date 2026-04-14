// BIT_RAQ
template<typename T>
struct BIT_RAQ{
    int n;
    vector<T>bit[2];
    BIT_RAQ(int n_):n(n_+1){
        rep(i,2)bit[i].assign(n,0);
    }BIT_RAQ(const vector<T>&v):n(v.size()+1){
        rep(i,2)bit[i].assign(n,0);
        rep(i,n-1)add(i,i,v[i]);
    }void add_sub(int p,int i,T x){
        for(++i;i<n;i+=i&-i)bit[p][i]+=x;
    }void add(int l,int r,T x){
        add_sub(0,l,-x*(l-1));
        add_sub(0,r+1,x*r);
        add_sub(1,l,x);
        add_sub(1,r+1,-x);
    }T sum_sub(int p,int i){
        T s=0;
        for(++i;i>0;i-=i&-i)s+=bit[p][i];
        return s;
    }T sum(int i){
        return sum_sub(0,i)+sum_sub(1,i)*i;
    }T query(int l,int r){
        return sum(r)-sum(l-1);
    }T operator[](int i){
        return sum(i)-sum(i-1);
    }
};