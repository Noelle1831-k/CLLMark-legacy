	int D = b*b - 4*a*c;
	if (D < 0)
		return "No";
	else if (D == 0)
		return "Yes";
	else {
		int D_sqrt = sqrt(D);
		if (D_sqrt*D_sqrt == D)
			return "Yes";
		else
			return "No";
	}
}
<|endoftext|>