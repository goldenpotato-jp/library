// randll
ll randll(ll l,ll r){
    ll x=0;
    rep(i,4)x=(x<<15)|(rand()&0x7FFF);
    return l+x%(r-l+1);
}