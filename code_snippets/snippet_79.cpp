	double surface = 4 * 3.14 * r * r; 
	surface += 4 * 3.14 * r * r * 3.14; 
	return surface;
}
int cubes(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i * i * i;
	}
	return result;
}
int powerOfTwo(int n) {
	int result = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			result += 1;
		}
		n /= 2;
	}
	return result;
}
int powerOfTwoPlusOne(int n) {
	int result = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			result += 1;
		}
		n /= 2;
	}
	return 2 * result + 1;
}
int powerOfTwoPlusOneRecursive(int n) {
	if (n == 0) {
		return 1;
	}
	return 2 * powerOfTwoPlusOneRecursive(n - 1) + 1;
}
int powerOfTwoPlusOneRecursive2(int n) {
	if (n == 0) {
		return 0;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive2(n - 1) + 1;
	} else {
		return 2 * powerOfTwoPlusOneRecursive2(n - 1);
	}
}
int powerOfTwoPlusOneRecursive3(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive3(n - 1) + 1;
	} else {
		return 2 * powerOfTwoPlusOneRecursive3(n - 1);
	}
}
int powerOfTwoPlusOneRecursive4(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive4(n - 1) + 1;
	} else {
		return powerOfTwoPlusOneRecursive4(n - 1);
	}
}
int powerOfTwoPlusOneRecursive5(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive5(n - 1) + 1;
	} else {
		return 2 * powerOfTwoPlusOneRecursive5(n / 2);
	}
}
int powerOfTwoPlusOneRecursive6(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive6(n - 1) + 1;
	} else {
		return powerOfTwoPlusOneRecursive6(n / 2);
	}
}
int powerOfTwoPlusOneRecursive7(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive7(n - 1) + 1;
	} else {
		return 2 * powerOfTwoPlusOneRecursive7(n / 2);
	}
}
int powerOfTwoPlusOneRecursive8(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive8(n - 1) + 1;
	} else {
		return 2 * powerOfTwoPlusOneRecursive8(n / 2);
	}
}
int powerOfTwoPlusOneRecursive9(int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return 2 * powerOfTwoPlusOneRecursive9(n - 1) + 1;
	} else {
		return powerOfTwoPlusOneRecursive9(n / 2