	string out_str = "";
	string cur_str = "";
	str += " ";
	for (int i = 0; i < str.length(); i++) {
		cur_str += str[i];
		if (i > 0 && str[i - 1] == ' ' && str[i] != ' ') {
			out_str += cur_str;
			cur_str = "";
		}
	}
	str = out_str;
	out_str = "";
	cur_str = "";
	for (int i = 0; i < str.length(); i++) {
		cur_str += str[i];
		if (i > 0 && str[i - 1] == ' ' && str[i] != ' ') {
			out_str += cur_str;
			cur_str = "";
		}
	}
	str = out_str;
	out_str = "";
	cur_str = "";
	for (int i = 0; i < str.length(); i++) {
		cur_str += str[i];
		if (i > 0 && str[i - 1] == ' ' && str[i] != ' ') {
			out_str += cur_str;
			cur_str = "";
		}
	}
	str = out_str;
	out_str = "";
	cur_str = "";
	for (int i = 0; i < str.length(); i++) {
		cur_str += str[i];
		if (i > 0 && str[i - 1] == ' ' && str[i] != ' ') {
			out_str += cur_str;
			cur_str = "";
		}
	}
	str = out_str;
	out_str = "";
	cur_str = "";
	for (int i = 0; i < str.length(); i++) {
		cur_str += str[i];
		if (i > 0 && str[i - 1] == ' ' && str[i] != ' ') {
			out_str += cur_str;
			cur_str = "";
		}
	}
	return out_str;
}
int main() {
	string str = "Python Exercises Practice Solution Exercises";
	cout << removeDuplicate(str) << endl;
	return 0;
}
<|endoftext|>