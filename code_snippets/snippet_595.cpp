	string index = "";
	for (auto it = ditionary.begin(); it != ditionary.end(); ++it) {
		if (it->second == key) {
			index = it->first;
		}
	}
	return index;
}
int main() {
	cout << accessKey({{string("physics"), 80}, {string("math"), 90}, {string("chemistry"), 86}}, 80) << endl;
	cout << accessKey({{string("python"), 10}, {string("java"), 20}, {string("C++"), 30}}, 30) << endl;
	cout << accessKey({{string("program"), 15}, {string("computer"), 45}}, 45) << endl;
	return 0;
}
<|endoftext|>