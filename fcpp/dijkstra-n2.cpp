int d[2001];
int was[2001];
vector<pair<int, int>> v[2001];
int n;
void dijkstra(int x) {
	for (int i = 0; i < n; i++)
		d[i] = inf;
	d[x] = 0;
	for (int it = 0; it < n; it++)
	{
		int id = -1;
		for (int i = 0; i < n; i++)
			if (!was[i])if (id == -1 || d[id] > d[i])
				id = i;
		was[id] = -1;
		for (auto p : v[id]) {
			int y = p.first;
			int t = p.second;
			d[y] = min(d[y], d[id] + t);
		}
	}
}