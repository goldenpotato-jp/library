// LCPArray
struct LCPArray{
    int n;
    vector<int>v,sa,isa,lcpa;
    LCPArray(const string&s,const vector<int>&sa):n(s.size()),v(n),sa(sa),isa(n+1),lcpa(n){
        rep(i,n)v[i]=s[i];
        build();
    }template<class T>LCPArray(const vector<T>&v,const vector<int>&sa):n(v.size()),v(v),sa(sa),isa(n+1),lcpa(n){
        build();
    }void build(){
        rep(i,n+1)isa[sa[i]]=i;
        int c=0;
        rep(i,n){
            int j=isa[i];
            if(j>0){
                int k=sa[j-1];
                while(i+c<n&&k+c<n&&v[i+c]==v[k+c])++c;
                lcpa[j-1]=c,c-=c>0;
            }else c=0;
        }
    }int operator[](int i){
        return lcpa[i];
    }
};