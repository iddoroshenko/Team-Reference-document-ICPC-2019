int lcp (int i, int j) {
	int ans = 0;
	for (int k=log_n; k>=0; --k)
		if (c[k][i] == c[k][j]) {
			ans += 1<<k;
			i += 1<<k;
			j += 1<<k;
		}
	return ans;
}