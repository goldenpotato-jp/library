// SCC
struct SCC{
    int n,cnt=0,cur=0;
    vector<bool>on_stack;
    vector<int>id,lowlink,cmp,stack;
    vector<vector<int>>g,scc;
    SCC(int N):n(N),g(n),id(n,-1),lowlink(n,-1),cmp(n,-1),on_stack(n){
        stack.reserve(n);
    }void add_edge(int from,int to){
        g[from].emplace_back(to);
    }void dfs(int v){
        id[v]=lowlink[v]=cur++,stack.emplace_back(v),on_stack[v]=1;
        for(int next:g[v]){
            if(id[next]==-1)dfs(next),chmin(lowlink[v],lowlink[next]);
            else if(on_stack[next])chmin(lowlink[v],id[next]);
        }if(id[v]==lowlink[v]){
            vector<int>cur_scc;
            while(1){
                int w=stack.back();
                stack.pop_back(),on_stack[w]=0,cmp[w]=cnt,cur_scc.emplace_back(w);
                if(w==v)break;
            }scc.emplace_back(move(cur_scc)),++cnt;
        }
    }void build(){
        rep(i,n)if(id[i]==-1)dfs(i);
        reverse(all(scc));
        rep(i,n)cmp[i]=cnt-cmp[i]-1;
    }
};