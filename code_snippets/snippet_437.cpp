	string ret = "";
	for (int i = 0; i < list.size(); i++) {
		ret += " " + list[i];
	}
	return ret;
}
int main() {
	string ret = concatenateElements({string("Part"), string("of"), string("the"), string("journey"), string("is"), string("end")});
	cout << ret << endl;
	return 0;
}
<|endoftext|>