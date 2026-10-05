	count++;
	if (count > 3)
		return false;
	if (sum == 0)
		return true;
	for (int i = 0; i < n; i++) {
		a.erase(a.begin() + i);
		if (checkTriplet(a, n - 1, sum - a[0], count))
			return true;
		else
			a.insert(a.begin() + i, a[0]);
	}
	return false;
}
int main() {
	vector<int> a;
	int n, sum;
	a.push_back(7);
	a.push_back(4);
	a.push_back(0);
	a.push_back(9);
	a.push_back(5);
	a.push_back(1);
	a.push_back(3);
	n = a.size();
	sum = 8;
	cout << checkTriplet(a, n, sum, 0) << endl;
	a.clear();
	a.push_back(1);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(5);
	a.push_back(9);
	n = a.size();
	sum = 8;
	cout << checkTriplet(a, n, sum, 0) << endl;
	a.clear();
	a.push_back(10);
	a.push_back(4);
	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	n = a.size();
	sum = 5;
	cout << checkTriplet(a, n, sum, 0) << endl;
	return 0;
}
<|endoftext|>