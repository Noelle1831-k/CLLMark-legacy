	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum > n;
}
bool checkDeficient(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum < n;
}
bool checkPerfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum == n;
}
string classifyNumber(int n) {
	string response = "";
	if (checkAbundant(n)) {
		response += "abundant";
	}
	if (checkDeficient(n)) {
		response += "deficient";
	}
	if (checkPerfect(n)) {
		response += "perfect";
	}
	return response;
}
string classifyArray(vector<int> arr) {
	string response = "";
	bool even = false;
	bool odd = false;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0) {
			even = true;
		}
		else {
			odd = true;
		}
	}
	if (even && odd) {
		response += "both";
	}
	else if (even) {
		response += "even";
	}
	else if (odd) {
		response += "odd";
	}
	return response;
}
void printArray(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void printArrayByCondition(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
void printArrayByCondition1(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 != 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
void printArrayByCondition2(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0 && arr[i] % 3 != 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
void printArrayByCondition3(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 != 0 && arr[i] % 3 == 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
void printArrayByCondition4(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0 && arr[i] % 3 == 0) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
void printArrayByCondition5(vector<int> arr) {
	for