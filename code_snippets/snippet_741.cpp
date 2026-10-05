	if (a+b > c and a+c > b and b+c > a)
		return true;
	return false;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (isTriangleexists(a, b, c))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
<|endoftext|>