	vector<int> res;
	for(int i=0; i<testTup1.size(); i++){
		if(testTup1[i] > testTup2[i]){
			res.push_back(testTup2[i]);
		}
		else{
			res.push_back(testTup1[i]);
		}
	}
	return res;
}
int main() {
	vector<int> testTup1;
	testTup1.push_back(10);
	testTup1.push_back(4);
	testTup1.push_back(6);
	testTup1.push_back(9);
	vector<int> testTup2;
	testTup2.push_back(5);
	testTup2.push_back(2);
	testTup2.push_back(3);
	testTup2.push_back(3);
	vector<int> res = andTuples(testTup1, testTup2);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<", ";
	}
	cout<<endl;
	return 0;
}
<|endoftext|>