pair <double, double> linesIntetseptionPoint(double a1, double b1, double c1, double a2, double b2, double c2)
{
	pair<double, double> xy;

	if (a1 == 0)
	{
		xy.second = c1 / b1;
		xy.first = (c2 - b2 * xy.second) / a2;
		return xy;
	}

	if (a2 == 0)
	{
		xy.second = c2 / b2;
		xy.first = (c1 - b1 * xy.second) / a1;
		return xy;
	}

	xy.second = (c2*a1 - a2 * c1) / (b2*a1 - a2 * b1);
	xy.first = (c1 - b1 * xy.second) / a1;
	return xy;
}