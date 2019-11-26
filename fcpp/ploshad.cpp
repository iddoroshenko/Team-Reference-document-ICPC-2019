int n;
cin >> n;
vector<pair<int, int>>a(n);
for (int i = 0; i < n; i++) {
	cin >> a[i].X >> a[i].Y;
}
double s = 0;
for (int i = 0; i < n - 1; i++) {
	s += (a[i + 1].X - a[i].X)*(a[i + 1].Y + a[i].Y);
}
s += (a[0].X - a[n-1].X)*(a[0].Y + a[n-1].Y);