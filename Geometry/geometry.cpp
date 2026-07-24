// geometry.cpp
ld EPS=1e-12;
int sgn(ld a){
    return a<-EPS?-1:(a>EPS?1:0);
}struct Point{
    ld x,y;
    Point(ld x=0,ld y=0):x(x),y(y){}
    Point operator-(){
        return{-x,-y};
    }Point operator+(Point b){
        return{x+b.x,y+b.y};
    }Point operator-(Point b){
        return{x-b.x,y-b.y};
    }Point operator*(ld b){
        return{x*b,y*b};
    }Point operator/(ld b){
        return{x/b,y/b};
    }Point operator+=(Point b){
        x+=b.x,y+=b.y;
        return*this;
    }Point operator-=(Point b){
        x-=b.x,y-=b.y;
        return*this;
    }Point operator*=(ld b){
        x*=b,y*=b;
        return*this;
    }Point operator/=(ld b){
        x/=b,y/=b;
        return*this;
    }ld lensq(){
        return x*x+y*y;
    }ld len(){
        return sqrtl(lensq());
    }Point normal(){
        return{x/len(),y/len()};
    }bool is_zero(){
        return sgn(x)==0&&sgn(y)==0;
    }Point nuv(){
        return{-normal().y,normal().x};
    }Point rot(ld rad){
        ld c=cosl(rad),s=sinl(rad);
        return{x*c-y*s,x*s+y*c};
    }ld ang(){
        return atan2l(y,x);
    }
};ld dot(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}ld det(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}ld distsq(Point a,Point b){
    return(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}ld dist(Point a,Point b){
    return sqrtl(distsq(a,b));
}Point operator*(ld a,Point b){
    return{a*b.x,a*b.y};
}bool operator==(Point a,Point b){
    return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
}bool operator!=(Point a,Point b){
    return!(a==b);
}bool operator<(Point a,Point b){
    return sgn(a.x-b.x)?sgn(a.x-b.x)<0:sgn(a.y-b.y)<0;
}int isp(Point a,Point b,Point c){
    int flag=sgn(det(b-a,c-a));
    if(flag==1)return 1;
    if(flag==-1)return-1;
    if(sgn(dot(b-a,c-b))>0)return 2;
    if(sgn(dot(a-b,c-a))>0)return-2;
    return 0;
}int angty(Point a,Point b,Point c){
    ld d=dot(a-b,c-b);
    if(sgn(d)>0)return 0;
    if(sgn(d)<0)return 2;
    return 1;
}struct Line{
	Point begin,end;
	Line(Point begin={0,0},Point end={0,0}):begin(begin),end(end){}
	Line(ld a,ld b,ld c){
		if(sgn(b)==0)begin=Point(-c/a,0),end=Point(-c/a,1);
		else begin=Point(0,-c/b),end=Point(1,-(a+c)/b);
	}Point vec(){
		return end-begin;
	}Point revvec(){
		return begin-end;
	}
};Point line_intersect(Line a,Line b){
	return a.begin+a.vec()*det(b.end-a.begin,b.vec())/det(a.vec(),b.vec());
}bool has_intersect(Line a,Line b){
    return isp(a.begin,a.end,b.begin)*isp(a.begin,a.end,b.end)<=0&&isp(b.begin,b.end,a.begin)*isp(b.begin,b.end,a.end)<=0;
}pair<bool,Point>seg_intersect(Line a,Line b){
    if(!has_intersect(a,b))return{0,{0,0}};
    if(sgn(det(a.vec(),b.vec()))!=0)return{1,line_intersect(a,b)};
    if(isp(a.begin,a.end,b.begin)==0)return{1,b.begin};
    if(isp(a.begin,a.end,b.end)==0)return{1,b.end};
    if(isp(b.begin,b.end,a.begin)==0)return{1,a.begin};
    if(isp(b.begin,b.end,a.end)==0)return{1,a.end};
	return{0,{0,0}};
}ld point_line_dist(Point p,Line l){
	return abs(det(l.vec(),p-l.begin)/l.vec().len());
}ld point_res_dist(Point p,Line r){
    return sgn(dot(p-r.begin,r.vec()))<0?dist(r.begin,p):abs(det(r.vec(),p-r.begin)/r.vec().len());
}ld point_seg_dist(Point p,Line s){
    return sgn(dot(s.vec(),p-s.begin))<0||sgn(dot(s.revvec(),p-s.end))<0?min(dist(p,s.begin),dist(p,s.end)):point_line_dist(p,s);
}ld seg2_dist(Line a,Line b){
	if(has_intersect(a,b))return 0;
	return min({point_seg_dist(a.begin,b),point_seg_dist(a.end,b),point_seg_dist(b.begin,a),point_seg_dist(b.end,a)});
}Point proj(Point a,Line l){
	return l.begin+l.vec()*dot(a-l.begin,l.vec())/l.vec().lensq();
}Point refl(Point a,Line l){
	return a+2*(proj(a,l)-a);
}