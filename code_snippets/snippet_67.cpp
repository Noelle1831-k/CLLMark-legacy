	string out1, out2;
	string buffer;
	string delimeters = "\n";
	vector<string> res;
	string::iterator iter;
	string::iterator iter2;
	for (iter = text.begin(); iter != text.end(); iter++) {
		if (find(delimeters.begin(), delimeters.end(), *iter) != delimeters.end()) {
			out1 = buffer;
			out2 = buffer;
			while(find(delimeters.begin(), delimeters.end(), *iter2) != delimeters.end()) {
				out2 += *iter2;
				iter2++;
			}
			while(find(delimeters.begin(), delimeters.end(), *iter) != delimeters.end()) {
				out1 += *iter;
				iter++;
			}
			out1 += *iter;
			res.push_back(out1);
			res.push_back(out2);
			buffer = "";
		} else {
			buffer += *iter;
		}
	}
	return res;
}
int main() {
	string text;
	while (1) {
		printf("Enter your sentence: ");
		scanf("%s", text);
		vector<string> res = multipleSplit(text);
		printf("Splitted: ");
		for (unsigned int i = 0; i < res.size(); i++) {
			printf("%s ", res[i].c_str());
		}
		printf("\n");
	}
	return 0;
}
<|endoftext|>