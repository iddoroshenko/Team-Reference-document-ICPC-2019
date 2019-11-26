const int mod = 1000000000 + 7;
const int q = 1009; 
vector <ll> ph;
vector <ll> pq;
void pq_put()
{
	pq.pb(1);
	for (size_t i = 1; i < 100000; ++i)
		pq.pb((pq[i - 1] * q) % mod);
}

ll hashing(string s)
{
	ll h = 0;
	if (ph.size())h = ph.back();
	for (int i = 0; i < s.size(); i++)
	{
		h = (h * q + s[i]) % mod;
		ph.pb(h);
	}
	re h;
}

ll get(int l, int r)
{
	ll ans = ph[r];
	if (l) {
		ans -= ph[l - 1] * pq[r - l + 1] % mod;
		if (ans < 0)ans += mod;
	}
	re ans;
}