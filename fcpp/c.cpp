int C (int n, int k) {
	int res = 1;
	for (int i=n-k+1; i<=n; ++i)
		res *= i;
	for (int i=2; i<=k; ++i)
		res /= i;
}
int C (int n, int k) {//better
	double res = 1;
	for (int i=1; i<=k; ++i)
		res = res * (n-k+i) / i;
	return (int) (res + 0.01);
}
//Pascal triangle
const int maxn = ...;
int C[maxn+1][maxn+1];
for (int n=0; n<=maxn; ++n) {
	C[n][0] = C[n][n] = 1;
	for (int k=1; k<n; ++k)
		C[n][k] = C[n-1][k-1] + C[n-1][k];
}