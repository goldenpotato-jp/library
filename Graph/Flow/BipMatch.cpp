// BipMatch
struct BipMatch{
    int L,R;
    vector<int>d,ml,mr;
    vector<vector<int>>g;
    queue<int>q;
    BipMatch(int L,int R):L(L),R(R),g(L),d(L),ml(L,-1),mr(R,-1){}
    void add_edge(int l,int r){
        g[l].emplace_back(r);
    }bool bfs(){
        bool res=0;
        rep(i,L){
            if(ml[i]==-1)d[i]=0,q.emplace(i);
            else d[i]=inf;
        }while(q.size()){
            for(auto v2:g[q.front()]){
                if(mr[v2]==-1)res=1;
                else if(d[mr[v2]]==inf)d[mr[v2]]=d[q.front()]+1,q.push(mr[v2]);
            }q.pop();
        }return res;
    }bool dfs(int v){
        for(auto v2:g[v])if(mr[v2]==-1||d[mr[v2]]==d[v]+1&&dfs(mr[v2])){
            ml[v]=v2,mr[v2]=v;
            return 1;
        }d[v]=-1;
        return 0;
    }int max_match(){
        int res=0;
        while(bfs())rep(i,L)res+=ml[i]==-1&&dfs(i);
        return res;
    }bool get_match(int u,int v){
        return ml[u]==v;
    }
};