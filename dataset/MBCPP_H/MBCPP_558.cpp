	int digitDistance = 0;
	while (n1 > 0) {
		digitDistance = digitDistance + (n2 % 10 - n1 % 10);
		n1 = n1 / 10;
		n2 = n2 / 10;
	}
	return digitDistance;
}