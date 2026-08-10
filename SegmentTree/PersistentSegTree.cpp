// PersistentSegTree
template<class M,int NODES=2000000>
struct PersistentSegTree{
    using T=typename M::T;
    struct Node{
        T data;
        int l,r;
        Node():data(M::e()),l(0),r(0){}
        Node(const T&data,int l,int r):data(data),l(l),r(r){}
    };Node*pool=new Node[NODES];
    int pid=1,N;
    vector<int>roots;
    PersistentSegTree(int N):N(N){
        pool[0]=Node(),roots.reserve(262144),roots.emplace_back(0);
    }PersistentSegTree(const vector<T>&v):N(v.size()){
        pool[0]=Node(),roots.reserve(262144),roots.emplace_back(build(0,v.size(),v));
    }int my_new(const T&data,int l=0,int r=0){
        pool[pid]={data,l,r};
        return pid++;
    }int merge(int l,int r){
        return my_new(M::op(pool[l].data,pool[r].data),l,r);
    }int build(int l,int r,const vector<T>&v){
        if(l+1==r)return my_new(v[l]);
        int m=(l+r)>>1;
        return merge(build(l,m,v),build(m,r,v));
    }int update(int i,const T&x,int n,int l,int r){
        if(l+1==r)return my_new(x);
        int m=(l+r)>>1;
        if(i<m)return merge(update(i,x,pool[n].l,l,m),pool[n].r);
        return merge(pool[n].l,update(i,x,pool[n].r,m,r));
    }int update(int n,int i,const T&x){
        return roots.emplace_back(update(i,x,n,0,N));
    }int update_t(int t,int i,const T&x){
        return roots.emplace_back(update(i,x,roots[t],0,N));;
    }int update(int i,const T&x){
        return roots.emplace_back(update(i,x,roots.back(),0,N));
    }int add(int i,const T&x,int n,int l,int r){
        if(l+1==r)return my_new(M::op(x,pool[n].data));
        int m=(l+r)>>1;
        if(i<m)return merge(add(i,x,pool[n].l,l,m),pool[n].r);
        return merge(pool[n].l,add(i,x,pool[n].r,m,r));
    }int add(int n,int i,const T&x){
        return roots.emplace_back(add(i,x,n,0,N));
    }int add_t(int t,int i,const T&x){
        return roots.emplace_back(add(i,x,roots[t],0,N));
    }int add(int i,const T&x){
        return roots.emplace_back(add(i,x,roots.back(),0,N));
    }T get(int a,int b,int n,int l,int r){
        if(n==0||r<=a||b<=l)return M::e();
        if(a<=l&&r<=b)return pool[n].data;
        int m=(l+r)>>1;
        return M::op(get(a,b,pool[n].l,l,m),get(a,b,pool[n].r,m,r));
    }T get(int n,int a,int b){
        return get(a,b+1,n,0,N);
    }T get_t(int t,int a,int b){
        return get(a,b+1,roots[t],0,N);
    }T get(int a,int b){
        return get(a,b+1,roots.back(),0,N);
    }int new_tree(){
        return 0;
    }
};