	vector<double> res;
	double d = b*b - 4*a*c;
	if(d <= 0)
		return res;
	res.push_back((-b + sqrt(d)) / (2*a));
	res.push_back((-b - sqrt(d)) / (2*a));
	return res;
}
<|endoftext|>