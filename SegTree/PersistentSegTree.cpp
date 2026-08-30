// PersistentSegTree
template<class M,int NODES=2000000>
struct PersistentSegTree{
    using T=typename M::T;
    struct Node{
        T data;
        Node*l,*r;
        Node(){}
        Node(const T&data):data(data),l(nullptr),r(nullptr){}
    };Node*pool=new Node[NODES],*nil;
    int pid=0,N;
    vector<Node*>roots;
    PersistentSegTree(int N):N(N){
        nil=my_new(M::e()),nil->l=nil->r=nil,roots.reserve(262144),roots.emplace_back(nil);
    }PersistentSegTree(const vector<T>&v):N(v.size()){
        nil=my_new(M::e()),nil->l=nil->r=nil,roots.reserve(262144),roots.emplace_back(build(0,v.size(),v));
    }Node*my_new(const T&data){
        pool[pid].data=data,pool[pid].l=pool[pid].r=nil;
        return&pool[pid++];
    }Node*merge(Node*l,Node*r){
        pool[pid].data=M::op(l->data,r->data),pool[pid].l=l,pool[pid].r=r;
        return&pool[pid++];
    }Node*build(int l,int r,const vector<T>&v){
        if(l+1==r)return my_new(v[l]);
        int m=(l+r)>>1;
        return merge(build(l,m,v),build(m,r,v));
    }Node*update(int i,const T&x,Node*n,int l,int r){
        if(l+1==r)return my_new(x);
        int m=(l+r)>>1;
        if(i<m)return merge(update(i,x,n->l,l,m),n->r);
        return merge(n->l,update(i,x,n->r,m,r));
    }Node*update(Node*n,int i,const T&x){
        return roots.emplace_back(update(i,x,n,0,N));
    }Node*update(int t,int i,const T&x){
        return roots.emplace_back(update(i,x,roots[t],0,N));;
    }Node*update(int i,const T&x){
        return roots.emplace_back(update(i,x,roots.back(),0,N));
    }Node*add(int i,const T&x,Node*n,int l,int r){
        if(l+1==r)return my_new(M::op(x,n->data));
        int m=(l+r)>>1;
        if(i<m)return merge(add(i,x,n->l,l,m),n->r);
        return merge(n->l,add(i,x,n->r,m,r));
    }Node*add(Node*n,int i,const T&x){
        return roots.emplace_back(add(i,x,n,0,N));
    }Node*add(int t,int i,const T&x){
        return roots.emplace_back(add(i,x,roots[t],0,N));
    }Node*add(int i,const T&x){
        return roots.emplace_back(add(i,x,roots.back(),0,N));
    }T get(int a,int b,Node*n,int l,int r){
        if(n==nil||r<=a||b<=l)return M::e();
        if(a<=l&&r<=b)return n->data;
        int m=(l+r)>>1;
        return M::op(get(a,b,n->l,l,m),get(a,b,n->r,m,r));
    }T get(Node*n,int a,int b){
        return get(a,b+1,n,0,N);
    }T get(int t,int a,int b){
        return get(a,b+1,roots[t],0,N);
    }T get(int a,int b){
        return get(a,b+1,roots.back(),0,N);
    }Node*new_tree(){
        return nil;
    }int ver(){
        return roots.size()-1;
    }
};