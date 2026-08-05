// MaxFlow
struct MaxFlow{
    struct EdgePos{
        int from,index;
    };struct Edge{
        int to,rev;
        ll cap;
    };vector<int>level,iter;
    vector<EdgePos>edges;
    vector<vector<Edge>>g;
    queue<int>q;
    MaxFlow(int n):g(n),level(n),iter(n){}
    void add_edge(int from,int to,ll cap){
        g[from].emplace_back(to,g[to].size(),cap),g[to].emplace_back(from,g[from].size()-1,0),edges.emplace_back(from,g[from].size()-1);
    }bool bfs(int s,int t){
        fill(all(level),-1),level[s]=0,q.emplace(s),fill(all(iter),0);
        while(q.size()){
            for(auto e:g[q.front()])if(e.cap&&level[e.to]<0)level[e.to]=level[q.front()]+1,q.emplace(e.to);
            q.pop();
        }return level[t]+1;
    }ll dfs(int v,int t,ll limit){
        if(v==t)return limit;
        for(int&i=iter[v];i<g[v].size();++i)if(g[v][i].cap&&level[g[v][i].to]==level[v]+1){
            ll flow=dfs(g[v][i].to,t,min(limit,g[v][i].cap));
            if(!flow)continue;
            g[v][i].cap-=flow,g[g[v][i].to][g[v][i].rev].cap+=flow;
            return flow;
        }return 0;
    }ll max_flow(int s,int t){
        ll res=0,flow;
        while(bfs(s,t))while(flow=dfs(s,t,INF))res+=flow;
        return res;
    }ll get_flow(int i){
        return g[g[edges[i].from][edges[i].index].to][g[edges[i].from][edges[i].index].rev].cap;
    }
};