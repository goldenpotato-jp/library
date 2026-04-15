// extend_gcd
ll extend_gcd(ll a,ll b,ll&x,ll&y){
    ll r1=a,r2=b,x1=1,x2=0,y1=0,y2=1;
    while(r2){
        ll q=r1/r2,r3=r1-q*r2,x3=x1-q*x2,y3=y1-q*y2;
        r1=r2,r2=r3,x1=x2,x2=x3,y1=y2,y2=y3;
    }x=x1,y=y1;
    return r1;
}