// LazySegTree
template<class M>struct LazySegTree{
    using S=typename M::S;
    using F=typename M::F;
    int n=1;
    vector<S>seg;
    vector<F>lazy;
    LazySegTree(int N=0){
        while(n<N)n<<=1;
        seg.assign(n<<1,M::e()),lazy.assign(n<<1,M::id());
    }LazySegTree(const vector<S>&v){
        while(n<v.size())n<<=1;
        seg.assign(n<<1,M::e()),lazy.assign(n<<1,M::id());
        rep(i,v.size())seg[i+n]=v[i];
        for(int i=n-1;i;--i)seg[i]=M::op(seg[i<<1],seg[i<<1|1]);
    }void apply(int i,F f){
        seg[i]=M::map(f,seg[i]);
        if(i<n)lazy[i]=M::com(f,lazy[i]);
    }void push(int i){
        if(lazy[i]!=M::id())apply(i<<1,lazy[i]),apply(i<<1|1,lazy[i]),lazy[i]=M::id();
    }void set(int l,int r,F f){
        set(l,r+1,f,1,0,n);
    }void set(int ql,int qr,F f,int i,int l,int r){
        if(r<=ql||qr<=l)return;
        if(ql<=l&&r<=qr){
            apply(i,f);
            return;
        }int m=(l+r)>>1;
        push(i),set(ql,qr,f,i<<1,l,m),set(ql,qr,f,i<<1|1,m,r),seg[i]=M::op(seg[i<<1],seg[i<<1|1]);
    }S get(int l,int r){
        return get(l,r+1,1,0,n);
    }S get(int ql,int qr,int i,int l,int r){
        if(r<=ql||qr<=l)return M::e();
        if(ql<=l&&r<=qr)return seg[i];
        push(i);
        int m=(l+r)>>1;
        return M::op(get(ql,qr,i<<1,l,m),get(ql,qr,i<<1|1,m,r));
    }S operator[](int i){
        return get(i,i);
    }
};