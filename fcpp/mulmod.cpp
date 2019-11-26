ll mod;
long long mulmod(long long n, long long p){
    if (p == 0)
        return 0;
    if (p == 1)
        return n % mod;
    long long tmp = mulmod(n, p/2);
    long long ans = (tmp + tmp) % mod;
    if (p % 2 == 1)
        ans = (ans + n) % mod;
    return ans;
}