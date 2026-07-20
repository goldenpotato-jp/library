// LCPArray
struct LCPArray{
    vector<int>z;
    LCPArray(const string&s):z(s.size()){
        z[0]=s.size();
        int l=0,r=0;
        for(int i=1;i<s.size();++i){
            if(z[i-l]>=r-i){
                chmax(r,i);
                while(r<s.size()&&s[r]==s[r-i])++r;
                z[i]=r-i,l=i;
            }else z[i]=z[i-l];
        }
    }template<class T>
    LCPArray(const vector<T>&v):z(v.size()){
        z[0]=v.size();
        int l=0,r=0;
        for(int i=1;i<v.size();++i){
            if(z[i-l]>=r-i){
                chmax(r,i);
                while(r<v.size()&&v[r]==v[r-i])++r;
                z[i]=r-i,l=i;
            }else z[i]=z[i-l];
        }
    }int operator[](int i){
        return z[i];
    }
};