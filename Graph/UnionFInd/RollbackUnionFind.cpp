// RollbackUnionFind
struct RollbackUnionFind{
    vector<int>p;
    stack<pair<int,int>>h;
    RollbackUnionFind(int n):p(n,-1){}
    int find(int x){
        while(p[x]>=0)x=p[x];
        return x;
    }bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y){
            rep(i,2)h.emplace(-1,-1);
            return 0;
        }if(p[x]>p[y])swap(x,y);
        h.emplace(x,p[x]);
        h.emplace(y,p[y]);
        p[x]+=p[y],p[y]=x;
        return 1;
    }void rollback(){
        auto[i2,v2]=h.top();h.pop();
        auto[i1,v1]=h.top();h.pop();
        if(i2==-1)return;
        p[i1]=v1,p[i2]=v2;
    }void rollback(int snap){
        while(h.size()>>1>snap)rollback();
    }bool same(int x,int y){
        return find(x)==find(y);
    }int size(int x){
        return-p[find(x)];
    }int snapshot(){
        return h.size()>>1;
    }
};