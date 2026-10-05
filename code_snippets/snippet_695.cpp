	string::iterator iter = text.begin();
	while (iter != text.end()) {
		if (*iter == ' ') {
			string::iterator temp = iter;
			while(temp != text.end()){
				temp++;
				text.erase(temp);
			}
			temp--;
			text.erase(temp);
		}
		else {
			iter++;
		}
	}
	return text;
}
int main() {
	string text, temp;
	while (1) {
		temp = "";
		getline(cin, text);
		temp = removeAllSpaces(text);
		cout << temp << endl;
		if (text.length() == 0) {
			break;
		}
	}
	return 0;
}
<|endoftext|>