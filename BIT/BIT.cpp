// BIT
template<typename T>
struct BIT{
    int n;
    vector<T>bit;
    BIT(int n_):n(n_+1),bit(n,0){}
    BIT(const vector<T>&v):n(v.size()+1),bit(n,0){
        rep(i,n-1)add(i,v[i]);
    }void add(int i,T x){
        for(++i;i<n;i+=i&-i)bit[i]+=x;
    }T sum(int i){
        T s=0;
        for(++i;i>0;i-=i&-i)s+=bit[i];
        return s;
    }T query(int l,int r){
        return sum(r)-sum(l-1);
    }int lower_bound(T w){
        int x=0,r=1;
        while(r<n)r<<=1;
        for(int l=r;l>0;l>>=1)if(x+l<n&&bit[x+l]<w)w-=bit[x+=l];
        return x;
    }T operator[](int i){
        return sum(i)-sum(i-1);
    }
};