// SuffixArray
struct SuffixArray{
    int n;
    vector<int>sa;
    string s;
    SuffixArray(const string&str):s(str){
        s.push_back(0),n=s.size(),sa.resize(n),iota(all(sa),0),sort(all(sa),[&](int a, int b){
            return s[a]==s[b]?a>b:s[a]<s[b];
        });vector<int>classes(n),c(all(s)),cnt(n);
        for(int len=1;len<n;len<<=1){
            for(int i=0;i<n;i++){
                if(i>0&&c[sa[i-1]]==c[sa[i]]&&sa[i-1]+len<n&&c[sa[i-1]+(len>>1)]==c[sa[i]+(len>>1)])classes[sa[i]]=classes[sa[i-1]];
                else classes[sa[i]] = i;
            }iota(all(cnt),0),copy(all(sa),begin(c));
            for(int i=0;i<n;i++){
                int s1=c[i]-len;
                if(s1>=0)sa[cnt[classes[s1]]++]=s1;
            }classes.swap(c);
        }s.pop_back();
    }int operator[](int i){
        return sa[i];
    }
};
// LCPArray
struct LCPArray{
    int n;
    SuffixArray SA;
    vector<int>lcpa,rank;
    LCPArray(const SuffixArray&sa):n(sa.n),lcpa(n),rank(n),SA(sa){
        rep(i,n)rank[SA[i]]=i;
        for(int i=0,h=0;i<n-1;i++){
            int j=SA[rank[i]-1];
            if(h)--h;
            while(max(i,j)+h<n-1&&SA.s[i+h]==SA.s[j+h])++h;
            lcpa[rank[i]-1]=h;
        }
    }int operator[](int i){
        return lcpa[i];
    }
};