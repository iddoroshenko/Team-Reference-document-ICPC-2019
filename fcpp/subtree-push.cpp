void push (int v) {
	if (t[v] != -1) {
		t[v*2+1] = t[v*2+2] = t[v];
		t[v] = -1;
	}
}
 
void update (int v, int vl, int vr, int l, int r, int color) {
	if (l > r)
		return;
	if (l == vl && vr == r)
		t[v] = color;
	else {
		push (v);
		int c = vl + (vr- vl)/2;
		update (v*2+1, vl, c, l, min(r,c), color);
		update (v*2+2, c+1, vr, max(l,c+1), r, color);
	}
}
 
int get (int v, int vl, int vr, int pos) {
	if (vl == vr)
		return t[v];
	push (v);
	int c = vl + (vr- vl)/2;
	if (pos <= c)
		return get (v*2+1, vl, c, pos);
	else
		return get (v*2+2, c+1, vr, pos);
}