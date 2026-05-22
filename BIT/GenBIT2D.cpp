// GenBIT2D
template<class G>
struct GenBIT2D{
    using T=typename G::T;
    int h,w;
    vector<vector<T>>bit;
    GenBIT2D(int h_=0,int w_=0):h(h_+1),w(w_+1),bit(h,vector<T>(w,0)){}
    GenBIT2D(const vector<vector<T>>&v):h(v.size()+1),w(v[0].size()+1),bit(h,vector<T>(w,0)){
        rep(i,h-1)rep(j,w-1)add(i,j,v[i][j]);
    }void add(int i,int j,T x){
        for(++i;i<h;i+=i&-i)for(int y=j+1;y<w;y+=y&-y)bit[i][y]=G::op(bit[i][y],x);
    }T sum(int i,int j)const{
        T s=0;
        for(++i;i>0;i-=i&-i)for(int y=j+1;y>0;y-=y&-y)s=G::op(s,bit[i][y]);
        return s;
    }T get(int i1,int j1,int i2,int j2)const{
        return G::op(G::op(G::op(sum(i2,j2),G::inv(sum(i2,j1-1))),G::inv(sum(i1-1,j2))),sum(i1-1,j1-1));
    }T get(int i,int j)const{
        return query(i,j,i,j);
    }int size_h()const{
        return h-1;
    }int size_w()const{
        return w-1;
    }
};