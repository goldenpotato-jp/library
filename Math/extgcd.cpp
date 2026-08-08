// extgcd
ll extgcd(ll a,ll b,ll&x,ll&y){
    x=1,y=0;
    ll u=0,v=1;
    while(b){
        ll t=a/b;
        a-=t*b,swap(a,b),x-=t*u,swap(x,u),y-=t*v,swap(y,v);
    }return a;
}