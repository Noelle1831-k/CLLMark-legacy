	int result = 0;
	while(power) {
		if(power % 2 != 0) {
			result += base;
		}
		base *= base;
		power /= 2;
	}
	return result;
}
int powerPowerSum(int base, int power) {
	return powerBaseSum(base, power) % 10;
}
int powerPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSumPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(base, power)) % 10;
}
int powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(int base, int power) {
	return powerPowerSum(base, powerPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSumPowerSum(base, power)) % 10;
}
