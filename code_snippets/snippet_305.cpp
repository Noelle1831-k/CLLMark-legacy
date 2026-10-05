	vector<int> res;
	while(s.size()>0){
		auto it = s.begin();
		s.erase(it);
		res.push_back(*it);
	}
	return res;
}
unordered_set<int> tupleToSet(vector<int> s) {
	unordered_set<int> res;
	for(auto it: s){
		res.insert(it);
	}
	return res;
}
unordered_set<int> generateSet(int size) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(rand()%size);
	}
	return res;
}
unordered_set<int> generateSet(int size, int range) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(rand()%range);
	}
	return res;
}
unordered_set<int> generateSet(int size, int range, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(rand()%range);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input){
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, vector<int> input4) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()] + input4[rand()%input4.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, vector<int> input4, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()] + input4[rand()%input4.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, vector<int> input4, vector<int> input5) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()] + input4[rand()%input4.size()] + input5[rand()%input5.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, vector<int> input4, vector<int> input5, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()] + input4[rand()%input4.size()] + input5[rand()%input5.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, vector<int> input4, vector<int> input5, vector<int> input6) {
	srand(time(NULL));
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()] + input4[rand()%input4.size()] + input5[rand()%input5.size()] + input6[rand()%input6.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3, vector<int> input4, vector<int> input5, vector<int> input6, int seed) {
	srand(seed);
	unordered_set<int> res;
	while(res.size()<size){
		res.insert(input[rand()%input.size()] + input2[rand()%input2.size()] + input3[rand()%input3.size()] + input4[rand()%input4.size()] + input5[rand()%input5.size()] + input6[rand()%input6.size()]);
	}
	return res;
}
unordered_set<int> generateSet(int size, vector<int> input, vector<int> input2, vector<int> input3