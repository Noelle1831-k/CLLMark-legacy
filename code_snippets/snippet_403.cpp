	string::iterator itr;
	int count = 0;
	for(itr = str.begin(); itr != str.end(); itr++) {
		if(*itr == toupper(*itr)) {
			count++;
		}
	}
	return count;
}
int main() {
	string str("PythOn");
	cout<<upperCtr(str);
	return 0;
}
<|endoftext|>