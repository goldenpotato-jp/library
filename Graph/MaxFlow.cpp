// MaxFlow
struct MaxFlow{
    int n;
    vector<int>level,iter;
    vector<tuple<int,int,ll>>edges;
    vector<vector<tuple<int,ll,int>>>g;
    MaxFlow(int n):n(n),g(n),level(n),iter(n){}
    int add_edge(int from,int to,ll cap){
        g[from].emplace_back(to,cap,g[to].size()),g[to].emplace_back(from,0,g[from].size()-1),edges.emplace_back(from,g[from].size()-1,cap);
        return edges.size()-1;
    }ll dfs(int v,int t,ll f){
        if(v==t)return f;
        for(int&i=iter[v];i<g[v].size();++i)if(get<1>(g[v][i])&&level[get<0>(g[v][i])]==level[v]+1){
            ll d=dfs(get<0>(g[v][i]),t,min(f,get<1>(g[v][i])));
            if(!d)continue;
            get<1>(g[v][i])-=d,get<1>(g[get<0>(g[v][i])][get<2>(g[v][i])])+=d;
            return d;
        }return 0;
    }ll max_flow(int s,int t){
        queue<int>q;
        ll flow=0,f;
        while(1){
            fill(all(level),-1),level[s]=0,q.push(s),fill(all(iter),0);
            while(!q.empty()){
                int v=q.front();q.pop();
                for(auto&e:g[v])if(get<1>(e)&&level[get<0>(e)]<0)level[get<0>(e)]=level[v]+1,q.push(get<0>(e));
            }if(level[t]<0)return flow;
            while(f=dfs(s,t,INF))flow+=f;
        }
    }ll get_flow(int id){
        return get<2>(edges[id])-get<1>(g[get<0>(edges[id])][get<1>(edges[id])]);
    }
};