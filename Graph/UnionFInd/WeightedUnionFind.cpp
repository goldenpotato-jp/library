// WeightedUnionFind
template<class G>
struct WeightedUnionFind{
    using T=typename G::T;
    vector<int>p;
    vector<T>d;
    WeightedUnionFind(int n):p(n,-1),d(n,G::e){}
    int find(int x){
        if(p[x]<0)return x;
        int r=find(p[x]);
        d[x]=G::op(d[x],d[p[x]]);
        return p[x]=r;
    }T weight(int x){
        find(x);
        return d[x];
    }bool unite(int x,int y,T w){
        w=G::op(w,weight(x)),w=G::op(w,G::inv(weight(y)));
        x=find(x),y=find(y);
        if(x==y)return 0;
        if(p[x]>p[y]){
            swap(x,y);
            w=G::inv(w);
        }p[x]+=p[y],p[y]=x;
        d[y]=w;
        return 1;
    }bool same(int x,int y){
        return find(x)==find(y);
    }int size(int x){
        return-p[find(x)];
    }T diff(int x,int y){
        return G::op(weight(y),G::inv(weight(x)));
    }
};