	string ret = "";
	for(int i=0; i<list1.size(); i++){
		string tmp = list1[i];
		if(tmp.size() > ret.size()){
			ret = tmp;
		}
	}
	return ret.size();
}
int num1to100Missing(int missing_num, vector<int> list1) {
	int missing_num1 = missing_num;
	for(int i=0; i<list1.size(); i++){
		missing_num1 ^= list1[i];
	}
	return missing_num1;
}
int countNumEvenOdd(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for(int i=0; i<list1.size(); i++){
		if(list1[i] % 2 == 0){
			count_even++;
		}else{
			count_odd++;
		}
	}
	return count_even + count_odd;
}
int countNumEvenOdd1to100(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for(int i=1; i<=100; i++){
		if(i % 2 == 0){
			count_even++;
		}else{
			count_odd++;
		}
	}
	return count_even + count_odd;
}
int countNumEvenOdd1to100(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for(int i=1; i<=100; i++){
		if(i % 2 == 0){
			count_even++;
		}else{
			count_odd++;
		}
	}
	return count_even + count_odd;
}
int countNumEvenOdd1to100(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for(int i=1; i<=100; i++){
		if(i % 2 == 0){
			count_even++;
		}else{
			count_odd++;
		}
	}
	return count_even + count_odd;
}
int countNumEvenOdd1to100(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for(int i=1; i<=100; i++){
		if(i % 2 == 0){
			count_even++;
		}else{
			count_odd++;
		}
	}
	return count_even + count_odd;
}
int countNumEvenOdd1to100(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for(int i=1; i<=100; i++){
		if(i % 2 == 0){
			count_even++;
		}else{
			count_odd++;
		}
	}
	return count_even + count_odd;
}
/**
 * Write a c++ function to count how many numbers are even or odd from 1~100.
 * > countNumEvenOdd1to100(vector<int>{2,3,4,5,6,7,8,9,1