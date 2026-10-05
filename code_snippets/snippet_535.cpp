	vector<int> res_tup;
	for(int i=0; i<testTup1.size(); i++){
		res_tup.push_back(abs(testTup1[i] - testTup2[i]) % 10);
	}
	return res_tup;
}
int main() {
	vector<int> testTup1;
	vector<int> testTup2;
	testTup1.push_back(10);
	testTup1.push_back(4);
	testTup1.push_back(5);
	testTup1.push_back(6);
	testTup2.push_back(5);
	testTup2.push_back(6);
	testTup2.push_back(7);
	testTup2.push_back(5);
	testTup1 = tupleModulo(testTup1, testTup2);
	for(int i=0; i<testTup1.size(); i++){
		cout<<testTup1[i]<<" ";
	}
	return 0;
}
<|endoftext|>