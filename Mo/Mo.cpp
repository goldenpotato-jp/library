// Mo
struct Mo{
    int width;
    vector<int>left,right,order;
    Mo(int N,int Q):order(Q){
        width=max<int>(1,1.*N/max<ld>(1.,sqrt(Q/1.5))),iota(all(order),0);
    }void insert(int l, int r){
        left.emplace_back(l),right.emplace_back(r+1);
    }template<typename AL,typename AR,typename DL,typename DR,typename REM>
    void run(AL&add_left,AR&add_right,DL&delete_left,DR&delete_right,REM&rem){
        sort(all(order),[&](int a,int b){
            int ablock=left[a]/width,bblock=left[b]/width;
            if(ablock!=bblock)return ablock<bblock;
            if(ablock&1)return right[a]<right[b];
            return right[a]>right[b];
        });int nl=0,nr=0;
        for(auto idx:order){
            while(nl>left[idx])add_left(--nl);
            while(nr<right[idx])add_right(nr++);
            while(nl<left[idx])delete_left(nl++);
            while(nr>right[idx])delete_right(--nr);
            rem(idx);
        }
    }
};