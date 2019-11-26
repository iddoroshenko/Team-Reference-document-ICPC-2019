int d[3001]; 
vector<pair<int, int>> v[3001]; 
bool f(int x, int y) { 
	if (d[x] != d[y]) 
		return d[x] < d[y]; 
	return x < y; 
} 
set <int, bool(*)(int, int)> s(f); 
void dijkstra(int x) { 
	x--;
	for (int i = 0; i <= n; i++) 
	{ 
		d[i] = inf; 
	} 
	d[x] = 0; 
	s.insert(x); 
	while (!s.empty()) { 
		int x = *s.begin(); 
		s.erase(x); 
		for (auto p : v[x]) { 
			int y = p.first; 
			int t = p.second; 
			if (d[y] > d[x] + t) { 
				s.erase(y); 
				d[y] = d[x] + t; 
				s.insert(y); 
			} 
		} 
	} 
} 