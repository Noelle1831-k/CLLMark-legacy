(x != y) && (x != z) && (y != z)}
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	(checkIsosceles(x, y, z)) ? cout << "Scalene" : cout << "Isosceles";
	return 0;
}
<|endoftext|>