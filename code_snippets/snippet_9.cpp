	string rotstr = str + str;
	string::iterator itr = find(rotstr.begin(), rotstr.end(), str.begin(), str.end());
	string::iterator itr2 = find(str.begin(), str.end(), str.begin(), str.end());
	while(itr2 != str.end()){
		itr2++;
		itr2 = find(itr2, str.end(), str.begin(), str.end());
	}
	while(itr != rotstr.end()){
		itr++;
		itr = find(itr, rotstr.end(), str.begin(), str.end());
	}
	return distance(str.begin(), itr2);
}
int main () {
	string str;
	while(getline(cin, str)){
		cout<<findRotations(str)<<endl;
	}
}
<|endoftext|>