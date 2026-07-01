// LCPArray
struct LCPArray{
    vector<int>isa,lcpa;
    LCPArray(const string&s,const vector<int>&sa):isa(s.size()),lcpa(s.size()-1){
        rep(i,s.size())isa[sa[i]]=i;
        int c=0;
        rep(i,s.size()){
            if(isa[i]){
                while(i+c<s.size()&&sa[isa[i]-1]+c<s.size()&&s[i+c]==s[sa[isa[i]-1]+c])++c;
                lcpa[isa[i]-1]=c,c-=c>0;
            }else c=0;
        }
    }vector<int>get(){
        return lcpa;
    }int operator[](int i){
        return lcpa[i];
    }int size(){
        return lcpa.size();
    }
};