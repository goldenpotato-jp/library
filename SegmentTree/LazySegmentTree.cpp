// LazySegmentTree
template<class M>
struct LazySegmentTree{
    using S=typename M::S;
    using F=typename M::F;
    int n=1;
    vector<S>seg;
    vector<F>lazy;
    LazySegmentTree(int N=0){
        while(n<N)n<<=1;
        seg.assign(n<<1,M::e()),lazy.assign(n<<1,M::id());
    }LazySegmentTree(const vector<S>&v){
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
        set(l,r,f,1,0,n-1);
    }void set(int ql,int qr,F f,int i,int l,int r){
        if(r<ql||qr<l)return;
        if(ql<=l&&r<=qr){
            apply(i,f);
            return;
        }push(i),set(ql,qr,f,i<<1,l,(l+r)>>1),set(ql,qr,f,i<<1|1,((l+r)>>1)+1,r),seg[i]=M::op(seg[i<<1],seg[i<<1|1]);
    }S get(int l,int r){
        return get(l,r,1,0,n-1);
    }S get(int ql,int qr,int i,int l,int r){
        if(r<ql||qr<l)return M::e();
        if(ql<=l&&r<=qr)return seg[i];
        push(i);
        return M::op(get(ql,qr,i<<1,l,(l+r)>>1),get(ql,qr,i<<1|1,((l+r)>>1)+1,r));
    }S operator[](int i){
        return get(i,i);
    }
};