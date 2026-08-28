// SA_IS
struct SA_IS{
    vector<int>sa;
    SA_IS(const string&s){
        int n=s.size();
        vector<int>v(n+1);
        rep(i,n)v[i]=s[i]+1;
        sa=sa_is(v,257);
    }template<class T>SA_IS(const vector<T>&v){
        int n=v.size(),k=1;
        vector<int>idx(n),nv(n+1);
        iota(all(idx),0),sort(all(idx),[&](int l,int r){return v[l]<v[r];});
        rep(i,n)k+=i>0&&v[idx[i-1]]!=v[idx[i]],nv[idx[i]]=k;
        sa=sa_is(nv,k+1);
    }template<class T>SA_IS(const vector<T>&v,int upper){
        int n=v.size();
        vector<int>nv(n+1);
        rep(i,n)nv[i]=v[i]+1;
        sa=sa_is(nv,upper+1);
    }vector<int>sa_is(const vector<int>&v,int upper){
        int n=v.size(),m=0;
        if(n==0)return{};
        if(n==1)return{0};
        vector<bool>ls(n);
        vector<int>res(n,-1),sum_l(upper+1),sum_s(upper+1),lms_map(n,-1),lms;
        for(int i=n-2;i>=0;--i)ls[i]=v[i]==v[i+1]?ls[i+1]:v[i]<v[i+1];
        rep(i,n)++(ls[i]?sum_l[v[i]+1]:sum_s[v[i]]);
        rep(i,upper)sum_s[i]+=sum_l[i],sum_l[i+1]+=sum_s[i];
        auto induce=[&](const vector<int>&lms){
            vector<int>buf=sum_s;
            fill(all(res),-1);
            for(int e:lms)if(e!=n)res[buf[v[e]]++]=e;
            buf=sum_l,res[buf[v[n-1]]++]=n-1;
            rep(i,n){
                int val=res[i];
                if(val>0&&!ls[val-1])res[buf[v[val-1]]++]=val-1;
            }buf=sum_l;
            for(int i=n-1;i>=0;--i){
                int val=res[i];
                if(val>0&&ls[val-1])res[--buf[v[val-1]+1]]=val-1;
            }
        };rep(i,n-1)if(!ls[i]&&ls[i+1])lms_map[i+1]=m++;
        lms.reserve(m);
        rep(i,n-1)if(!ls[i]&&ls[i+1])lms.emplace_back(i+1);
        induce(lms);
        if(m==0)return res;
        vector<int>sorted_lms,rec_v(m);
        sorted_lms.reserve(m);
        for(int e:res)if(lms_map[e]!=-1)sorted_lms.emplace_back(e);
        int rec_upper=0;
        rec_v[lms_map[sorted_lms[0]]]=0;
        rep(i,m-1){
            int l=sorted_lms[i],r=sorted_lms[i+1],end_l=lms_map[l]+1<m?lms[lms_map[l]+1]:n,end_r=(lms_map[r]+1<m)?lms[lms_map[r]+1]:n;
            if(end_l-l==end_r-r){
                while(l<end_l&&v[l]==v[r])++l,++r;
                rec_upper+=l==n||v[l]!=v[r];
            }else++rec_upper;
            rec_v[lms_map[sorted_lms[i+1]]]=rec_upper;
        }auto rec_sa=sa_is(rec_v,rec_upper);
        rep(i,m)sorted_lms[i]=lms[rec_sa[i]];
        induce(sorted_lms);
        return res;
    }int operator[](int i){
        return sa[i];
    }
};