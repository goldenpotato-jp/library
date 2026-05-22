// SegmentTree2D
template<class M>
struct SegmentTree2D{
    using T=typename M::T;
    int H,W,h=1,w=1;
    vector<T>seg;
    int id(int i,int j)const{
        return (i*w<<1)+j;
    }SegmentTree2D(int h_=0,int w_=0):H(h_),W(w_){
        while(h<H)h<<=1;
        while(w<W)w<<=1;
        seg.assign(h*w<<2,M::e());
    }SegmentTree2D(const vector<vector<T>>&v):H(v.size()),W(v[0].size()){
        while(h<H)h<<=1;
        while(w<W)w<<=1;
        seg.assign(h*w<<2,M::e());
        rep(i,H)rep(j,W)seg[id(i+h,j+w)]=v[i][j];
        build();
    }void build(){
        for(int i=w;i<w<<1;++i)for(int j=h-1;j;--j)seg[id(j,i)]=M::op(seg[id(j<<1,i)],seg[id(j<<1|1,i)]);
        rep(i,h<<1)for(int j=w-1;j;--j)seg[id(i,j)]=M::op(seg[id(i,j<<1)],seg[id(i,j<<1|1)]);
    }void set(int i,int j,T x){
        seg[id(i+=h,j+=w)]=x;
        for(int x=i>>1;x;x>>=1)seg[id(x,j)]=M::op(seg[id(x<<1,j)],seg[id(x<<1|1,j)]);
        for(;i;i>>=1)for(int y=j>>1;y;y>>=1)seg[id(i,y)]=M::op(seg[id(i,y<<1)],seg[id(i,y<<1|1)]);
    }T query(int i,int j1,int j2)const{
        T res=M::e();
        for(;j1<j2;j1>>=1,j2>>=1){
            if(j1&1)res=M::op(res,seg[id(i,j1++)]);
            if(j2&1)res=M::op(seg[id(i,--j2)],res);
        }return res;
    }T get(int i1,int j1,int i2,int j2)const{
        T res=M::e();
        i1+=h,j1+=w,i2+=h,j2+=w;
        for(;i1<i2;i1>>=1,i2>>=1){
            if(i1&1)res=M::op(res,query(i1++,j1,j2));
            if(i2&1)res=M::op(query(--i2,j1,j2),res);
        }return res;
    }T operator()(int i,int j)const{
        return seg[id(i+h,j+w)];
    }int size_h()const{
        return H;
    }int size_w()const{
        return W;
    }
};