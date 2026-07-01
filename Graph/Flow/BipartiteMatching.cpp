// BipMatch
struct BipMatch{
    int L,R;
    vector<int>d,ml,mr;
    vector<vector<int>>g;
    BipMatch(int L,int R):L(L),R(R),g(L),d(L),ml(L,-1),mr(R,-1){}
    void add_edge(int l,int r){
        g[l].emplace_back(r);
    }bool bfs(){
        queue<int>q;
        bool res=0;
        rep(i,L){
            if(ml[i]==-1)d[i]=0,q.emplace(i);
            else d[i]=inf;
        }while(q.size()){
            int v=q.front();q.pop();
            for(auto v2:g[v]){
                int v3=mr[v2];
                if(v3==-1)res=1;
                else if(d[v3]==inf)d[v3]=d[v]+1,q.push(v3);
            }
        }return res;
    }bool dfs(int v){
        for(auto v2:g[v]){
            int v3=mr[v2];
            if(v3==-1||d[v3]==d[v]+1&&dfs(v3)){
                ml[v]=v2,mr[v2]=v;
                return 1;
            }
        }d[v]=inf;
        return 0;
    }int max_match(){
        int res=0;
        while(bfs())rep(i,L)if(ml[i]==-1&&dfs(i))++res;
        return res;
    }bool get_match(int u,int v){
        return ml[u]==v;
    }
};