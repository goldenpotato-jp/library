// MaxFlow
struct MaxFlow{
    struct Data{
        int a,b;
        ll c;
    };
    vector<int>level,iter;
    vector<Data>edges;
    vector<vector<Data>>g;
    MaxFlow(int n):g(n),level(n),iter(n){}
    int add_edge(int from,int to,ll cap){
        g[from].emplace_back(to,g[to].size(),cap),g[to].emplace_back(from,g[from].size()-1,0),edges.emplace_back(from,g[from].size()-1,cap);
        return edges.size()-1;
    }ll dfs(int v,int t,ll f){
        if(v==t)return f;
        for(int&i=iter[v];i<g[v].size();++i)if(g[v][i].c&&level[g[v][i].a]==level[v]+1){
            ll d=dfs(g[v][i].a,t,min(f,g[v][i].c));
            if(!d)continue;
            g[v][i].c-=d,g[g[v][i].a][g[v][i].b].c+=d;
            return d;
        }return 0;
    }ll max_flow(int s,int t){
        queue<int>q;
        ll flow=0,f;
        while(1){
            fill(all(level),-1),level[s]=0,q.emplace(s),fill(all(iter),0);
            while(q.size()){
                int v=q.front();q.pop();
                for(auto[a,_,b]:g[v])if(b&&level[a]<0)level[a]=level[v]+1,q.emplace(a);
            }if(level[t]<0)return flow;
            while(f=dfs(s,t,INF))flow+=f;
        }
    }ll get_flow(int id){
        return edges[id].c-g[edges[id].a][edges[id].b].c;
    }
};