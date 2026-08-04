// SCC
struct SCC{
    int n,cnt=0,cur=0;
    vector<bool>on_stack;
    vector<int>id,lowlink,comp,stack;
    vector<vector<int>>g,scc;
    SCC(int n):n(n),g(n),id(n,-1),lowlink(n,-1),comp(n,-1),on_stack(n){
        stack.reverve(n);
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
                stack.pop_back(),on_stack[w]=0,comp[w]=cnt,cur_scc.emplace_back(w);
                if(w==v)break;
            }scc.emplace_back(move(cur_scc)),++cnt;
        }
    }vector<vector<int>>build(){
        rep(i,n)if(id[i]==-1)dfs(i);
        reverse(all(scc));
        rep(i,n)comp[i]=cnt-comp[i]-1;
    }
};