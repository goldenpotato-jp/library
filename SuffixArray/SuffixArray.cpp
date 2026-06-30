// SuffixArray
struct SuffixArray{
    vector<int>sa;
    SuffixArray(const string&s){
        vector<int>v(s.size());
        rep(i,s.size())v[i]=s[i];
        sa=sa_is(v,127);
    }template<class T>
    SuffixArray(const vector<T>&s){
        vector<int>idx(s.size()),v(s.size());
        iota(all(idx),0),sort(all(idx),[&](int l, int r){return s[l]<s[r];});
        int n=0;
        rep(i,s.size())n+=i>0&&s[idx[i-1]]!=s[idx[i]],v[idx[i]]=n;
        sa=sa_is(v,n);
    }int operator[](int i){
        return sa[i];
    }int size(){
        return sa.size();
    }vector<int>sa_is(const vector<int>&s,int n){
        if(s.empty())return{};
        if(s.size()==1)return{0};
        if(s.size()==2){
            if(s[0]<s[1])return{0,1};
            else return{1,0};
        }vector<bool>ls(s.size());
        vector<int>res(s.size(),-1),sl(n+1),ss(n+1),lms_map(s.size()+1,-1),lms;
        for(int i=s.size()-2;i+1;--i)ls[i]=s[i]==s[i+1]?ls[i+1]:s[i]<s[i+1];
        rep(i,s.size())++(ls[i]?sl[s[i]+1]:ss[s[i]]);
        rep(i,n)ss[i]+=sl[i],sl[i+1]+=ss[i];
        ss[n]+=sl[n];
        auto induce=[&](const vector<int>&lms){
            vector<int>buf;
            fill(all(res),-1),buf=ss;
            for(auto e:lms)if(e!=s.size())res[buf[s[e]]++]=e;
            buf=sl,res[buf[s[s.size()-1]]++]=s.size()-1;
            rep(i,s.size())if(res[i]>0&&!ls[res[i]-1])res[buf[s[res[i]-1]]++]=res[i]-1;
            buf=sl;
            for(int i=s.size()-1;i+1;--i)if(res[i]>0&&ls[res[i]-1])res[--buf[s[res[i]-1]+1]]=res[i]-1;
        };
        int m=0;
        rep(i,s.size()-1)if(!ls[i]&&ls[i+1])lms_map[i+1]=m++;
        lms.reserve(m);
        rep(i,s.size()-1)if(!ls[i]&&ls[i+1])lms.emplace_back(i+1);
        induce(lms);
        if(m){
            vector<int>sorted_lms,s2(m);
            sorted_lms.reserve(m);
            for(int e:res)if(lms_map[e]>-1)sorted_lms.emplace_back(e);
            int n2=0;
            s2[lms_map[sorted_lms[0]]]=0;
            rep(i,m-1){
                bool diff=0;
                int l=sorted_lms[i],r=sorted_lms[i+1],end_l=lms_map[l]+1<m?lms[lms_map[l]+1]:s.size(),end_r=(lms_map[r]+1<m)?lms[lms_map[r]+1]:s.size();
                if(end_l-l==end_r-r){
                    while(l<end_l&&s[l]==s[r])++l,++r;
                    if(l==s.size()||s[l]!=s[r])diff=1;
                }else diff=1;
                n2+=diff,s2[lms_map[sorted_lms[i+1]]]=n2;
            }
            auto sa2=sa_is(s2,n2);
            rep(i,m)sorted_lms[i]=lms[sa2[i]];
            induce(sorted_lms);
        }return res;
    }
};