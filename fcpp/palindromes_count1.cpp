vector<int> d1 (n);
int l=0, r=-1;
for (int i=0; i<n; ++i) {
	int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
	while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	d1[i] = k--;
	if (i+k > r)
		l = i-k,  r = i+k;
}