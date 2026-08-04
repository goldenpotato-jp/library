// TwoSAT
struct TwoSAT{
    bool flag=1;
    int n,n2,cnt=0,cur=0;
    vector<bool>on_stack;
    vector<int>id,lowlink,cmp,stack,res;
    vector<vector<int>>g;
    TwoSAT(int n):n(n),n2(n<<1),on_stack(n2),id(n2,-1),lowlink(n2,-1),cmp(n2,-1),res(n2),g(n2){
        stack.reserve(n2);
    }void add_edge(int from,int to){
        g[from].emplace_back(to);
    }void dfs(int v){
        id[v]=lowlink[v]=cur++,stack.emplace_back(v),on_stack[v]=1;
        for(int next:g[v]){
            if(id[next]==-1)dfs(next),chmin(lowlink[v],lowlink[next]);
            else if(on_stack[next])chmin(lowlink[v],id[next]);
        }if(id[v]==lowlink[v]){
            while(1){
                int w=stack.back();
                stack.pop_back(),on_stack[w]=0,cmp[w]=cnt;
                if(w==v)break;
            }++cnt;
        }
    }int get_not(int x){
        return x<n?x+n:x-n;
    }void add_closure(bool bx,int x,bool by,int y){
        if(!bx)x=get_not(x);
        if(!by)y=get_not(y);
        add_edge(get_not(x),y),add_edge(get_not(y),x);
    }void build(){
        rep(i,n2)if(id[i]==-1)dfs(i);
        rep(i,n){
            if(cmp[i]==cmp[i+n])flag=0;
            res[i]=cmp[i]<cmp[i+n];
        }
    }
};