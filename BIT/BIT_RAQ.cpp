// BIT_RAQ
struct BIT_RAQ{
    int n;
    vector<ll>bit[2];
    BIT_RAQ(int n_=0):n(n_+1){
        rep(i,2)bit[i].assign(n,0);
    }BIT_RAQ(const vector<ll>&v):n(v.size()+1){
        rep(i,2)bit[i].assign(n,0);
        rep(i,n-1)add(i,i,v[i]);
    }void add_sub(int p,int i,ll x){
        for(++i;i<n;i+=i&-i)bit[p][i]+=x;
    }void add(int l,int r,ll x){
        add_sub(0,l,-x*(l-1));
        add_sub(0,r+1,x*r);
        add_sub(1,l,x);
        add_sub(1,r+1,-x);
    }ll sum_sub(int p,int i)const{
        ll s=0;
        for(++i;i>0;i-=i&-i)s+=bit[p][i];
        return s;
    }ll sum(int i)const{
        return sum_sub(0,i)+sum_sub(1,i)*i;
    }ll query(int l,int r)const{
        return sum(r)-sum(l-1);
    }ll operator[](int i)const{
        return sum(i)-sum(i-1);
    }int size()const{
        return n-1;
    }
};