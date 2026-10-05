	stack<char> myStack;
	map<char,char> myMap = {{'{','}'},{']','['},'};','{'}};
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			myStack.push(exp[i]);
		}
		else {
			if (myStack.empty()) {
				return false;
			}
			char poppedEle = myStack.top();
			myStack.pop();
			if (myMap[poppedEle] != exp[i]) {
				return false;
			}
		}
	}
	return myStack.empty();
}
int main() {
	string exp = "{()}[{}][]({})";
	cout << checkExpression(exp) << "\n";
	return 0;
}<|endoftext|>