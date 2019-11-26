ll c[102][102];
ll f[102][102];
int was[102];
int p[102];
vector <vector<int>> v(102);
int t;
ll dfs(int x, ll capacity) {
	if (x == t) {
		return capacity;
	}
	was[x] = 1;
	for (auto y : v[x]) {
		ll flow = min(c[x][y] - f[x][y], capacity);
		if (!was[y] && flow > 0) {
			ll delta = dfs(y, flow);
			if (delta == 0)
				continue;
			p[x] = y;
			return delta;
		}
	}
	return 0;
}



void calc(int x, ll cap) {

	int y = x;

	while (y != t) {
		f[y][p[y]] += cap;
		f[p[y]][y] -= cap;
		y = p[y];
	}

}
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b; ll w;
		cin >> a >> b >> w;
		c[a][b] = w;
		c[b][a] = w;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	ll ans = 0;
	t = n;
	while (ll cap = dfs(1, 100000000000000000)) {
		calc(1, cap);
		ans += cap;
		memset(was, 0, sizeof(was));
		memset(p, 0, sizeof(p));
	}

	cout << ans;
	return 0;
}