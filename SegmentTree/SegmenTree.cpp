// SegmentTree
template<class M>
struct SegmentTree{
    using T=typename M::T;
    int n=1,o;
    vector<T>seg;
    SegmentTree(int n_=0):o(n_){
        while(n<n_)n<<=1;
        seg.assign(n<<1,M::e());
    }SegmentTree(const vector<T>&v):o(v.size()){
        while(n<o)n<<=1;
        seg.assign(n<<1,M::e());
        rep(i,o)seg[i+n]=v[i];
        for(int i=n-1;i>0;--i)seg[i]=M::op(seg[i<<1],seg[i<<1|1]);
    }void set(int i,T x){
        seg[i+=n]=x;
        while(i>>=1)seg[i]=M::op(seg[i<<1],seg[i<<1|1]);
    }T get(int l,int r){
        T L=M::e(),R=M::e();
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1)L=M::op(L,seg[l++]);
            if(r&1)R=M::op(seg[--r],R);
        }return M::op(L,R);
    }template<class F>
    int max_right(int l,F f){
        l+=n;
        T sum=M::e();
        do{
            while(!(l&1))l>>=1;
            if(!f(M::op(sum,seg[l]))){
                while(l<n)if(f(M::op(sum,seg[l<<=1])))sum=M::op(sum,seg[l++]);
                return l-n-1;
            }sum=M::op(sum,seg[l++]);
        }while((l&-l)!=l);
        return o-1;
    }template<class F>
    int min_left(int r,F f){
        r+=n+1;
        T sum=M::e();
        do{
            r--;
            while(r>1&&r&1)r>>=1;
            if(!f(M::op(seg[r],sum))){
                while(r<n)if(f(M::op(seg[r=r<<1|1],sum)))sum=M::op(seg[r--],sum);
                return r-n+1;
            }sum=M::op(seg[r],sum);
        }while((r&-r)!=r);
        return 0;
    }T operator[](int i){
        return seg[i+n];
    }int size()const{
        return o;
    }
};