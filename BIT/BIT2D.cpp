// BIT2D
struct BIT2D{
    int h,w;
    vector<vector<ll>>bit;
    BIT2D(int h_=0,int w_=0):h(h_+1),w(w_+1),bit(h,vector<ll>(w,0)){}
    BIT2D(const vector<vector<ll>>&v):h(v.size()+1),w(v[0].size()+1),bit(h,vector<ll>(w,0)){
        rep(i,h-1)rep(j,w-1)add(i,j,v[i][j]);
    }void add(int i,int j,ll x){
        for(++i;i<h;i+=i&-i)for(int y=j+1;y<w;y+=y&-y)bit[i][y]+=x;
    }ll sum(int i,int j)const{
        ll s=0;
        for(++i;i>0;i-=i&-i)for(int y=j+1;y>0;y-=y&-y)s+=bit[i][y];
        return s;
    }ll query(int i1,int j1,int i2,int j2)const{
        return sum(i2,j2)-sum(i2,j1-1)-sum(i1-1,j2)+sum(i1-1,j1-1);
    }ll get(int i,int j)const{
        return query(i,j,i,j);
    }int size_h()const{
        return h-1;
    }int size_w()const{
        return w-1;
    }
};