// BIT
struct BIT{
    int n;
    vector<ll>bit;
    BIT(int n_=0):n(n_+1),bit(n,0){}
    BIT(const vector<ll>&v):n(v.size()+1),bit(n,0){
        rep(i,n-1)add(i,v[i]);
    }void add(int i,ll x){
        for(++i;i<n;i+=i&-i)bit[i]+=x;
    }ll sum(int i)const{
        ll s=0;
        for(++i;i>0;i-=i&-i)s+=bit[i];
        return s;
    }ll query(int l,int r)const{
        return sum(r)-sum(l-1);
    }int lower_bound(ll w)const{
        int x=0,r=1;
        while(r<n)r<<=1;
        for(int l=r;l>0;l>>=1)if(x+l<n&&bit[x+l]<w)w-=bit[x+=l];
        return x;
    }ll operator[](int i)const{
        return sum(i)-sum(i-1);
    }int size()const{
        return n-1;
    }
};