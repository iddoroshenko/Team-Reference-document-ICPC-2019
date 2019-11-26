ll t[4*100000];
void build(int v, int vl,int vr, vi& a){
    if(vl == vr){
        t[v] = a[vl];
        return;
    }
    int c = vl + (vr- vl)/2;
    build(2*v+1,vl,c,a);
    build(2*v+2,c+1,vr,a);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
ll sum(int v, int vl, int vr, int l, int r){
    if(l > vr || r < vl){
        return -inf - 1;
    }
    if(l <= vl && vr <= r)
        return t[v];
    int c = vl + (vr- vl)/2;
    ll q1 = sum(2*v+1, vl, c, l,r);
    ll q2 = sum(2*v+2,c+1,vr,l,r);
    return max(q1, q2);
}
void modify(int v, int vl, int vr, int pos, int x){
    if(vl == vr){
        t[v] = x;
        return;
    }
    int c = vl + (vr- vl)/2;
    if(c >= pos)
        modify(2*v + 1, vl, c, pos,x);
    else
        modify(2*v + 2,c +1,vr,pos,x);
    t[v] = max(t[2*v+1], t[2*v+2]);
}