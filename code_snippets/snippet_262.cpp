	map<int, int> M;
	M[1] = 1;
	for (int i = 2; i < p; i++) {
		M[i] = (M[i - 1] * i) % p;
	}
	map<int, int> MInv;
	MInv[1] = 1;
	for (int i = 2; i < p; i++) {
		MInv[i] = (MInv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M2;
	M2[1] = 1;
	for (int i = 2; i < p; i++) {
		M2[i] = (M2[i - 1] * 2) % p;
	}
	map<int, int> M2Inv;
	M2Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M2Inv[i] = (M2Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23;
	M23[1] = 1;
	for (int i = 2; i < p; i++) {
		M23[i] = (M23[i - 1] * 23) % p;
	}
	map<int, int> M23Inv;
	M23Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23Inv[i] = (M23Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2;
	M23M2[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2[i] = (M23M2[i - 1] * 23 * 2) % p;
	}
	map<int, int> M23M2Inv;
	M23M2Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2Inv[i] = (M23M2Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2M23;
	M23M2M23[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23[i] = (M23M2M23[i - 1] * 23 * 2 * 23) % p;
	}
	map<int, int> M23M2M23Inv;
	M23M2M23Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23Inv[i] = (M23M2M23Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2M23M2;
	M23M2M23M2[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2[i] = (M23M2M23M2[i - 1] * 23 * 2 * 23 * 2) % p;
	}
	map<int, int> M23M2M23M2Inv;
	M23M2M23M2Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2Inv[i] = (M23M2M23M2Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2M23M2M23;
	M23M2M23M2M23[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23[i] = (M23M2M23M2M23[i - 1] * 23 * 2 * 23 * 2 * 23) % p;
	}
	map<int, int> M23M2M23M2M23Inv;
	M23M2M23M2M23Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23Inv[i] = (M23M2M23M2M23Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2M23M2M23M2;
	M23M2M23M2M23M2[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23M2[i] = (M23M2M23M2M23M2[i - 1] * 23 * 2 * 23 * 2 * 23 * 2) % p;
	}
	map<int, int> M23M2M23M2M23M2Inv;
	M23M2M23M2M23M2Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23M2Inv[i] = (M23M2M23M2M23M2Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2M23M2M23M2M23;
	M23M2M23M2M23M2M23[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23M2M23[i] = (M23M2M23M2M23M2M23[i - 1] * 23 * 2 * 23 * 2 * 23 * 2 * 23) % p;
	}
	map<int, int> M23M2M23M2M23M2M23Inv;
	M23M2M23M2M23M2M23Inv[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23M2M23Inv[i] = (M23M2M23M2M23M2M23Inv[p % i] * (p - p / i)) % p;
	}
	map<int, int> M23M2M23M2M23M2M23M2;
	M23M2M23M2M23M2M23M2[1] = 1;
	for (int i = 2; i < p; i++) {
		M23M2M23M2M23M2M23M