// BipartiteMatching
struct BipartiteMatching{
    struct Data{
        int a,b;
    };
    int L,R;
    vector<int>level,iter,ml,mr;
    vector<vector<int>>g;
    vector<Data>edges;
    BipartiteMatching(int L,int R):L(L),R(R),g(L),level(L),iter(L),ml(L,-1),mr(R,-1){}
    int add_edge(int l,int r){
        g[l].emplace_back(r),edges.emplace_back(l,g[l].size()-1);
        return edges.size()-1;
    }bool dfs(int v){
        for(int&i=iter[v];i<g[v].size();++i)if(mr[g[v][i]]<0||level[mr[g[v][i]]]==level[v]+1&&dfs(mr[g[v][i]])){
            ml[v]=g[v][i],mr[g[v][i]]=v;
            return 1;
        }return 0;
    }int max_flow(){
        rep(u,L)for(auto v:g[u])if(mr[v]<0){
            ml[u]=v,mr[v]=u;
            break;
        }queue<int>q;
        while(1){
            fill(all(level),-1),fill(all(iter),0);
            rep(i,L)if(ml[i]<0)level[i]=0,q.push(i);
            while(q.size()){
                int u=q.front();q.pop();
                for(auto e:g[u])if(mr[e]>=0&&level[mr[e]]<0)level[mr[e]]=level[u]+1,q.emplace(mr[e]);
            }bool updated=0;
            rep(i,L)updated|=ml[i]<0&&dfs(i);
            if(!updated)break;
        }int res=0;
        rep(i,L)res+=ml[i]>=0;
        return res;
    }bool get_flow(int id){
        return ml[edges[id].a]==g[edges[id].a][edges[id].b];
    }
};
