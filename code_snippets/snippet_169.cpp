	for (int i = 0; i < list.size(); i++) {
		if (list[i] > num) {
			return true;
		}
	}
	return false;
}
int cubes(int N) {
	int result = 0;
	for (int i = 0; i <= N; i++) {
		result += pow(i, 3);
	}
	return result;
}
int oddCubes(int N) {
	int result = 0;
	for (int i = 1; i <= N; i += 2) {
		result += pow(i, 3);
	}
	return result;
}
int evenCubes(int N) {
	int result = 0;
	for (int i = 0; i <= N; i += 2) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples(int N, int M) {
	int result = 0;
	for (int i = 0; i <= N; i++) {
		if (i % M == 0) {
			result += pow(i, 3);
		}
	}
	return result;
}
int cubesOfMultiples2(int N, int M) {
	int result = 0;
	for (int i = 0; i <= N; i += M) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples3(int N, int M) {
	int result = 0;
	for (int i = M; i <= N; i += M) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples4(int N, int M) {
	int result = 0;
	for (int i = M; i <= N; i++) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples5(int N, int M) {
	int result = 0;
	for (int i = 0; i <= N; i += M) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples6(int N, int M) {
	int result = 0;
	for (int i = 0; i <= N; i++) {
		if (i % M == 0) {
			result += pow(i, 3);
		}
	}
	return result;
}
int cubesOfMultiples7(int N, int M) {
	int result = 0;
	for (int i = M; i <= N; i += M) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples8(int N, int M) {
	int result = 0;
	for (int i = M; i <= N; i++) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples9(int N, int M) {
	int result = 0;
	for (int i = 0; i <= N; i += M) {
		result += pow(i, 3);
	}
	return result;
}
int cubesOfMultiples10(int N, int M) {
	int result = 0;
	for (int i = 0; i <= N; i++) {