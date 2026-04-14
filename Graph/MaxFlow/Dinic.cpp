// Dinic
struct Dinic{
    int n;
    vector<int>level,iter;
    vector<tuple<ll,ll,ll>>edges;
    vector<vector<tuple<int,ll,int>>>g;
    Dinic(int n):n(n),g(n),level(n),iter(n){}
    int add_edge(int from,int to,ll cap){
        ll idx=g[from].size();
        g[from].emplace_back(to,cap,g[to].size());
        g[to].emplace_back(from,0,idx);
        edges.emplace_back(from,idx,cap);
        return edges.size()-1;
    }void bfs(int s){
        fill(all(level),-1);
        queue<int>q;
        level[s]=0;
        q.push(s);
        while(!q.empty()){
            int v=q.front();q.pop();
            for(auto&e:g[v])if(get<1>(e)&&level[get<0>(e)]<0){
                level[get<0>(e)]=level[v]+1;
                q.push(get<0>(e));
            }
        }
    }ll dfs(int v,int t,ll f){
        if(v==t)return f;
        for(int&i=iter[v];i<g[v].size();++i){
            auto&[to,cap,rev]=g[v][i];
            if(cap&&level[to]==level[v]+1){
                ll d=dfs(to,t,min(f,cap));
                if(d){
                    cap-=d;
                    get<1>(g[to][rev])+=d;
                    return d;
                }
            }
        }return 0;
    }ll max_flow(int s,int t){
        ll flow=0;
        while(1){
            bfs(s);
            if(level[t]<0)return flow;
            fill(all(iter),0);
            ll f;
            while(f=dfs(s,t,INF))flow+=f;
        }
    }ll get_flow(int id){
        auto[from,idx,cap]=edges[id];
        return cap-get<1>(g[from][idx]);
    }
};