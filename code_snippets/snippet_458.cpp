	string err = "Valid string.";
	string err_1 = "String must have 1 upper case character.";
	string err_2 = "String must have 1 number.";
	string err_3 = "String length should be atleast 8.";
	vector<string> res{};
	char check = 0;
	if (str1.length()<8)
		res.push_back(err_3);
	for (int i=0; i<str1.length(); i++) {
		if (isupper(str1[i])) {
			check = 1;
			break;
		}
	}
	if (check==0)
		res.push_back(err_1);
	for (int i=0; i<str1.length(); i++) {
		if (isdigit(str1[i])) {
			check = 1;
			break;
		}
	}
	if (check==0)
		res.push_back(err_2);
	if (res.size()==0)
		res.push_back(err);
	return res;
}
int main() {
	string str("123Python");
	string str1("123python");
	string str2("python");
	vector<string> res_1 = checkString(str);
	vector<string> res_2 = checkString(str1);
	vector<string> res_3 = checkString(str2);
	cout << "res_1 = ";
	for (int i=0; i<res_1.size(); i++)
		cout << res_1[i] << ", ";
	cout << "\n";
	cout << "res_2 = ";
	for (int i=0; i<res_2.size(); i++)
		cout << res_2[i] << ", ";
	cout << "\n";
	cout << "res_3 = ";
	for (int i=0; i<res_3.size(); i++)
		cout << res_3[i] << ", ";
	cout << "\n";
}
<|endoftext|>