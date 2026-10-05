	l.erase(unique(l.begin(), l.end()), l.end());
	return l;
}
int main() {
	vector<string> l = {
		"Python", 
		"Exercises", 
		"Practice", 
		"Solution", 
		"Exercises"
	};
	printArr(removeDuplicList(l));
}
<|endoftext|>