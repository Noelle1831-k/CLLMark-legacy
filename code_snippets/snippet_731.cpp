	if (a == 0)
		return "No";
	double d = b*b - 4*a*c;
	if (d < 0)
		return "No";
	if (d == 0)
		return "Yes";
	else {
		double root1 = (-b + sqrt(d)) / (2*a);
		double root2 = (-b - sqrt(d)) / (2*a);
		if (root1 > root2) {
			return "Yes";
		}
	}
	return "No";
}
int main() {
	string solution = checkSolution(2, 0, -1);
	cout << solution << endl;
	return 0;
}
<|endoftext|>