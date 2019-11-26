long long d[10000000];
void calc_p(int n)
{
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if(d[i]==0)
			for (int j = i + i; j <= n; j += i)
			{
				d[j] = 1;
			}
	}
}