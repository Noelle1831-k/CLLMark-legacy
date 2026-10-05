	if (x == y && y == z)
		return true;
	else
		return false;
}
bool checkIsosceles(int x, int y, int z) {
	if (x == y || y == z || x == z)
		return true;
	else
		return false;
}
bool checkScalene(int x, int y, int z) {
	if (x != y && y != z && x != z)
		return true;
	else
		return false;
}
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if (checkEquilateral(x, y, z)) {
		cout << "Equilateral" << endl;
	} else if (checkIsosceles(x, y, z)) {
		cout << "Isosceles" << endl;
	} else if (checkScalene(x, y, z)) {
		cout << "Scalene" << endl;
	}
}
<|endoftext|>