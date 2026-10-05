	int sum = 0;
	for (const auto& kv : dict)
		sum += kv.second;
	return sum;
}
int main() {
	unordered_map<string, int> myMap = {
		{"a", 100},
		{"b", 200},
		{"c", 300}
	};
	cout << returnSum(myMap) << endl; 
}
<|endoftext|>